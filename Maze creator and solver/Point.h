#ifndef __POINT_H
#define __POINT_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class Point
{
private:
	int row;
	int col;

public:
	Point();
	Point(int row, int col);
	Point(const Point& other);
	~Point(); 
	int getRow() const;
	int getCol() const;
	void setRow(int row);
	void setCol(int col);
};
#endif
