/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:21:22 by vs                #+#    #+#             */
/*   Updated: 2025/12/17 18:46:16 by vs               ###   ########.fr       */
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
