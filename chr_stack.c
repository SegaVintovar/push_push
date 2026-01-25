/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chr_stack.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/24 14:27:42 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/25 18:03:18 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

static size_t	word_counter(const char *s, char delimiter)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] != delimiter && (i == 0 || s[i - 1] == delimiter))
			wc++;
		i++;
	}
	return (wc);
}

// mb make it return char** ???, to track the fail?
static char	**split_every_arg(int argc, char **argv, char **chr_stack)
{
	char	**tmp;
	int		i;
	int		s;
	int		p;

	i = 1;
	p = 0;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (NULL);
		s = 0;
		while (tmp && tmp[s] != NULL)
		{
			chr_stack[p] = tmp[s];
			p++;
			s++;
		}
		i++;
		free(tmp);
	}
	chr_stack[p] = NULL;
	return (chr_stack);
}

char	**get_stack(int argc, char **argv)
{
	char	**chr_stack;
	int		i;
	size_t	t;

	t = 0;
	i = 1;
	while (i < argc)
	{
		t += word_counter(argv[i], ' ');
		i++;
	}
	chr_stack = malloc(sizeof(char *) * (t + 1));
	if (!chr_stack)
		return (NULL);
	chr_stack = split_every_arg(argc, argv, chr_stack);
	return (chr_stack);
}
