#include "Point.hpp"

Point::Point( void )
	: _x(0), _y(0)
{}

Point::Point( int x, int y )
	: _x(x), _y(y)
{}

Point::Point( const Point& cp )
	: _x(cp._x), _y(cp._y)
{}

Point& Point::operator=( const Point& cp )
{
	this->_x = cp._x;
	this->_y = cp._y;
	return (*this);
}

Point::~Point( void )
{}

void	Point::setX( int x )
{
	this->_x = x;
}

void	Point::setY( int y )
{
	this->_y = y;
}

int		Point::getX( void )
{
	return (this->_x);
}

int		Point::getY( void )
{
	return (this->_y);
}

void	Point::print( void )
{
	std::cout << "x(" << this->_x << ") y(" 
		<< this->_y << ")" << std::endl;
}