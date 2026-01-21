/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utilis.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 18:17:06 by vs            #+#    #+#                 */
/*   Updated: 2026/01/21 12:46:24 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	mp;

	i = 0;
	mp = 1;
	nbr = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			mp = mp *(-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 +(nptr[i] - '0');
		i++;
	}
	return (nbr * mp);
}

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

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (c[len] != '\0')
		len ++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	d = malloc(len + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}

void	print_stack(int *to_print, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", to_print[i]);
		i++;
	}
}
