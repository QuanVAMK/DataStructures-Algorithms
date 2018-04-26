#include <iostream>
#include "Queue.h"

int main()
{
	Queue q1 = Queue(10);

	q1.Push(10);
	q1.Push(20);
	q1.Push(30);

	std::cout << q1.Pop();
	return 0;
}