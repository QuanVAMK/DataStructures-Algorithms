#include "LinkedList.h"

LinkedList::LinkedList()
{
	Head = nullptr;
}

LinkedList::~LinkedList()
{
	Node* Current = Head;
	while (Current != nullptr)
	{
		Node* Next = Current->Next;
		delete Current;
		Current = Next;
	}
}

bool LinkedList::IsEmpty() { return Head ? true : false; }

int LinkedList::CheckSize()
{
	if (IsEmpty()) { return 0; }
	int Sum = 0;
	Node* i = Head;
	while (i != nullptr)
	{
		Sum++;
		i = i->Next;
	}
	return Sum;
}

Node* LinkedList::GetFront()
{
	return Head;
}

void LinkedList::SetFront(Node* NodeToSet)
{
	Head = NodeToSet;
}

void LinkedList::PushFront(int Value)
{
	Node* Temp = new Node();
	Temp->Value = Value;
	Temp->Next = Head;
	Head = Temp;
}

void LinkedList::InsertAfter(int Value, int Pos) 
{
	if (IsEmpty())
	{
		return;
	}
	if (Pos == 1)
	{
		PushFront(Value);
		return;
	}

	Node* NodeBeforePos = Head;
	// No of each traversal + PosBefore + 0-indexed = < + (N - 1) + (-1) 
	for (int i = 0; i < Pos - 2; i++)
	{
		NodeBeforePos = NodeBeforePos->Next;
	}

	Node* NodeToInsert = new Node();
	NodeToInsert->Value = Value;
	NodeToInsert->Next = NodeBeforePos->Next;
	NodeBeforePos->Next = NodeToInsert;

}

void LinkedList::PopFront()
{
	if (IsEmpty())
		return;

	Node* Current = Head;
	Head = Current->Next;
	delete Current;
}

void LinkedList::EraseAfter(int Pos)
{
	if (IsEmpty())
		return;
	if (Pos == 1)
	{
		PopFront();
		return;
	}

	Node* NodeBeforePos = Head;
	for (int i = 0; i < Pos - 2; i++)
		NodeBeforePos = NodeBeforePos->Next;

	Node* NodeToDelete = NodeBeforePos->Next;
	NodeBeforePos->Next = NodeToDelete->Next;
	delete NodeToDelete;
}


