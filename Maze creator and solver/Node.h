#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

#include "Point.h"

class Node
{
private:
	int row, col;
	Node* next;

public:
	Node();
	Node(int rows, int cols);
	Node(Node node, Node* next);
	~Node() = default;
	
	Node* getNextNode() const;
	int getRow() const;
	int getCol() const;

};
#endif