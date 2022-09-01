/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:58:26 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/12 21:51:39 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

double	check_max_min_z(t_point *point, double *max_z)
{
	t_point	*point_2;
	t_point	*point_3;
	double	min_z;

	point_2 = point;
	point_3 = point;
	*max_z = point->z;
	min_z = point->z;
	while (point_2 != NULL)
	{
		while (point_2 != NULL)
		{
			if (point_2->z > *max_z)
				*max_z = point_2->z;
			if (point_2->z < min_z)
				min_z = point_2->z;
			point_2 = point_2->right;
		}
		point_2 = point_3->below;
		point_3 = point_3->below;
	}
	return (min_z);
}

void	change_z(t_point *point)
{
	t_point	*point_2;
	double	scale_factor;
	double	max_z;
	double	min_z;

	min_z = check_max_min_z(point, &max_z);
	scale_factor = 1.0;
	if (max_z < 40 && min_z > -40)
	{
		if (max_z > 20 || min_z < -20)
			scale_factor = 5.0;
		else
			scale_factor = 10.0;
	}
	point_2 = point;
	while (point_2 != NULL)
	{
		while (point_2 != NULL)
		{
			point_2->z = point_2->z * scale_factor;
			point_2 = point_2->right;
		}
		point_2 = point->below;
		point = point->below;
	}
}
