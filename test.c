
#include <stdio.h>
#include "push_push_header.h"

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
	while (i < a.size)
	{
		p = i + 1;
		while (a.arr[i] != a.arr[p] && p < a.size)
			p++;
		if (a.arr[i] == a.arr[p])
			return (0);
		i++;
	}
	return (1);
}
// get the top a element. shrink stack a, enlarge stack b by 1
// 
void	pb(t_stack a, t_stack b)
{
	int		tmp;
	int		*tmp_arr = NULL;
	size_t	i;

	i = 0;
	if (a.arr)
	{
		tmp = a.arr[0];
		a.size -= 1;
		tmp_arr = malloc(sizeof(int) * a.size);
		while (i < a.size)
		{
			tmp_arr[i] = a.arr[i + 1];
			i++;
		}
		free(a.arr);
		a.arr = tmp_arr;
		tmp_arr = NULL;

	}
	printf("pb\n");
}

t_stack	initialisation(int argc, char **argv)
{
	t_stack a;
	size_t	i;
	char **fake_argv;

	fake_argv = NULL;

	a.arr = NULL;
	i = 1;
	while (i < argc)
	{
		// we are reaching each element if the argv
		// then spliting it into new char**
		// then we are testing those for numberness
		
		if (is_number(fake_argv[i]) == 0)
			exit (1);
		i++;
	}
	a.size = argc - 1;
	a.arr = (int *)malloc(a.size * sizeof(int));
	i = 0;
	while (i < a.size)
	{
		a.arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (is_unique(a) == 0)
		exit (1);
	return (a);
}

int main(int argc, char **argv)
{
	t_stack	a;
	size_t	i;

	a.arr = NULL;
	i = 1;
	while (i < argc)
	{
		if (is_number(argv[i]) == 0)
			return (0);
		i++;
	}
	a.size = argc - 1;
	a.arr = (int *)malloc(a.size * sizeof(int));
	i = 0;
	while (i < a.size)
	{
		a.arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (is_unique(a) == 0)
		return (0);
	else
		i = 0;
		while (i < a.size)
		{
			printf("%d\n", a.arr[i]);
			i++;
		}
}
