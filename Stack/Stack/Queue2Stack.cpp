// Implement a Stack using 2 Queues
#include "Queue2Stack.h"

void EnQueue(Queue *&Q, int Item)
{
	if (!Q) {
		Q = new Queue();
	}

	Node *Temp = new Node();
	Temp->Data = Item;
	Temp->Next = nullptr;
	// Front is only empty when Queue is empty
	if (!Q->Front) {
		Q->Front = Temp;
		Q->Rear = Temp;
		return;
	}
	
	Q->Rear->Next = Temp;
	Q->Rear = Temp;
}

int Dequeue(Queue *&Q)
{
	Node *Temp = Q->Front;
	Q->Front = Temp->Next;
	int x = Temp->Data;
	delete Temp;

	return x;
}

void PushStack(Stack *&S, int Item)
{
	// push from Q1 to Q2
	while (S->Q1 && S->Q1->Front) {
		int x = Dequeue(S->Q1);
		EnQueue(S->Q2, x);
		}

	// Push Item to Q1
	EnQueue(S->Q1, Item);

	// Push Q2 back to Q1
	while (S->Q2 && S->Q2->Front) {
		int x = Dequeue(S->Q2);
		EnQueue(S->Q1, x);
	}
}

int PopStack(Stack *&S)
{
	if (!S->Q1 || !S->Q1->Front) {
		return -1;
	}

	int x = Dequeue(S->Q1);
	return x;
}
