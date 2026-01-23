/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alco_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:07:38 by vsudak            #+#    #+#             */
/*   Updated: 2026/01/23 11:55:18 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

static int	is_sorted(t_stack *a)
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

static int	find_the_biggest_value(t_stack *any)
{
	int		biggest;
	size_t	i;

	i = 0;
	biggest = any->arr[0];
	while (i < any->size)
	{
		if (any->arr[i] > biggest)
			biggest = any->arr[i];
		i++;
	}
	return (biggest);
}

static void	sort_size_four(t_stack *a, t_stack *b)
{
	int	smallest_int_in_stack;
	size_t smallest_index;

	// get the smallest int to top and push it to b
	smallest_int_in_stack = find_the_smallest_value(a);
	// if (a->arr[0] > a->arr[1])
	// 	swap_a(a);
	// rizing the smallest to top
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
	int		half_size;
	size_t	i;

	half_size = any->size / 2;
	i = 0;
	smallest_int_in_stack = find_the_smallest_value(any);
	// figure out rotate or reverse rotate
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
	int	biggest_int_in_stack;
	
	smallest_int_in_stack = find_the_smallest_value(a);
	while (a->size > 3)
	{
		pop_smallest_via_rotate(a);
		pb(a, b);
	}
	// pop_smallest_via_rotate(a);
	// pb(a, b);
	// pop_smallest_via_rotate(a);
	// pb(a, b);
	sort_size_three(a);
	while (b->size != 0)
		pa(a, b);
	//pa(a, b);
	//biggest_int_in_stack = find_the_biggest_value(a);
}

//use this to figure out indexes of sorted list
void	simple_sort(int *a, size_t size)
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

int	*create_sorted_copy(t_stack *a)
{
	int		*sorted_arr;
	size_t	i;

	i = 0;
	sorted_arr = malloc(a->size * sizeof(int));
	while (i < a->size)
	{
		sorted_arr[i] = a->arr[i];
		i++;
	}
	simple_sort(sorted_arr, i);
	return (sorted_arr);
}

void	convert_into_indices(t_stack *a)
{
	int		*sorted_copy;
	size_t	i;
	size_t	p;

	sorted_copy = create_sorted_copy(a);
	i = 0;
	while (i < a->size)
	{
		p = 0;
		while (p < a->size)
		{
			if (a->arr[i] == sorted_copy[p])
			{
				a->arr[i] = p;
				break;
			}
			p++;
		}
		i++;
	}
	free(sorted_copy);
}



// void	push_chunks(t_stack *a, t_stack *b)
// {
// 	int	chunk_size;
// 	int	amount_of_chunks;

// 	if (a->size < 10)
// 		chunk_size = 3;
// 	if (a->size >= 10 && a->size < 50)
// 		chunk_size = 5;
// 	if (a->size >= 50 && a->size < 100)
// 		chunk_size = 7;
// 	if (a->size >= 100)
// 		chunk_size = 15;
// 	amount_of_chunks = a->size / chunk_size;
	
// 	if (a->size)
// }


void	push_a_to_the_coorect_location(t_stack *a, t_stack *b)
{
	// 
}

void	alco_algo(t_stack *a, t_stack *b)
{
	convert_into_indices(a);
	//init_sorted_seq(a);
	//print_stack(a->seq, a->size);
	while (is_sorted(a) == 0)
	{
		if (a->keep[0] == 0)
		{
			pb(a, b);
		}
		else
			ra(a);
	}
	
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
		{
			alco_algo(a, b);
			break;
		}
	}
}
