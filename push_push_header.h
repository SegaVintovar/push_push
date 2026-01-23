#ifndef PUSH_PUSH_HEADER_H
# define PUSH_PUSH_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int		*arr;
	size_t	size;
	int		*lis;
	// LIS result, size is the same as stack_arr size, I need to calloc it
	size_t	keep_size;
	int		*keep;
	//the values that we want ot keep in stack_a
}	t_stack;

// typedef struct
// {
// 	int *arr;
// 	size_t arr_size;
// 	int *seq;
// 	size_t seq_size;
// }	in_order;

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
long	ft_atoi(const char *nptr);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
char	**ft_split(char const *s, char c);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
int		*pb_shrink_stack_a(t_stack *a, int *tmp_arr);
int		*pb_enlarge_stack_b(t_stack *b, int tmp, int *tmp_arr);
void	print_stack(int *arr, size_t size);
void	algo(t_stack *a, t_stack *b);
void	convert_into_indices(t_stack *a);



#endif