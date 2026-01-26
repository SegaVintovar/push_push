/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_push_header.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/25 19:09:08 by vsudak        #+#    #+#                 */
/*   Updated: 2026/01/26 18:03:22 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_PUSH_HEADER_H
# define PUSH_PUSH_HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int		*arr;
	size_t	size;
}	t_stack;

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
void	print_stack(int *arr, size_t size);
void	algo(t_stack *a, t_stack *b);
void	radix_s(t_stack *a, t_stack *b);
char	**get_stack(int argc, char **argv);
t_stack	*initialization(int argc, char **argv);
void	exit_and_free_all(t_stack *a, t_stack *b);
int		is_unique_int(t_stack *a);
int		is_sorted(t_stack *a);
int		find_the_smallest_value(t_stack *any);

#endif