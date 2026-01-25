/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_3.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/13 12:45:46 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/25 19:05:47 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

void	rrr(t_stack *a, t_stack *b)
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
	}
	if (b->size > 0)
	{
		tmp = b->arr[b->size - 1];
		while (count < b->size - 1)
		{
			b->arr[b->size - count - 1] = b->arr[b->size - count - 2];
			count++;
		}
		b->arr[0] = tmp;
	}
	write(1, "rrr\n", 4);
}

static int	*push_from_src_stack(t_stack *src, int *tmp_arr)
{
	size_t	i;

	i = 0;
	if (src->size > 1)
	{
		tmp_arr = malloc(sizeof(int) * (src->size - 1));
		if (!tmp_arr)
			return (NULL);
	}
	while (i < src->size - 1)
	{
		tmp_arr[i] = src->arr[i + 1];
		i++;
	}
	src->size--;
	free(src->arr);
	return (tmp_arr);
}

// takes the value that we are pushing, enlarging dest stack
static int	*enlarge_dest_stack(t_stack *dest, int tmp)
{
	size_t	i;
	int		*tmp_arr;

	i = 0;
	tmp_arr = malloc((dest->size + 1) * sizeof(int));
	if (!tmp_arr)
		return (NULL);
	i = 0;
	tmp_arr[i] = tmp;
	i++;
	while (dest->size >= i)
	{
		tmp_arr[i] = dest->arr[i - 1];
		i++;
	}
	if (dest->arr)
	{
		free(dest->arr);
		dest->arr = NULL;
	}
	dest->size++;
	return (tmp_arr);
}

void	pb(t_stack *a, t_stack *b)
{
	int		tmp;
	int		*tmp_arr;

	tmp_arr = NULL;
	tmp = a->arr[0];
	tmp_arr = push_from_src_stack(a, tmp_arr);
	if (!tmp_arr)
		exit_and_free_all(a, b);
	a->arr = tmp_arr;
	tmp_arr = NULL;
	b->arr = enlarge_dest_stack(b, tmp);
	if (!b->arr)
		exit_and_free_all(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	int		tmp;
	int		*tmp_arr;

	tmp_arr = NULL;
	tmp = b->arr[0];
	tmp_arr = push_from_src_stack(b, tmp_arr);
	if (!tmp_arr && b->size > 0)
		exit_and_free_all(a, b);
	b->arr = tmp_arr;
	tmp_arr = NULL;
	a->arr = enlarge_dest_stack(a, tmp);
	if (!a->arr)
		exit_and_free_all(a, b);
	write(1, "pa\n", 3);
}
