#include "AverageFunction.hpp"

#include <cstdlib>

int	main( void )
{
	AverageFunction av;
	const int	xmax = 50;
	const int	ymax = 100;
	const int	nbPoint = 5;
	int			i;
	int			x;
	int			y;

	srand (time(NULL));
	i = 0;
	while (i++ < nbPoint)
	{
		x = rand() % xmax;
		y = rand() % ymax;
		av.addPoint(x, y);
	}
	av.print_points();
	av.calc_func();
	av.print_func();
	return (0);
}