struct Node 
{
	int Value;
	Node* Next;
};


class LinkedList {
	Node* Head;
public:
	LinkedList();
	~LinkedList();
	bool IsEmpty();
	int CheckSize();
	Node* GetFront();
	void SetFront(Node* NodeToSet);
	void PushFront(int Value);
	void InsertAfter(int Value, int Pos);
	void PopFront();
	void EraseAfter(int Pos);
};
