#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

#include "Node.h"

class Stack
{
private:
	Node* top;

public:
	Stack();
	~Stack();
	void MakeEmpty();
	bool IsEmpty();
	void Push(Node node, Node* next = NULL);
	Node Pop();
	Node Top();
};

#endif