/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/20 12:26:50 by vsudak        #+#    #+#                 */
/*   Updated: 2025/12/19 14:09:45 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

// duplicating the string
// there is malloc
char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			d[i] = s[i];
			i++;
		}
	}
	d[i] = '\0';
	return (d);
}
// int main()
// {
// 	char *ee = "123";
// 	char *dd = ft_strdup(ee);
// 	printf("%s\n", dd);
// }
// tester wanted me to seg fault when !s,
// but i used a guard in the very begining 
