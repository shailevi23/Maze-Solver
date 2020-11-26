#include "Node.h"

Node::Node() // c'tor
{
	this->row = -1;
	this->col = -1;
	this->next = NULL;
}
Node::Node(int rows, int cols)
{
	this->row = rows;
	this->col = cols;
	this->next = NULL;
}

Node::Node(Node node, Node* next)
{
	this->row = node.row;
	this->col = node.col; 
	this->next = next;
}

Node* Node::getNextNode() const
{
	return this->next;
}
int Node::getRow() const
{
	return this->row;
}
int Node::getCol() const
{
	return this->col;
}

