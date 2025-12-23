
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
		while (a.arr[i] != a.arr[p] && p < a.size)// vagrind "invalid read"
			p++;
		if (a.arr[i] == a.arr[p])// valgrind "invalide read"
			return (0);
		i++;
	}
	return (1);
}
// get the top a element. shrink stack a, enlarge stack b by 1

// the passing value should have been taken before, so now we shrink src stack
int	*push_from_src_stack(t_stack *src, int *tmp_arr)
{
	size_t	i;

	i = 0;
	tmp_arr = malloc(sizeof(int) * ( src->size - 1));
	while (i < src->size - 1)
	{
		tmp_arr[i] = src->arr[i + 1];
		i++;
	}
	src->size--;
	if (src->arr)
		free(src->arr);
	return (tmp_arr);
}

// takes the value that we are pushing, enlarging dest stack
// 
int	*enlarge_dest_stack(t_stack *dest, int tmp, int *tmp_arr)
{
	size_t	i;

	i = 0;
	tmp_arr = malloc((dest->size + 1) * sizeof(int));
	if (!tmp_arr)
		exit(1);
	i = 0;
	tmp_arr[i] = tmp;
	i++;
	while (dest->size >= i)
	{
		tmp_arr[i] = dest->arr[i - 1];
		i++;
	}
	if (dest->arr)
	{
		free(dest->arr);
		dest->arr = NULL;
	}
	dest->size++;
	return (tmp_arr);
}

void	pb(t_stack *a, t_stack *b)
{
	int		tmp;
	int		*tmp_arr;
	size_t	i;

	tmp_arr = NULL;
	i = 0;
	if (a->arr)
	{
		tmp = a->arr[0];
		tmp_arr = push_from_src_stack(a, tmp_arr);
		a->arr = tmp_arr;
		tmp_arr = NULL;
		b->arr = enlarge_dest_stack(b, tmp, tmp_arr);
	}
	else
		return;
	printf("pb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	int		tmp;
	int		*tmp_arr;
	size_t	i;

	tmp_arr = NULL;
	i = 0;
	if (a->arr)
	{
		tmp = b->arr[0];
		tmp_arr = push_from_src_stack(b, tmp_arr);
		a->arr = tmp_arr;
		tmp_arr = NULL;
		b->arr = enlarge_dest_stack(a, tmp, tmp_arr);
	}
	else
		return;
	printf("pa\n");
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
	t_stack	b;
	size_t	i;

	a.arr = NULL;
	b.arr = NULL;
	b.size = 0;
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
	if (is_unique(a) != 0)
	{
		i = 0;
		while (i < a.size)
		{
			printf("%d\n", a.arr[i]);
			i++;
		}
		printf("Push and print both arr\n");
		pb(&a, &b);
		pb(&a, &b);
		pa(&a, &b);
		i = 0;
		printf("t_stack a\n");
		// while (i < a.size)
		// {
		// 	printf("%d\n", a.arr[i]);
		// 	i++;
		// }
		i = 0;
		printf("t_stack b\n");
		while (i < b.size)
		{
			printf("%d\n", b.arr[i]);
			i++;
		}
	}
	else
		return (0);
	free(b.arr);
	free(a.arr);
}
