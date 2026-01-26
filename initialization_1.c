/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization_1.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/24 14:03:03 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/26 18:09:04 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

static void	free_chr_stack(char **chr_stack)
{
	size_t	p;

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
	size_t	i;

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

void	free_t_stack(t_stack *to_free)
{
	if (to_free)
	{
		if (to_free->arr)
			free(to_free->arr);
		free(to_free);
	}
}

// to handle int overflow, atoi always returns the long which is always in
// long limits
static t_stack	*allocation(char **chr_stack, size_t p, t_stack *result)
{
	long	tmp;

	result = malloc(sizeof(t_stack));
	if (result == NULL)
		return (NULL);
	result->size = p;
	result->arr = malloc(sizeof(int) * result->size);
	if (!result->arr)
		return (free(result), NULL);
	p = 0;
	while (p < result->size)
	{
		tmp = ft_atoi(chr_stack[p]);
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			free_chr_stack(chr_stack);
			free_t_stack(result);
			return (NULL);
		}
		result->arr[p] = (int)tmp;
		p++;
	}
	free_chr_stack(chr_stack);
	return (result);
}

t_stack	*initialization(int argc, char **argv)
{
	t_stack	*result;
	char	**chr_stack;
	size_t	p;

	result = NULL;
	chr_stack = get_stack(argc, argv);
	if (!chr_stack)
		return (NULL);
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
	if (!result || is_unique_int(result) == 0)
	{
		free_t_stack(result);
		return (NULL);
	}
	return (result);
}
