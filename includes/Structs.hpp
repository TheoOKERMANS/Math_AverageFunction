#ifndef STRUCTS_HPP
# define STRUCTS_HPP

#include "Point.hpp"
#include "Function.hpp"

struct list_point{
	Point	point;
	list_point*	next;
};

void		free_list_point( list_point* lp );
void		add_back_list_point( list_point** lp, list_point* new_lsp);
list_point*	new_list_point( Point p );
void		print_list_point( list_point* lp );

struct list_function{
	Function	func;
	list_function*	next;
};

void		free_list_function( list_function* lp );
void		add_back_list_function( list_function** lp, list_function* new_lsp);
list_function*	new_list_function( Function p );

#endif