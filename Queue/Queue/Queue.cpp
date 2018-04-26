// Implementation of Queue using 2 stacks
#include "Queue.h"

Stack::Stack(int Top1, int *Arr1)
{
	this->Top = Top1;
	this->Arr = Arr1;
}

void Stack::Push(int Size)
{
	this->Top = (this->Top + 1) % Size;
}

int Stack::Pop(int Size)
{
	int Item = this->Arr[this->Top];
	this->Top = (this->Top + 1) % Size;
	return Item;
}

Queue::Queue(int Capacity)
{
	this->Capacity = Capacity;
	this->Arr = new int[this->Capacity];
	this->Front = this->Size = 0;
	this->Rear = this->Capacity - 1;
	this->FrontHandle = Stack(Front, Arr);
	this->RearHandle = Stack(Rear, Arr);
}

Queue::~Queue()
{
	delete[] this->Arr;
}

void Queue::Push(int Item)
{
	if (IsFull()) {
		return;
	}

	this->Size = this->Size + 1;
	this->RearHandle.Push(this->Size);
	this->Rear = this->RearHandle.GetTop();
	this->Arr[this->Rear] = Item;
}

int Queue::Pop()
{
	if (IsEmpty()) {
		return -1;
	}

	int Item = this->FrontHandle.Pop(this->Size);
	this->Front = this->FrontHandle.GetTop();
	this->Size = this->Size - 1;
	return Item;
}
