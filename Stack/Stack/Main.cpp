#include <iostream>
#include "Stack.h"
#include "KStacks.h"

void PrintStack(Node *const &Root)
{
	for (Node *i = Root; i != nullptr; i = i->Next)
		std::cout << i->Data << " ";
}

int main()
{
	/* Example of Stacks
	Stack StackEx;
	StackEx.Push(5);
	StackEx.Push(6);
	StackEx.Push(1);
	StackEx.Push(9);
	StackEx.Push(4);
	std::cout << StackEx.Pop() << " ";
	std::cout << StackEx.Peek();
	Node *Root = StackEx.GetFront();
	PrintStack(Root);
	/**/

	int k = 3, n = 10;
	KStacks ks(n, k);

	ks.Push(0, 0);
	ks.Push(1, 0);
	ks.Push(2, 0);
	ks.Push(3, 0);
	ks.Push(4, 0);

	std::cout << "Popped item: " << ks.Pop(0);
	return 0;
}