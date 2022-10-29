#include "AverageFunction.hpp"

//---------------------------Point---------------------------

list_point*	new_list_point( Point p )
{
	list_point*	res = new list_point;
	res->point = p;
	res->next = NULL;
	return (res);
}

void	free_list_point( list_point* lp )
{
	if (lp != NULL)
	{
		if (lp->next != NULL)
			free_list_point(lp->next);
		delete (lp);
	}
}

void	add_back_list_point( list_point** lp, list_point* new_lsp)
{
	list_point*	tmp;

	if (lp != NULL)
	{
		if (*lp != NULL)
		{
			tmp = *lp;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_lsp;
		}
		else
			*lp = new_lsp;
	}
}

void	print_list_point( list_point* lp )
{
	list_point*	tmp;
	int			i;

	tmp = lp;
	i = 1;
	while (tmp)
	{
		std::cout << "Point " << i << " : ";
		tmp->point.print();
		i++;
		tmp = tmp->next;
	}
}

//---------------------------Function---------------------------

list_function*	new_list_function( Function p )
{
	list_function*	res = new list_function;
	res->func = p;
	res->next = NULL;
	return (res);
}

void	free_list_function( list_function* lp )
{
	if (lp != NULL)
	{
		if (lp->next != NULL)
			free_list_function(lp->next);
		delete (lp);
	}
}

void	add_back_list_function( list_function** lp, list_function* new_lsp)
{
	list_function*	tmp;

	if (lp != NULL)
	{
		if (*lp != NULL)
		{
			tmp = *lp;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_lsp;
		}
		else
			*lp = new_lsp;
	}
}