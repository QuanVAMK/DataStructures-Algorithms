#include <iostream>
#include "Queue2Stack.h"



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
	/* Example of KStacks
	int k = 3, n = 10;
	KStacks ks(n, k);

	ks.Push(0, 0);
	ks.Push(1, 0);
	ks.Push(2, 0);
	ks.Push(3, 0);
	ks.Push(4, 0);

	std::cout << "Popped item: " << ks.Pop(0);
	/**/

	Stack *S1 = new Stack();
	S1->Q1 = nullptr;
	S1->Q2 = nullptr;

	std::cout << PopStack(S1) << std::endl;

	PushStack(S1, 1);
	std::cout << PopStack(S1) << std::endl;

	PushStack(S1, 2);
	PushStack(S1, 3);
	PushStack(S1, 4);

	std::cout << PopStack(S1) << "\t" << PopStack(S1) << "\t" << PopStack(S1) << std::endl;
	std::cout << PopStack(S1);

	return 0;
}