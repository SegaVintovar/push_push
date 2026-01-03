
#include <stdio.h>
#include "push_push_header.h"

size_t	word_counter(const char *s, char delimiter)
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

int is_number(char *arg)
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

int is_unique(t_stack a)
{
	size_t	i;
	size_t	p;

	i = 0;
	p = 0;
	while (i < a.size - 1)
	{
		p = i + 1;
		while (a.arr[i] != a.arr[p] && p < a.size - 1)
		{
			if (a.arr[i] == a.arr[p])
				return (0);
			p++;
		}
		i++;
	}
	return (1);
}

// malloc initial stack
// char_stack going to contain all splited elements
// go by argv and split every in temporary str
// append it to stack`s str = malloc new one with a->size + wordcount

void	free_chr_stack(char **chr_stack)
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

char **get_stack(int argc, char **argv)
{
	char	**tmp;
	char	**chr_stack;
	int		i;
	int		p;
	int		s;
	size_t	t;

	t = 0;
	i = 1;
	p = 0;
	while (i < argc)
	{
		t += word_counter(argv[i], ' ');
		i++;
	}
	chr_stack = malloc(sizeof(char *) * (t + 1));
	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		s = 0;
		while (tmp[s] != NULL)
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

t_stack	*initialisation(int argc, char **argv)
{
	t_stack	*result;
	char	**chr_stack;
	size_t	p;

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
	free_chr_stack(chr_stack);
	if (is_unique(*result) == 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

// t_stack	pinitialisation(int argc, char **argv)
// {
// 	t_stack a;
// 	size_t	i;
// 	char **tmp;
// 	size_t	n;
// 	size_t	p;
// 	char **char_stack;

// 	tmp = NULL;

// 	a.arr = NULL;
// 	p = 0;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		// we are reaching each element if the argv
// 		// then spliting it into new char**
// 		// then we are testing those for numberness
// 		tmp = ft_split(argv[i], ' ');
// 		char_stack = malloc(word_count(tmp, ' ') * sizeof(char *));
// 		n = 0;
// 		while (tmp != NULL)
// 		{
// 			char_stack[p] = tmp[n];
// 			p++;
// 			n++;
// 		}
// 		// check how many args did we get?
// 		if (is_number(char_stack[p]) == 0)
// 			exit (1);
// 		i++;
// 	}
// 	a.size = argc - 1;
// 	a.arr = (int *)malloc(a.size * sizeof(int));
// 	i = 0;
// 	while (i < a.size)
// 	{
// 		a.arr[i] = ft_atoi(argv[i + 1]);
// 		i++;
// 	}
// 	if (is_unique(a) == 0)
// 		exit (1);
// 	return (a);
// }


int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	b->arr = malloc(sizeof(int*));
	b->size = 0;
	// i = 1;
	// while (i < argc)
	// {
	// 	if (is_number(argv[i]) == 0)
	// 		return (0);
	// 	i++;
	// }
	// a->size = argc - 1;
	// a->arr = (int *)malloc(a->size * sizeof(int));
	// i = 0;
	// while (i < a->size)
	// {
	// 	a->arr[i] = ft_atoi(argv[i + 1]);
	// 	i++;
	// }
	a = initialisation(argc, argv);
	pb(a, b);
	pb(a, b);
	swap_b(b);
	pa(a, b);
	printf("t_stack a\n");
	print_stack(a);
	printf("t_stack b\n");
	print_stack(b);
	if (0 < b->size)
		free(b->arr);
	if (0 < a->size)
		free(a->arr);
	free(b);
	free(a);
}
