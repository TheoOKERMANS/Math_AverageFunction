#include "AverageFunction.hpp"

#include <cstdlib>

int	main( void )
{
	AverageFunction av;
	const int	xmax = 50;
	const int	ymax = 50;
	const int	nbPoint = 5;
	int			i;

	i = 0;
	while (i++ < nbPoint)
		av.addPoint(rand() % xmax, rand() % ymax);
	av.print_points();
	av.calc_func();
	av.print_func();
	return (0);
}