#include "Stack.h"


Stack::Stack()
{
	Root = nullptr;
}

Stack::~Stack()
{
	Node *Current = Root;
	while (Current != nullptr)
	{
		Node *Next = Current->Next;
		delete Current;
		Current = Next;
	}
}

Node *Stack::GetFront()
{
	if (IsEmpty()) { return nullptr; }
	return Root;
}

void Stack::Push(int Data)
{
	Node *Temp = new Node();
	Temp->Data = Data;
	Temp->Next = Root;
	Root = Temp;
}

int Stack::Pop()
{
	if (IsEmpty()) { return -1; }

	Node *Temp = Root;
	Root = Root->Next;
	int Popped = Temp->Data;
	
	delete Temp;
	return Popped;
}

int Stack::Peek()
{
	if (IsEmpty()) { return -1; }
	return Root->Data;
}

bool Stack::IsEmpty() { return Root == nullptr ? true : false; }
