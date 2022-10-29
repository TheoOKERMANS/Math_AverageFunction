#include "Function.hpp"

Function::Function( void )
	: _a(1), _b(0)
{}

Function::Function( float a, float b )
	: _a(a), _b(b)
{}

Function::~Function( void )
{}

void	Function::print( void )
{
	std::cout << "f(x) = " << this->_a << "x + " << this->_b << std ::endl;
}

float	Function::getA( void )
{
	return (this->_a);
}

float	 Function::getB( void )
{
	return (this->_b);
}

float	Function::calc( int x )
{
	return ((this->_a * (float)x) + this->_b);
}