#pragma once

struct Node 
{
	int Data;
	Node *Next;
};

struct Queue
{
	Node *Front;
	Node *Rear;
};

struct Stack
{
	Queue *Q1;
	Queue *Q2;
};

void EnQueue(Queue *&Q, int Item);
int Dequeue(Queue *&Q);

void PushStack(Stack *&S, int Item);
int PopStack(Stack *&S);
