#ifndef __MAZE_H
#define __MAZE_H

#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
#pragma warning(disable: 4996)

#include "Queue.h"
#include "Stack.h"

const char SPACE = ' ';
const char ASTERISK = '*';
const char DOLLAR = '$';

class Maze
{
private:
	int rows, cols;
	char** maze;

public:
	Maze(char** maze, int rows, int cols);
	~Maze();
	void show();
	void addNeighborsToQueue(Queue& q, int currRow, int currCol);
	Point addNeighborsToStackRandom(Stack& s,int currRow, int currCol);
	bool SolveMazeFor1();
	void CreateRandomMaze();
	Point* arrResize(Point* arr, int& size);
	void deleteWall(int currRow, int currCol, int neighborRow, int neighborCol);

};
#endif


