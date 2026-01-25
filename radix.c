/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/24 13:45:06 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/25 19:17:32 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

//use this to figure out indexes of sorted list
static void	simple_sort(int *a, size_t size)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		if (a[i] > a[i + 1])
		{
			tmp = a[i + 1];
			a[i + 1] = a[i];
			a[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static int	*create_sorted_copy(t_stack *a)
{
	int		*sorted_arr;
	size_t	i;

	i = 0;
	sorted_arr = malloc(a->size * sizeof(int));
	if (!sorted_arr)
		return (NULL);
	while (i < a->size)
	{
		sorted_arr[i] = a->arr[i];
		i++;
	}
	simple_sort(sorted_arr, i);
	return (sorted_arr);
}

static void	convert_into_indices(t_stack *a)
{
	int		*sorted_copy;
	size_t	i;
	size_t	p;

	sorted_copy = create_sorted_copy(a);
	if (!sorted_copy)
		exit_and_free_all(a, NULL);
	i = 0;
	while (i < a->size)
	{
		p = 0;
		while (p < a->size)
		{
			if (a->arr[i] == sorted_copy[p])
			{
				a->arr[i] = p;
				break ;
			}
			p++;
		}
		i++;
	}
	free(sorted_copy);
}

static int	count_bits(size_t stack_size)
{
	int	i;
	int	bits_amount;

	bits_amount = 1;
	i = 0;
	while (i < 64)
	{
		if (stack_size >> i & 1)
			bits_amount = i;
		i++;
	}
	bits_amount++;
	return (bits_amount);
}

void	radix_s(t_stack *a, t_stack *b)
{
	int		bits_amnt;
	int		i;
	size_t	p;

	i = 0;
	bits_amnt = count_bits(a->size);
	convert_into_indices(a);
	while (i < bits_amnt)
	{
		p = a->size;
		while (p)
		{
			if ((a->arr[0] >> i) & 1)
				ra(a);
			else
				pb(a, b);
			p--;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
