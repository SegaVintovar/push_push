#include <stdio.h>
#include "push_push_header.h"

void free_all(t_stack *a, t_stack *b)
{
	if (b->arr)
		free(b->arr);
	if (0 < a->size)
	{	
		free(a->arr);
		//free(a->keep);
		free(a->lis);
	}
	free(b);
	free(a);
}

// $(shuf -i 1-100 -n 100)
int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	b->arr = malloc(sizeof(int*));
	b->size = 0;
	a = initialization(argc, argv);
	if (a == NULL)
	{
		free(b->arr);
		free(b);
		return(write(2, "error\n", 7));
	}
	algo(a, b);
	free_all(a, b);
	__INT_MAX__;
}
