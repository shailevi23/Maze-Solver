#include "Maze.h"
#include "Point.h"
#include "Queue.h"
#include "Stack.h"

Maze::Maze(char** maze, int rows, int cols)
{
	this->cols = cols;
	this->rows = rows;
	this->maze = maze;
}

Maze::~Maze()
{
	int i;
	 
	for (i = 0; i < this->rows; i++)
		delete[] maze[i];

	delete[] maze;
}

void Maze::show()
{
	int i, j;

	for (i = 0; i < this->rows; i++)
	{
		for (j = 0; j < this->cols; j++)
			cout << this->maze[i][j];
		cout << "\n";
	}
}

bool Maze::SolveMazeFor1()
{
	int size, currRow, currCol;
	bool flag = true;
	size = this->rows * this->cols;
	Queue q(size);
	Point currPoint;

	q.enqueue(Point(1, 0)); // initizle queue with point (1,0).
	while ((!q.isEmpty() && flag)) // queue is not empty 
	{
		currPoint = q.dequeue();  // take out from head
		currRow = currPoint.getRow();
		currCol = currPoint.getCol();
		maze[currRow][currCol] = DOLLAR;  // been there sign

		if (currRow == rows - 2 && currCol == cols - 1) // end of maze
			flag = false;
		else
			addNeighborsToQueue(q, currRow, currCol);
	}
	if (maze[rows - 2][cols - 1] == SPACE)
	{
		cout << "no solution\n";
		return false;
	}
	return true;
}

void Maze::CreateRandomMaze()
{
	int counter = 0;
	Stack s;
	Node currNode;
	int currRow, currCol, randomNeighborRow, randomNeighborCol;
	Point randomNeighbor;
	s.Push(Node(1, 1), NULL); // initizle stack with Node (1,1)
	while (!s.IsEmpty())
	{
		counter++;
		currNode = s.Pop();
		currRow = currNode.getRow();
		currCol = currNode.getCol();
		this->maze[currRow][currCol] = SPACE; // been there sign
		randomNeighbor = addNeighborsToStackRandom(s, currRow, currCol);
			if (randomNeighbor.getRow() != 0 || randomNeighbor.getCol() != 0) // at least one neighbor
			{
				randomNeighborRow = randomNeighbor.getRow();
				randomNeighborCol = randomNeighbor.getCol();
				deleteWall(currRow, currCol, randomNeighborRow, randomNeighborCol);
				s.Push(currNode);
				s.Push(Node(randomNeighborRow, randomNeighborCol));
			}
	}
 	
}

void Maze::addNeighborsToQueue(Queue& q, int currRow, int currCol)
{
	if (this->maze[currRow][currCol + 1] == SPACE)  // right
		q.enqueue(Point(currRow, currCol + 1));

	if (this->maze[currRow + 1][currCol] == SPACE)  // down
		q.enqueue(Point(currRow + 1, currCol));

	if (this->maze[currRow][currCol - 1] == SPACE) // left
		q.enqueue(Point(currRow, currCol - 1));

	if (this->maze[currRow - 1][currCol] == SPACE) // up
		q.enqueue(Point(currRow - 1, currCol));
}

void Maze::deleteWall(int currRow, int currCol, int neighborRow, int neighborCol)
{
	if (currRow == neighborRow && (currCol + 2) == neighborCol) // right
		this->maze[currRow][currCol + 1] = SPACE;

	if ((currRow + 2) == neighborRow && currCol == neighborCol) // down
		this->maze[currRow + 1][currCol] = SPACE;

	if (currRow == neighborRow && (currCol - 2) == neighborCol) // left
		this->maze[currRow][currCol - 1] = SPACE;

	if ((currRow - 2) == neighborRow && currCol == neighborCol) // up
		this->maze[currRow - 1][currCol] = SPACE;
}

Point Maze::addNeighborsToStackRandom(Stack& s, int currRow, int currCol)
{
	Point* arr = new Point[1];
	int logSize = 0, phySize = 1, i;
	Point temp;

	if (currCol + 2 < this->cols)  // right
	{
		if (this->maze[currRow][currCol + 1] == ASTERISK && this->maze[currRow][currCol + 2] == DOLLAR)  // right
		{
			if (logSize == phySize) // need space?
			{
				arr = arrResize(arr, phySize);
			}
			arr[logSize++] = Point(currRow, currCol + 2); // add to arr and increase logsize
		}
	}

	if (currRow + 2 < this->rows) // down
	{
		if (this->maze[currRow + 1][currCol] == ASTERISK && this->maze[currRow + 2][currCol] == DOLLAR)  // down
		{
			if (logSize == phySize) // need space?
			{
				arr = arrResize(arr, phySize);
			}
			arr[logSize++] = Point(currRow + 2, currCol); // add to arr and increase logsize
		}
	}

	if (currCol - 2 > 0)// left
	{
		if (this->maze[currRow][currCol - 1] == ASTERISK && this->maze[currRow][currCol - 2] == DOLLAR) // left
		{
			if (logSize == phySize) // need space?
			{
				arr = arrResize(arr, phySize);
			}
			arr[logSize++] = Point(currRow, currCol - 2); // add to arr and increase logsize
		}
	}

	if (currRow - 2 > 0) // up
	{
		if (this->maze[currRow - 1][currCol] == ASTERISK && this->maze[currRow - 2][currCol] == DOLLAR) // up
		{
			if (logSize == phySize) // need space?
			{
				arr = arrResize(arr, phySize);
			}
			arr[logSize++] = Point(currRow - 2, currCol); // add to arr and increase logsize
		}
	}

	if (logSize > 0) // at least one neighbor
	{
		i = rand() % logSize;

		temp = arr[i];

		delete[] arr;
		return temp;
	}
	else
	{
		delete[] arr;
		return Point(0,0);
	}
}


Point* Maze::arrResize(Point* arr, int& size)
{
	int newsize = size * 2;
	int i;
	Point* resArr = new Point[newsize];
	for (i = 0; i < size; i++) // copy all data to temp arr
	{
		resArr[i] = arr[i];
	}
	delete[] arr;
	size = newsize; // update size
	return resArr;
}