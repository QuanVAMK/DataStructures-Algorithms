// Introduction to Tree
#include <iostream>
#include "Bst.h"


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
	// If Root is empty we didn't find 
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

int main() 
{
	BstNode *Root = nullptr;
	Insert(Root, 15);
	Insert(Root, 20);
	Insert(Root, 10);
	Insert(Root, 5);
	Insert(Root, 17);

	std::cout << IsSearchable(Root, 5) << IsSearchable(Root, 26) << std::endl;
	return 0;
}

