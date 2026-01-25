/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/13 12:41:56 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/25 19:03:37 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

void	rr(t_stack *a, t_stack *b)
{
	int		tmp;
	size_t	count;

	count = 0;
	tmp = a->arr[0];
	while (a->size - 1 > count)
	{
		a->arr[count] = a->arr[count + 1];
		count++;
	}
	a->arr[a->size - 1] = tmp;
	count = 0;
	tmp = b->arr[0];
	while (b->size - 1 > count)
	{
		b->arr[count] = b->arr[count + 1];
		count++;
	}
	b->arr[b->size - 1] = tmp;
	write(1, "rr\n", 3);
}

void	rrb(t_stack *b)
{
	int		tmp;
	size_t	count;

	count = 0;
	if (b->size > 0)
	{
		tmp = b->arr[b->size - 1];
		while (count < b->size - 1)
		{
			b->arr[b->size - count - 1] = b->arr[b->size - count - 2];
			count++;
		}
		b->arr[0] = tmp;
		write(1, "rrb\n", 4);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
	tmp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = tmp;
	write(1, "ss\n", 3);
}
