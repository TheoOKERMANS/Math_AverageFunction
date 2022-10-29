#ifndef AVERAGEFUNCTION_HPP
# define AVERAGEFUNCTION_HPP

#include "Point.hpp"
#include "Structs.hpp"
#include "Function.hpp"
#include <iostream>
#include <stddef.h>

class AverageFunction
{
	private :
		list_point*	_pointlst;
		Function	_func;
		bool		_func_calc;
		float		_best_dif;
		const static float	_accuracy = 1;

		bool	_check_error( void );
		void	_update_best_func( float pow );
		float	_get_diff( Function func, Point p );
		float	_get_all_diff( Function func );
		bool	_test_func( Function func );

	public :
		AverageFunction( void );
		~AverageFunction( void );

		void	addPoint( Point p );
		void	addPoint( int x, int y );
		void	print_points( void );
		void	print_func( void );

		void	calc_func( void );
};

#endif