#include "Stack.h"

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{
	MakeEmpty();
}

void Stack::MakeEmpty()
{
	Node* temp;
	while (top != NULL)
	{
		temp = top;
		top = top->getNextNode();
		delete temp;
	}
}

bool Stack::IsEmpty()
{
	if (top == NULL)
		return true;
	return false;
}

void Stack::Push(Node node, Node* next)
{
	top = new Node(node, this->top);
}

Node Stack::Pop()
{
	if (IsEmpty())
		exit(1);
	Node* temp = top;
	Node item = *top;
	top = top->getNextNode();
	delete temp;
	return item;
}

Node Stack::Top()
{
	Node x;
	x = Pop();
	Push(x);
	return x;
}