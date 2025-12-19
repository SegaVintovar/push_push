/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:41:08 by vsudak            #+#    #+#             */
/*   Updated: 2025/12/19 11:15:17 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_print_dcs("sb\n");
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
	ft_print_dcs("ss\n");
}
void	pa(int *stack_a, int *stack_b)
{
	int tmp;
	
	tmp = stack_b[0];
	//adjust stack b.
	s
	//enlarge stack_a.
	 
}

void	rra(int *stack_a, int stack_size)
{
	int *tmp_stack;
	int a;
	int b;

	a = 0;
	b = 0;
	
	tmp_stack[0] = stack_a[stack_size];
	while(b < stack_size)
	{
		tmp_stack[b] = stack_a[a];
		a++;
		b++;
	}
	
	ft_printf("rra\n");
}

void	pb(int *stack_a, int *stack_b)
{
	ft_print_dcs("pb\n");
}