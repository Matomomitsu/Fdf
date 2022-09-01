/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 06:49:46 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/30 19:16:18 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

double	rad(double num)
{
	return (((num * M_PI) / 180));
}

int	abs(int num)
{
	if (num >= 0)
		return (num);
	else
		return (-num);
}

void	convert_point(t_point *point, double max_x, double max_y)
{
	double	x;
	double	y;
	double	z;

	x = point->x;
	y = point->y;
	if (point->converted.z == 0)
	{
		z = point->z;
		point->converted.z = z;
	}
	else
		z = point->converted.z;
	max_x = (max_x * cos(rad(30))) + \
			(max_y * cos(rad(150)));
	max_y = (max_x * sin(rad(30))) + \
			(max_y * sin(rad(150)));
	point->converted.x = (x - y) * cos(rad(30)) \
					+ (600 - max_x / 2);
	point->converted.x = -z + (x + y) * sin(rad(30)) \
					+ (400 - max_y / 2);
}
