// Implementation of Queue using 2 Stacks
#include <iostream>

struct Node 
{
	int Data;
	Node *Next;
};

struct Queue 
{
	Node *Stack1;
	Node *Stack2;
};

void PushStack(Node *&OutTop, int Item)
{
	Node *Temp = new Node();
	Temp->Data = Item;
	Temp->Next = OutTop;
	OutTop = Temp;
}

int PopStack(Node *&OutTop)
{
	Node *Temp = OutTop;
	OutTop = Temp->Next;
	int x = Temp->Data;
	delete Temp;

	return x;
}

// Method 2: EnQueue is costly
void EnQueue2(Queue *&OutQ, int Item)
{
	// While Stack 1 is not empty, push everything to Stack 2
	while (OutQ->Stack1) {
		int x = PopStack(OutQ->Stack1);
		PushStack(OutQ->Stack2, x);
	}
	// Push Item to Stack 1
	PushStack(OutQ->Stack1, Item);

	// Push Everything from Stack 2 to Stack 1
	while (OutQ->Stack2) {
		int x = PopStack(OutQ->Stack2);
		PushStack(OutQ->Stack1, x);
	}
}

int DeQueue2(Queue *&OutQ)
{
	// If Stack 1 is empty then don't pop it
	if (!OutQ->Stack1) {
		return -1;
	}
	// Pop Item from Stack 1
	return PopStack(OutQ->Stack1);
}

// Method 1: DeQueue is costly 
// TODO: Fix DeQueue bug
void EnQueue(Queue *&OutQ, int Item)
{
	PushStack(OutQ->Stack1, Item);
}

int Dequeue(Queue *&OutQ)
{
	if (!OutQ->Stack1 && !OutQ->Stack2) {
		return -1;
	}

	// If Stack2 is empty then push Items from Stack1 to Stack2
	if (!OutQ->Stack2) {
		while (OutQ->Stack1) {
			int x = PopStack(OutQ->Stack1);
			PushStack(OutQ->Stack2, x);
		}
	}

	// Pop Item from Stack2
	return PopStack(OutQ->Stack2);
}

int main()
{
	Queue *q1 = new Queue();
	q1->Stack1 = nullptr;
	q1->Stack2 = nullptr;

	EnQueue(q1, 3);
	EnQueue(q1, 2);
	EnQueue(q1, 1);
	EnQueue(q1, 4);
	EnQueue(q1, 5);

	Dequeue(q1);
	Dequeue(q1);
	Dequeue(q1);
	Dequeue(q1);
	Dequeue(q1);

	EnQueue2(q1, 3);
	EnQueue2(q1, 2);
	EnQueue2(q1, 1);
	EnQueue2(q1, 4);
	EnQueue2(q1, 5);

	DeQueue2(q1);
	DeQueue2(q1);
	DeQueue2(q1);
	DeQueue2(q1);
	DeQueue2(q1);

	return 0;
}