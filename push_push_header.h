#ifndef PUSH_PUSH_HEADER_H
# define PUSH_PUSH_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct //s_stack
{
	int *arr;
	int size;
	//struct s_stack *next;
}	t_stack;

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *nptr);
void	swap_a(int *stack_a);
void	swap_b(int *stack_b);
void	ss(int *stack_a, int *stack_b);
void	rra(int *stack_a, int argc);
char	**ft_split(char const *s, char c);
static size_t	word_count(const char *s, char delimiter);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
int		*pb_shrink_stack_a(t_stack *a, int *tmp_arr);
int		*pb_enlarge_stack_b(t_stack *b, int tmp, int *tmp_arr);


#endif