#pragma once

class KStacks
{
	int *Arr;	// Size n, store actual content in all stacks
	int *Top;	// Size k, store top element in all stacks
	int *Next;	// Size n, store next entry in all stacks

	int n, k;
	int free;	// Store beginning index of free list	

public:
	KStacks(int n1, int k1);

	~KStacks();

	bool IsFull() { return (free == -1); }

	bool IsEmpty(int sn) { return (Top[sn] == -1); }

	void Push(int item, int sn);

	int Pop(int sn);
};
