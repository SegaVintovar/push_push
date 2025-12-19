#ifndef PUSH_PUSH_HEADER_H
# define PUSH_PUSH_HEADER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *arr;
	int size;
} stack;


int		ft_atoi(const char *nptr);
void	swap_a(int *stack_a);
void	swap_b(int *stack_b);
void	ss(int *stack_a, int *stack_b);
void	rra(int *stack_a, int argc);


#endif