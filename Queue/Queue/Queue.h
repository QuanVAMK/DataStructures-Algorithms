#pragma once

class Stack 
{
	int Top;
	int *Arr;

public:
	// Don't need destructor because Queue is gonna handle freeing Arr.
	Stack() {};
	Stack(int Top1, int *Arr1);

	// Update Rear.
	// Don't need to check IsFull because Queue is gonna handle that.
	void Push(int Size);

	// Update Front & return item to be popped.
	// Don't need to check IsEmpty because Queue is gonna handle that.
	int Pop(int Size);

	int GetTop() { return Top; }
};

class Queue
{
	int Front, Rear, Size, Capacity;
	int *Arr;
	Stack FrontHandle;
	Stack RearHandle;
	
public:
	Queue(int Capacity);
	~Queue();
	bool IsFull() { return Size == Capacity; }
	bool IsEmpty() { return Size == 0; }

	// Push the item and update Rear.
	void Push(int Item);

	// Pop the item and update Front & Size.
	int Pop();
};
