#include "Point.h"

Point::Point()
{
	this->col = 0;
	this->row = 0;
}

Point::Point(int row, int col)
{
	setRow(row);
	setCol(col);
}

Point::Point(const Point& other)
{
	setRow(other.row);
	setCol(other.col);
}

Point::~Point()
{
}

int Point::getRow() const
{
	return this->row;
}
int Point::getCol() const
{
	return this->col;
}

void Point::setRow(int row)
{
	this->row = row;
}
void Point::setCol(int col)
{
	this->col = col;
}