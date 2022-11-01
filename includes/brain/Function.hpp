#ifndef FUNCTION_HPP
# define FUNCTION_HPP

#include <iostream>

class Function
{
	private :
		float	_a;
		float	_b;
	
	public :
		Function( void );
		Function( float a, float b );
		~Function( void );

		float	getA( void );
		float	getB( void );
		void	print( void );

		float	calc( int x );
};

#endif