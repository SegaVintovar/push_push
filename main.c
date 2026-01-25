/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/25 19:25:27 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/25 19:33:19 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

void	free_all(t_stack *a, t_stack *b)
{
	if (b)
	{
		if (b->arr)
			free(b->arr);
		free(b);
	}
	if (a)
	{
		if (a->arr)
			free(a->arr);
		free(a);
	}
}

void	exit_and_free_all(t_stack *a, t_stack *b)
{
	free_all(a, b);
	write(2, "Error\n", 7);
	exit(1);
}

t_stack	*bstack_allocation(t_stack *a)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
		exit_and_free_all(a, b);
	b->arr = malloc(sizeof(int *));
	if (!b->arr)
		exit_and_free_all(a, b);
	b->size = 0;
	return (b);
}

// $(shuf -i 1-100 -n 100)
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		b = NULL;
		a = initialization(argc, argv);
		if (!a)
			exit_and_free_all(a, b);
		if (a->size > 3)
			b = bstack_allocation(a);
		algo(a, b);
		free_all(a, b);
	}
}
//#inlcude <stdio.h>
// void	print_stack(int *to_print, size_t size)
// {
// 	size_t	i;
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d\n", to_print[i]);
// 		i++;
// 	}
// }
