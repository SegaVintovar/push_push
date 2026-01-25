/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/25 17:56:38 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/25 19:42:04 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

int	is_unique_int(t_stack *a)
{
	size_t	i;
	size_t	p;

	i = 0;
	p = 0;
	while (i < a->size - 1)
	{
		p = i + 1;
		while (a->arr[i] != a->arr[p] && p < a->size - 1)
			p++;
		if (a->arr[i] == a->arr[p])
			return (0);
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] > INT_MAX || a->arr[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	find_the_smallest_value(t_stack *any)
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
