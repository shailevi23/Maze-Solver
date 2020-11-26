#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

#include "Maze.h"
#include "Queue.h"
#include "Stack.h"

//declartions
void cleanBuffer();
void checkMazeInput(char** maze, int rows, int cols);
void invalidInput();
char** createMazeArrFor1(int rows, int cols);
char** createMazeArrFor2(int rows, int cols);
void checkDimentions(int rows, int  cols);

int main()
{
	srand((unsigned)time(NULL));
	bool flag = false;
	int userInput, rows, cols;
	cout << "Maze: 1) From input 2) Random\n";

	cin >> userInput;
	cin >> rows;
	cin >> cols;
	checkDimentions(rows,cols);


	if (userInput == 1) //from input
	{
		Maze myMaze(createMazeArrFor1(rows,cols), rows, cols);
		flag = myMaze.SolveMazeFor1();
		if(flag)
			myMaze.show();
	}
	else if(userInput == 2) // random
	{
		Maze myMaze(createMazeArrFor2(rows, cols), rows, cols);
		myMaze.CreateRandomMaze();
		myMaze.SolveMazeFor1();
		myMaze.show();
	}
	else // user input is not 1 or 2 
	invalidInput();

	system("pause");
}

char** createMazeArrFor1(int rows, int cols)
{
	int i;
	char** maze;
	maze = new char*[rows];
	cleanBuffer();
	for (i = 0; i < rows; i++)
	{
		maze[i] = new char[cols + 1];
		cin.getline(maze[i], cols + 1);
	}
	checkMazeInput(maze, rows, cols);
	return maze;
}

void checkDimentions(int rows, int  cols)
{
	if (rows > 25 || cols > 80) // max dimentions
		invalidInput();
}

char** createMazeArrFor2(int rows, int cols)
{
	int i, j;
	char** maze;
	maze = new char*[rows];

	for (i = 0; i < rows; i++)
	{
		maze[i] = new char[cols + 1];
		if (i % 2 == 0) // even
		{
			for (j = 0; j < cols; j++)
				maze[i][j] = ASTERISK;
		}
		else // odd
		{
			for (j = 0; j < cols; j++)
			{
				if (j % 2 == 0) // even col
					maze[i][j] = ASTERISK;
				else // odd col
					maze[i][j] = DOLLAR;
			}
		}
	}
	maze[1][0] = SPACE; // Maze enter
	maze[rows - 2][cols - 1] = SPACE; // Maze exit
	return maze;
}

void checkMazeInput(char** maze, int rows, int cols)
{
	int i, j;

	if (maze[1][0] != SPACE) // Maze enter
	   invalidInput();
	if (maze[rows - 2][cols - 1] != SPACE) // Maze exit
	   invalidInput();

	for (i = 0; i < rows; i++) // if any spot in the maze is not SPACE or ASTERISK
	{
		for (j = 0; j < cols; j++)
		{
			if ((maze[i][j] != SPACE) && (maze[i][j] != ASTERISK))
			  invalidInput();
		}
	}

	for (i = 0; i < cols; i++) // upper border
	{
		if (maze[0][i] != ASTERISK)
		   invalidInput();
	}

	for (i = 0; i < cols; i++) // lower border
	{
		if (maze[rows - 1][i] != ASTERISK)
		   invalidInput();
	}

	for (i = 2; i < rows - 1; i++) // left border
	{
		if (maze[i][0] != ASTERISK)
		   invalidInput();
	}

	for (i = 1; i < rows - 2; i++) // right border
	{
		if (maze[i][cols - 1] != ASTERISK)
		invalidInput();
	}

}

void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

void invalidInput() // func prints message to user and exit the program.
{
	cout << "invalid input";
	exit(1);
}