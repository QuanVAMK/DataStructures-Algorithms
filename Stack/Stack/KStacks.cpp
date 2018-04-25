#include "KStacks.h"
#include <iostream>

KStacks::KStacks(int n1, int k1)
{
	n = n1;
	k = k1;
	Arr = new int[n];
	Top = new int[k];
	Next = new int[n];

	// Initialize all stacks as empty
	for (int i = 0; i < k; i++) {
		Top[i] = -1;
	}

	// Initialize all spaces as free
	free = 0;
	for (int i = 0; i < n - 1; i++) {
		Next[i] = i + 1;
	}
	Next[n - 1] = -1; // end of free list
}

KStacks::~KStacks()
{
	delete[] Arr;
	delete[] Top;
	delete[] Next;
}

void KStacks::Push(int item, int sn)
{
	if (IsFull()) { return; }

	// Keep track of current free element
	int i = free;

	// Update the next free element
	free = Next[i];

	// Update the Next entry of current element
	Next[i] = Top[sn];

	// Update the Top element of stack number "sn"
	Top[sn] = i;

	Arr[i] = item;
}

int KStacks::Pop(int sn)
{
	if (IsEmpty(sn)) { return -1; }

	// Find index of Top element in stack number "sn"
	int i = Top[sn];

	// Point Top element to Next (previous Top)
	Top[sn] = Next[i];

	// Attach Next to the beginning of free list
	Next[i] = free;
	free = i;

	return Arr[i];
}

