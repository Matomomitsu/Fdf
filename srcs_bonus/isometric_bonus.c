/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 06:49:46 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/23 03:56:42 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

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

void	verify_rotation(t_point	*point, double *x, double *y, double *z)
{
	if (point->converted.rotated.x != point->x)
		*x = point->converted.rotated.x;
	if (point->converted.rotated.y != point->y)
		*y = point->converted.rotated.y;
	if (point->converted.rotated.z != point->converted.z)
		*z = point->converted.rotated.z;
}

void	verify_translation(t_point *point, double *max_x, double *max_y)
{
	*max_x = *max_x + point->converted.translated.trans_x;
	*max_y = *max_y + point->converted.translated.trans_y;
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
	verify_rotation(point, &x, &y, &z);
	max_x = (max_x * cos(rad(30))) + \
			(max_y * cos(rad(150)));
	max_y = (max_x * sin(rad(30))) + \
			(max_y * sin(rad(150)));
	verify_translation(point, &max_x, &max_y);
	point->converted.x = (x - y) * cos(rad(30)) \
					+ (600 - max_x / 2);
	point->converted.y = -z + (x + y) * sin(rad(30)) \
					+ (500 - max_y / 2);
}
