
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

int is_unique(stack a)
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

int main(int argc, char **argv)
{
	char str[6] = " -23a";
	stack	a;
	size_t	i;

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
	//printf("%d\n", is_number(str));

}
