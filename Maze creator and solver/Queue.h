#ifndef __QUEUE_H
#define __QUEUE_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

#include "Point.h"


class Queue
{
private:
	Point *arr;		// array to store queue elements
	int capacity;	// max capacity of the queue 
	int firstElement;		// first element in queue
	int lastElement;		// last element in queue
	int sizeOfQueue;		// current size of the queue

public:
	Queue(int size); // c'tor
	~Queue();  // d'tor

	Point dequeue();
	void enqueue(const Point& node);
	Point getFirstElement();
	int getSize();
	bool isEmpty();
	bool isFull();
};
#endif