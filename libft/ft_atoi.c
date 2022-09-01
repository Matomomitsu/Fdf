/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:37:39 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/12 22:48:37 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atoi(const char *nptr)
{
	size_t	i;
	double	signal;
	double	nb;

	i = 0;
	signal = 1.0;
	nb = 0.0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		signal *= -1.0;
		i++;
	}
	else
	{
		if (nptr[i] == '+')
			i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10.0) + (nptr[i] - 48.0);
		i++;
	}
	return (signal * nb);
}
