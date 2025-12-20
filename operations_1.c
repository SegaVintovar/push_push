/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/13 12:41:08 by vsudak        #+#    #+#                 */
/*   Updated: 2025/12/19 19:42:24 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

void	swap_a(int *stack_a)
{
	int tmp;

	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;

	printf("sa\n");
}

void	swap_b(int *stack_b)
{
	int tmp;

	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
	ft_print_dcs("sb\n");
}

void	ss(int *stack_a, int *stack_b)
{
	int tmp;

	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
	ft_print_dcs("ss\n");
}
//ft_shrink. removing the first element and move all the elemets 1 pos up
void	ft_realloc(int *stack, int new_size)
{
	
}

void	stack_size(stack a_b.arr)
{
	a_b.size = sizeof(a_b.arr);
}

void	pa(int *stack_a, int size_a, int *stack_b, int size_b)
{
	int		tmp;
	int		*tmp_arr;
	size_t	i;
	size_t	p;
	
	i = 0;
	p = 1;
	tmp = stack_b[0];
	//adjust stack b. shrink it
	tmp_arr = malloc(sizeof(int) * (size_b - 1));
	if (!tmp_arr)
		return (NULL);
	while(i < size_b - 1)
	{
		
	}
	//update stack_b size
	//enlarge stack_a.
	
	//place the tmp into the first pos of the stack_a
}

void	rra(int *stack_a, int stack_size)
{
	int *tmp_stack;
	int a;
	int b;

	a = 0;
	b = 1;
	
	tmp_stack[0] = stack_a[stack_size];
	while(b < stack_size)
	{
		tmp_stack[b] = stack_a[a];
		a++;
		b++;
	}
	
	ft_printf("rra\n");
}

void	pb(int *stack_a, int *stack_b)
{
	ft_print_dcs("pb\n");
}