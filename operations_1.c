/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:41:08 by vsudak            #+#    #+#             */
/*   Updated: 2025/12/29 18:24:41 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

void	swap_a(t_stack *a)
{
	int tmp;

	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;

	printf("sa\n");
}

void	swap_b(t_stack *b)
{
	int tmp;

	tmp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = tmp;
	printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int tmp;

	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
	tmp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = tmp;
	printf("ss\n");
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
	printf("ra\n");
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
	printf("rb\n");
}

void	rra(t_stack *a)
{
	int tmp;
	size_t count;
	
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
		printf("second_rra\n");
	}
}

// rra with malloc = I'll leave it here
// void	rra(t_stack *a)
// {
// 	int *tmp_stack;
// 	int p;

// 	if (a->size > 0)
// 	{
// 		p = 0;
// 		tmp_stack = malloc(a->size * sizeof(int));
// 		tmp_stack[p] = a->arr[a->size - 1];
// 		p++;
// 		while(p < a->size)
// 		{
// 			tmp_stack[p] = a->arr[p - 1];
// 			p++;
// 		}
// 		free(a->arr);
// 		a->arr = NULL;
// 		a->arr = tmp_stack;
// 		tmp_stack = NULL;
// 		printf("rra\n");
// 	}
// }



// int main()
// {
// 	t_stack *a;
// 	a = malloc(sizeof(t_stack));
// 	a->size = 4;
// 	a->arr = malloc(sizeof(int) * a->size);
// 	a->arr[0] = 1;
// 	a->arr[1] = 2;
// 	a->arr[2] = 3;
// 	a->arr[3] = 4;

// 	ra(a);

// 	printf("t_stack a\n");

// 	print_stack(a);
// 	free(a->arr);
// 	free(a);
// }

