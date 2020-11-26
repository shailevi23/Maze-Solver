#include "Queue.h"
#include "Maze.h"

// Constructor
Queue::Queue(int size)
{
	this->arr = new Point[size];
	this->capacity = size;
	this->firstElement = 0;
	this->lastElement = -1;
	this->sizeOfQueue = 0;
}

// Destructor
Queue::~Queue()
{
	delete[] this->arr;
}

// Dequeue remove first element
Point Queue::dequeue()
{
	int res = firstElement;

	if (isEmpty())
	{
		cout << "error";
		exit(1);
	}

	this->firstElement = (this->firstElement + 1) % this->capacity;
	this->sizeOfQueue--;
	return this->arr[res];
}

// Enqueue to add item to the arr
void Queue::enqueue(const Point& node)
{
	if (isFull())
	{
		cout << "error";
		exit(1);
	}

	this->lastElement = (this->lastElement + 1) % this->capacity;
	this->arr[this->lastElement] = node;
	this->sizeOfQueue++;
}

// return first element
Point Queue::getFirstElement()
{
	if (isEmpty())
	{
		cout << "error";
		exit(1);
	}
	return this->arr[this->firstElement];
}

// return size of qeueue
int Queue::getSize()
{
	return this->sizeOfQueue;
}

// check if the queue is empty
bool Queue::isEmpty()
{
	return (getSize() == 0);
}

// check if the queue is full
bool Queue::isFull()
{
	return (getSize() == this->capacity);
}