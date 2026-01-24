#include <stdio.h>
#include "push_push_header.h"

//AI free all
void free_all(t_stack *a, t_stack *b)
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

// void free_all(t_stack *a, t_stack *b)
// {
// 	if (b->size > 0)
// 		free(b->arr);
// 	if (0 < a->size)
// 		free(a->arr);
// 	free(b);
// 	free(a);
// }

void	exit_and_free_all(t_stack *a, t_stack *b)
{
	free_all(a, b);
	write(2, "Error\n", 7);
	exit(1);
}

// $(shuf -i 1-100 -n 100)
int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
	{
    	write(2, "Error\n", 7);
    	exit(1);
	}
	b->arr = malloc(sizeof(int*));
	if (!b->arr)
	{
		write(2, "Error\n", 7);
		free(b);
		exit(1);
	}
	b->size = 0;
	a = initialization(argc, argv);
	if (!a)
		exit_and_free_all(a, b);
	algo(a, b);
	print_stack(a->arr, a->size);
	free_all(a, b);
	__INT_MAX__;
}
