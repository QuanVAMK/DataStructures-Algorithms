#pragma once

struct BstNode {
	int Data;
	BstNode *Left;
	BstNode *Right;
};

void Insert(BstNode *&Root, int Data);

// Return True if Sera
bool IsSearchable(const BstNode *&Root, int Data);

// Initialize & Return a new Node
BstNode *SetNewNode(int Data);
