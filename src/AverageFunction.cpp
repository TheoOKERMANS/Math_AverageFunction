#include "AverageFunction.hpp"

AverageFunction::AverageFunction( void )
	: _pointlst(NULL), _func_calc(false)
{
	this->_func = Function();
}

AverageFunction::~AverageFunction( void )
{
	free_list_point(this->_pointlst);
}

void	AverageFunction::addPoint( Point p )
{
	add_back_list_point(&(this->_pointlst), new_list_point(p));
	this->_best_dif = this->_get_all_diff(this->_func);
}

void	AverageFunction::addPoint( int x, int y )
{
	this->addPoint(Point(x, y));
}

void	AverageFunction::print_points( void )
{
	print_list_point(this->_pointlst);
}

void	AverageFunction::print_func( void )
{
	this->_func.print();
}

bool	AverageFunction::_check_error( void )
{
	if (this->_pointlst == NULL)
	{
		std::cout << "No points" << std::endl;
		return (false);
	}
	else if (this->_func_calc == true)
	{
		std::cout << "Function already calculated" << std::endl;
		return (false);
	}
	return (true);
}

float		AverageFunction::_get_diff( Function func, Point p )
{
	float	res;

	res = func.calc(p.getX()) - (float)(p.getY());
	if (res < 0)
		res = -res;
	return (res);
}

float		AverageFunction::_get_all_diff( Function func )
{
	list_point*	tmp_point;
	float		res;

	tmp_point = this->_pointlst;
	res = 0;
	while (tmp_point != NULL)
	{
		res += this->_get_diff(func, tmp_point->point);
		tmp_point = tmp_point->next;
	}
	return (res);
}

bool	AverageFunction::_test_func( Function func )
{
	float		diff;

	diff = this->_get_all_diff(func);
	if (diff < this->_best_dif)
	{
		this->_best_dif = diff;
		this->_func = func;
		return (true);
	}
	return (false);
}

void	AverageFunction::_update_best_func( float pow )
{
	int			change;

	change = 1;
	while (change)
	{
		change = 0;
		if (this->_test_func(Function(this->_func.getA() + pow, this->_func.getB())) == true)
			change = 1;
		if (this->_test_func(Function(this->_func.getA() - pow, this->_func.getB())) == true)
			change = 1;
		if (this->_test_func(Function(this->_func.getA() + pow, this->_func.getB() + pow)) == true)
			change = 1;
		if (this->_test_func(Function(this->_func.getA() - pow, this->_func.getB() + pow)) == true)
			change = 1;
		if (this->_test_func(Function(this->_func.getA() + pow, this->_func.getB() - pow)) == true)
			change = 1;
		if (this->_test_func(Function(this->_func.getA() - pow, this->_func.getB() - pow)) == true)
			change = 1;
		if (this->_test_func(Function(this->_func.getA(), this->_func.getB() + pow)) == true)
			change = 1;
		if (this->_test_func(Function(this->_func.getA(), this->_func.getB() - pow)) == true)
			change = 1;
	}
}

void	AverageFunction::calc_func( void )
{
	float		pow;

	if (this->_check_error() == true)
	{
		pow = 1;
		while (pow >= AverageFunction::_accuracy)
		{
			this->_update_best_func(pow);
			if (this->_best_dif == 0)
				break ;
			pow /= 10;
		}
		this->_func_calc = true;
		std::cout << "Diff : " << this->_best_dif << "\n";
	}
}