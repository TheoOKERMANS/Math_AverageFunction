#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>

class Point
{
	private :
		int	_x;
		int _y;

	public :
		Point( void );
		Point( int x, int y );
		Point( const Point& cp );
		Point& operator=( const Point& cp );
		~Point( void );

		void	setX( int x );
		void	setY( int y );
		int		getX( void );
		int		getY( void );
		void	print( void );
};

#endif