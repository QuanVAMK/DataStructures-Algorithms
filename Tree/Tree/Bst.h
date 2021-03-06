#pragma once

struct BstNode {
	int Data;
	BstNode *Left;
	BstNode *Right;
};

// Custom Queue to hold pointers to BstNode
// Used in Level Order Traversal
class Queue
{
private:
	// The max amount of elements in Queue
	int Capacity;

	// Determines current size of Queue, checks if Queue is empty or not
	int Size;

	// Points to the first in line queue
	int Front;

	// Points to the last in line queue
	int Rear;

	// Array holding pointers to BstNode
	BstNode **Arr;

public:
	Queue(int NewCapacity);
	~Queue();

	bool IsEmpty();

	void EnQueue(BstNode *NewNode);
	BstNode *DeQueue();

};

void Insert(BstNode *&Root, int Data);

// Return True if the element exists in the tree
bool IsSearchable(const BstNode *&Root, int Data);

// = Root to highest lvl that has leaf node
int FindTreeHeight(const BstNode *&Root);

// Print all nodes of given lvl & advance
void LevelOrderTraversal(BstNode *&Root);

// Left Root Right
void InOrderTraversal(BstNode *&Root);

// Root Left Right
void PreOrderTraversal(BstNode *&Root);

// Right Root Left
void PostOrderTraversal(BstNode *&Root);

// Initialize & Return a new Node
BstNode *SetNewNode(int Data);
