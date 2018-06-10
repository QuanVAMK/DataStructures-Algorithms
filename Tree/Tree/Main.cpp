// Introduction to Tree
#include <iostream>
#include "Bst.h"


// Helper function to find max number between 2 numbers
int FindMaxOfTwoNums(int N1, int N2)
{
	if (N1 >= N2) {
		return N1;
	} else {
		return N2;
	}
}

// Helper function to set a new Node
BstNode *SetNewNode(int Data)
{
	BstNode *NewNode = new BstNode();
	NewNode->Data = Data;
	NewNode->Left = NewNode->Right = nullptr;
	return NewNode;
}

void Insert(BstNode *&Root, int Data)
{
	if (!Root) {
		Root = SetNewNode(Data);
	} else {
		if (Root->Data < Data) { 
			Insert(Root->Right, Data);
		} else {
			Insert(Root->Left, Data);
		}
	}
}

bool IsSearchable(BstNode *&Root, int Data)
{
	// No element found if Tree is empty
	if (!Root) {
		return false;
	} else {
		if (Root->Data < Data) {
			return IsSearchable(Root->Right, Data);
		} else if (Root->Data > Data) {
			return IsSearchable(Root->Left, Data);
		} else {
			return true;
		}
	}
}

int FindTreeHeight(BstNode *&Root)
{
	// Empty subtree
	if (!Root) {
		return -1;
	}

	int LeftTreeHeight = FindTreeHeight(Root->Left);
	int RightTreeHeight = FindTreeHeight(Root->Right);
	return FindMaxOfTwoNums(LeftTreeHeight, RightTreeHeight) + 1;
}

void LevelOrderTraversal(BstNode *&Root)
{
	Queue q1(15);

	BstNode *TempNode = Root;

	while (TempNode != nullptr) {
		std::cout << TempNode->Data << " ";
		q1.EnQueue(TempNode->Left);
		q1.EnQueue(TempNode->Right);
		TempNode = q1.DeQueue();
	}
	
}

void PreOrderTraversal(BstNode *&Root)
{
	if (!Root) { return; }

	PreOrderTraversal(Root->Left);
	std::cout << Root->Data << " ";
	PreOrderTraversal(Root->Right);
}

void InOrderTraversal(BstNode *&Root)
{
	if (!Root) { return; }

	std::cout << Root->Data << " ";
	InOrderTraversal(Root->Left);
	InOrderTraversal(Root->Right);
}

void PostOrderTraversal(BstNode *&Root)
{
	if (!Root) { return; }

	PostOrderTraversal(Root->Right);
	std::cout << Root->Data << " ";
	PostOrderTraversal(Root->Left);
}

Queue::Queue(int NewCapacity)
{
	Capacity = NewCapacity;

	// Initialization of Array of Pointers to BstNode
	Arr = new BstNode *[Capacity];
	Size = 0;
	Front = Rear = -1;
}

Queue::~Queue()
{
	delete []Arr;
}

bool Queue::IsEmpty()
{
	if (Size == 0) {
		return true;
	} else {
		return false;
	}
}

void Queue::EnQueue(BstNode *NewNode)
{
	if (!NewNode) { return; }

	if (Size == 0) {
		++Size;
		++Front;
		++Rear;
		Arr[Rear] = NewNode;
	} else {
		++Size;
		Rear = (Rear + 1) % Capacity;
		Arr[Rear] = NewNode;
	}
}

BstNode *Queue::DeQueue()
{
	if (IsEmpty()) { return nullptr; }

	BstNode *Ret = Arr[Front];
	Front = (Front + 1) % Capacity;
	--Size;

	return Ret;
}

int main() 
{
	BstNode *Root = nullptr;
	Insert(Root, 15);
	Insert(Root, 20);
	Insert(Root, 10);
	Insert(Root, 5);
	Insert(Root, 17);
	/*
	Root = SetNewNode(1);
	Root->Left = SetNewNode(2);
	Root->Right = SetNewNode(3);
	Root->Left->Left = SetNewNode(4);
	Root->Left->Right = SetNewNode(5);
	*/
	std::cout << IsSearchable(Root, 5) << IsSearchable(Root, 26) << FindTreeHeight(Root) << std::endl;
	LevelOrderTraversal(Root);

	PreOrderTraversal(Root);
	InOrderTraversal(Root);
	PostOrderTraversal(Root);

	return 0;
}

