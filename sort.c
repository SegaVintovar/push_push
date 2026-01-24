/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/10 15:07:38 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/24 14:54:59 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

int	is_sorted(t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] < a->arr[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

static void	sort_size_three(t_stack *a)
{
	if (a->arr[0] > a->arr[1])
		swap_a(a);
	if (is_sorted(a) == 0)
		rra(a);
}

static int find_the_smallest_value(t_stack *any)
{
	int		smallest;
	size_t	i;

	i = 0;
	smallest = any->arr[0];
	while (i < any->size)
	{
		if (any->arr[i] < smallest)
			smallest = any->arr[i];
		i++;
	}
	return (smallest);
}

static void	sort_size_four(t_stack *a, t_stack *b)
{
	int	smallest_int_in_stack;

	smallest_int_in_stack = find_the_smallest_value(a);
	while (a->arr[0] != smallest_int_in_stack)
	{
		rra(a);
	}
	if (is_sorted(a) == 0)	
		pb(a, b);
	if (is_sorted(a) == 0)
		sort_size_three(a);
	if (b->size > 0)	
		pa(a, b);
}

void	pop_smallest_via_rotate(t_stack *any)
{
	int		smallest_int_in_stack;
	size_t	half_size;
	size_t	i;

	half_size = any->size / 2;
	i = 0;
	smallest_int_in_stack = find_the_smallest_value(any);
	while (smallest_int_in_stack != any->arr[i])
		i++;
	if (i > half_size)
	{
		while (any->arr[0] != smallest_int_in_stack)
			rra(any);
	}
	else
	{
		while (any->arr[0] != smallest_int_in_stack)
			ra(any);
	}
}

static void	sort_size_five(t_stack *a, t_stack *b)
{
	int	smallest_int_in_stack;
	
	smallest_int_in_stack = find_the_smallest_value(a);
	while (a->size > 3)
	{
		pop_smallest_via_rotate(a);
		pb(a, b);
	}
	sort_size_three(a);
	while (b->size != 0)
		pa(a, b);
}

void	algo(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == 1)
		return;
	while (is_sorted(a) == 0)
	{
		if (a->size == 1)
			return;
		else if (a->size == 2)
			swap_a(a);
		else if (a->size == 3)
			sort_size_three(a);
		else if (a->size == 4)
			sort_size_four(a, b);
		else if (a->size == 5)
			sort_size_five(a, b);
		else if (a->size > 5)
			radix_s(a, b);
	}
}
