#pragma once

#include <iostream>
#include "LinkedList.h"

// Utility function to find Node with Value & keeptrack of NodePrev
void SearchNode(Node *&OutNodePrev, Node *&OutNodeCurrent, int Value)
{
	while (OutNodeCurrent && OutNodeCurrent->Value != Value)
	{
		OutNodePrev = OutNodeCurrent;
		OutNodeCurrent = OutNodeCurrent->Next;
	}
}

// TODO: Fix BUG
// Swap 2 nodes without swapping the data
void SwapNodes(LinkedList &OutList, int x, int y)
{
	if (OutList.IsEmpty() || x == y)
		return;

	Node *XPrev = nullptr, *XCurrent = OutList.GetFront();
	SearchNode(XPrev, XCurrent, x);

	Node *YPrev = nullptr, *YCurrent = OutList.GetFront();
	SearchNode(YPrev, YCurrent, y);

	if (XCurrent == nullptr || YCurrent == nullptr)
		return;

	// If X is not head of the linked list
	if (XPrev != nullptr)
		XPrev->Next = YCurrent;
	else // Else make Y as the new head
		OutList.SetFront(YCurrent);

	// If Y is not head of the linked list
	if (YPrev != nullptr)
		YPrev->Next = XCurrent;
	else // Else make X as the new head
		OutList.SetFront(XCurrent);

	// Swap the next node X & Y point to
	Node* Temp = YCurrent->Next;
	YCurrent->Next = XCurrent->Next;
	XCurrent->Next = Temp;
}

// TODO(Quan): Fix Bug & understand reference vs pointer
void ReverseLinkedListWithRecursion(Node*& Head, Node* Current, Node* Prev)
{
	if (Head == nullptr) { return; }

	/** If last node mark it as head */
	if (!Current->Next)
	{
		Current->Next = Prev;
		Head = Current;
		return;
	}

	Node* Next = Current->Next;

	Current->Next = Prev;

	ReverseLinkedListWithRecursion(Head, Next, Current);
}

bool CmpLists(Node *const &FirstHalf,Node *const &SecondHalf)
{
	Node *Temp1 = FirstHalf, *Temp2 = SecondHalf;
	while (Temp1 && Temp2)
	{
		if (Temp1->Value == Temp2->Value)
		{
			Temp1 = Temp1->Next;
			Temp2 = Temp2->Next;
		}
		else { return false; }
	}

	/** If both are nullptr then the list is palindrome */
	if (Temp1 == nullptr && Temp2 == nullptr) { return true; }

	/** If 1 is null & the other isn't */
	return false;
}

bool IsPalindrome(Node *const &Head)
{
	Node *Middle = nullptr, *SecondHalf = Head, *Temp = Head;
	Node *PrevOfSecondHalf = Head;
	bool bIsPalindrome = true;
	int Counter = 0;

	/** If there are more than 2 elements */
	if (Head && Head->Next)
	{
		/** Find the middle element */
		while (Temp)
		{

			if (Counter & 1)
			{
				/** Preserve the Prev of SecondHalf = end of 1st half to reconstruct the list later */
				PrevOfSecondHalf = SecondHalf;

				/** SecondHalf will be the starting pos of the 2nd half of the linked list */
				SecondHalf = SecondHalf->Next;
			}
			Counter++;
			Temp = Temp->Next;
		}

		/** Even case = last value is odd. If odd case, need to preserve MidNode to reconstruct the list later */
		if (Counter & 1)
		{
			Middle = SecondHalf;
			SecondHalf = SecondHalf->Next;
		}

		/** Terminate the 1st half */
		PrevOfSecondHalf->Next = nullptr;
		
		/** Reverse the 2nd half & compare both halfs */
		ReverseLinkedListWithRecursion(SecondHalf, SecondHalf, nullptr);
		bIsPalindrome = CmpLists(Head, SecondHalf);

		/** Construct Linked List back to normal */
		ReverseLinkedListWithRecursion(SecondHalf, SecondHalf, nullptr);

		/** If odd */
		if (Middle != nullptr)
		{
			Middle->Next = SecondHalf;
			PrevOfSecondHalf->Next = Middle;
		}
		else { PrevOfSecondHalf->Next = SecondHalf; }
	}

	return bIsPalindrome;
}

void ReverseLinkedList(Node*& Head)
{
	if (Head == nullptr)
		return;

	Node *Prev = nullptr; 
	Node *Current = Head; 
	Node *NNext = Head->Next; // To differentiate Next of a Node and the NextNode
	while (NNext != nullptr)
	{
		// Reverse one node
		Current->Next = Prev;
		Prev = Current;
		Current = NNext;
		NNext = NNext->Next;
	}
	Current->Next = Prev;
	Head = Current;
}

void PrintList(Node *const &Head)
{
	if (Head == nullptr) { return; }

	for (Node *i = Head; i != nullptr; i = i->Next)
		std::cout << i->Value << " ";
}

int main()
{
	LinkedList ListEx;
	ListEx.PushFront(3);
	ListEx.PushFront(5);
	ListEx.PushFront(5);
	ListEx.PushFront(3);
	ListEx.InsertAfter(4, 3);
	ListEx.InsertAfter(4, 2);
	Node* Head = ListEx.GetFront();

	PrintList(Head);
	std::cout << IsPalindrome(Head);

	ReverseLinkedList(Head);
	ListEx.SetFront(Head);
	return 0;
}
