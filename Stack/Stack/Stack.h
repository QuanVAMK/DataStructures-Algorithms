#pragma once

struct Node
{
	int Data;
	Node *Next;
};

class Stack 
{
	Node *Root;

public:
	Stack();
	~Stack();
	Node *GetFront();

	void Push(int Data);
	int Pop();
	int Peek();
	bool IsEmpty();
};
