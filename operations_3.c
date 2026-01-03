/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:45:46 by vsudak            #+#    #+#             */
/*   Updated: 2025/12/31 13:43:36 by vs               ###   ########.fr       */
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
	printf("rrr\n");
}

int	*push_from_src_stack(t_stack *src, int *tmp_arr)
{
	size_t	i;

	i = 0;
	tmp_arr = malloc(sizeof(int) * ( src->size - 1));
	while (i < src->size - 1)
	{
		tmp_arr[i] = src->arr[i + 1];
		i++;
	}
	src->size--;
	if (src->arr)
		free(src->arr);
	return (tmp_arr);
}

// takes the value that we are pushing, enlarging dest stack
// 
int	*enlarge_dest_stack(t_stack *dest, int tmp)
{
	size_t	i;
	int	*tmp_arr;

	i = 0;
	tmp_arr = malloc((dest->size + 1) * sizeof(int));
	if (!tmp_arr)
		exit(1);
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
	if (a->arr)
	{
		tmp = a->arr[0];
		tmp_arr = push_from_src_stack(a, tmp_arr);
		a->arr = tmp_arr;
		tmp_arr = NULL;
		b->arr = enlarge_dest_stack(b, tmp);
	}
	else
		return;
	printf("pb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	int		tmp;
	int		*tmp_arr;

	tmp_arr = NULL;
	if (b->arr)
	{
		tmp = b->arr[0];
		tmp_arr = push_from_src_stack(b, tmp_arr);
		b->arr = tmp_arr;
		tmp_arr = NULL;
		a->arr = enlarge_dest_stack(a, tmp);
	}
	else
		return;
	printf("pa\n");
}
