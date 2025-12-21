/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:41:08 by vsudak            #+#    #+#             */
/*   Updated: 2025/12/21 11:42:30 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

void	swap_a(int *stack_a)
{
	int tmp;

	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;

	printf("sa\n");
}

void	swap_b(int *stack_b)
{
	int tmp;

	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
	printf("sb\n");
}

void	ss(int *stack_a, int *stack_b)
{
	int tmp;

	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
	printf("ss\n");
}
//ft_shrink. removing the first element and move all the elemets 1 pos up
// void	ft_realloc(int *stack, int new_size)
// {
	
// }

// void	stack_size(int *arr)
// {
// 	a_b.size = sizeof(a_b.arr);
// }

void	pa(int *stack_a, int size_a, int *stack_b, int size_b)
{
	int		tmp;
	int		*tmp_arr;
	size_t	i;
	size_t	p;

	i = 0;
	p = 0;
	tmp = stack_b[p];
	p++;
	if (size_b > 1)
	{
		tmp_arr = malloc(sizeof(int) * (size_b - 1));
		while(i < size_b - 1)
		{
			tmp_arr[i] = stack_b[p];
			i++;
			p++;
		}
	}
	if (size_b = 1)
	{
		stack_b = NULL;
		size_b = 0;
	}
	else
		return;
	size_b--;
	if (stack_b)
		free(stack_b);
	stack_b = tmp_arr;
	tmp_arr = NULL;
	tmp_arr = malloc((size_a + 1) * sizeof(int *));
	p = 0;
	tmp_arr[p] = tmp;
	p++;
	while (p <= size_a + 1)
	{
		tmp_arr[p] = stack_a[p + 1];
		p++;
	}
	free(stack_a);
	stack_a = tmp_arr;
	tmp_arr = NULL;
	size_a++;
	printf("pa\n");
}

// int main()
// {
// 	int i = 0;
// 	stack A;
// 	int src_a[3] = {2, 3, 4};
// 	int src_b[1] = {1};
// 	stack B;
// 	A.arr = malloc(sizeof(int) * 3);
// 	while (i < 3)
// 	{
// 		A.arr[i] = src_a[i];
// 		i++;
// 	}
// 	B.arr = malloc(1 * sizeof(int));
// 	B.arr[0] = src_b[0];
// 	A.size = 3;
// 	B.size = 1;
// 	pa(A.arr, A.size, B.arr, B.size);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("%d\n", A.arr[i++]);
// 	}
// //	free(A.arr);
// //	free(B.arr);
// }

void	rra(int *stack_a, int stack_size)
{
	int *tmp_stack;
	int a;
	int b;

	a = 0;
	b = 1;
	
	tmp_stack[0] = stack_a[stack_size];
	while(b < stack_size)
	{
		tmp_stack[b] = stack_a[a];
		a++;
		b++;
	}
	
	printf("rra\n");
}

void	pb(int *stack_a, int *stack_b)
{
	printf("pb\n");
}