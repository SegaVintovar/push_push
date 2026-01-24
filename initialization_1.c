/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization_1.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/24 14:03:03 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/24 14:34:48 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

static void	free_chr_stack(char **chr_stack)
{
	size_t p;

	p = 0;
	while (chr_stack[p] != NULL)
	{
		free(chr_stack[p]);
		p++;
	}
	free(chr_stack);
}

int	is_number(char *arg)
{
	unsigned int	i;
	
	i = 0;
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_unique(t_stack *a)
{
	size_t	i;
	size_t	p;

	i = 0;
	p = 0;
	while (i < a->size - 1)
	{
		p = i + 1;
		while (a->arr[i] != a->arr[p] && p < a->size - 1)
			p++;
		if (a->arr[i] == a->arr[p])
			return (0);
		i++;
	}
	return (1);
}

static t_stack	*allocation(char **chr_stack, size_t p, t_stack *result)
{
	result = malloc(sizeof(t_stack));
	if (result == NULL)
	{
		free_chr_stack(chr_stack);
		free(result);
		return (NULL);
	}
	result->size = p;
	result->arr = malloc(sizeof(int) * result->size);
	if (!result->arr)
	{
		free_chr_stack(chr_stack);
		free(result);
		return (NULL);
	}
	p = 0;
	while (p < result->size)
	{
		result->arr[p] = ft_atoi(chr_stack[p]);
		p++;
	}
	return (result);
}

t_stack	*initialization(int argc, char **argv)
{
	t_stack	*result;
	char	**chr_stack;
	size_t	p;

	result = NULL;
	chr_stack = get_stack(argc, argv);
	p = 0;
	while (chr_stack[p] != NULL)
	{
		if (is_number(chr_stack[p]) == 0)
		{
			free_chr_stack(chr_stack);
			return (NULL);
		}
		p++;
	}
	result = allocation(chr_stack, p, result);
	free_chr_stack(chr_stack);
	if (is_unique(result) == 0)
	{
		free(result->arr);
		free(result);
		return (NULL);
	}
	return (result);
}