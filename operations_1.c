/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/13 12:41:08 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/25 19:15:41 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

void	swap_a(t_stack *a)
{
	int	tmp;

	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *b)
{
	int	tmp;

	tmp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = tmp;
	write(1, "sb\n", 3);
}

void	ra(t_stack *a)
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
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int		tmp;
	size_t	count;

	count = 0;
	tmp = b->arr[0];
	while (b->size - 1 > count)
	{
		b->arr[count] = b->arr[count + 1];
		count++;
	}
	b->arr[b->size - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rra(t_stack *a)
{
	int		tmp;
	size_t	count;

	count = 0;
	if (a->size > 0)
	{
		tmp = a->arr[a->size - 1];
		while (count < a->size - 1)
		{
			a->arr[a->size - count - 1] = a->arr[a->size - count - 2];
			count++;
		}
		a->arr[0] = tmp;
		write(1, "rra\n", 4);
	}
}
