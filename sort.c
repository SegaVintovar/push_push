/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:07:38 by vsudak            #+#    #+#             */
/*   Updated: 2026/01/28 11:47:34 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

// static void	sort_size_three(t_stack *a)
// {
// 	if (a->arr[0] > a->arr[1])
// 	{
// 		if (a->arr[0] > a->arr[2])
// 		{
// 			ra(a);
// 			swap_a(a);
// 			if (is_sorted(a) == 1)
// 				return ;
// 		}
// 		swap_a(a);
// 		if (is_sorted(a) == 1)
// 			return ;
// 	}
// 	if (is_sorted(a) == 0)
// 		rra(a);
// }

// 1 3 2	sa + ra
// 2 1 3	sa
// 2 3 1	rra
// 3 1 2	ra
// 3 2 1	sa + rra
static void	sort_size_three(t_stack *a)
{
	if (a->arr[0] < a->arr[1] && a->arr[1] > a->arr[2])
		return (swap_a(a), ra(a));
	if ((a->arr[0] > a->arr[1]) && a->arr[0] < a->arr[2])
		return (swap_a(a));
	if (a->arr[0] < a->arr[1] && a->arr[0] > a->arr[2])
		return (rra(a));
	if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2])
		return (ra(a));
	if (a->arr[0] > a->arr[1] && a->arr[1] > a->arr[2])
		return (swap_a(a), rra(a));
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
		return ;
	else
	{
		if (a->size == 1)
			return ;
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
