/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:30:03 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/16 22:54:03 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	change_scale_x(t_point *point, double r)
{
	t_point	*point_2;
	t_point	*point_3;

	point_3 = point;
	point_2 = point;
	while (point_2 != NULL)
	{
		while (point_2->right != NULL)
		{
			point_2->right->x = point_2->x + r;
			point_2->right->converted.rotated.x = point_2->right->x;
			point_2 = point_2->right;
		}
		point_2 = point_3->below;
		point_3 = point_3->below;
	}
}

void	change_scale_y(t_point *point, double r)
{
	t_point	*point_2;
	t_point	*point_3;

	point_3 = point;
	point_2 = point;
	while (point_2 != NULL)
	{
		while (point_2->below != NULL)
		{
			point_2->below->y = point_2->y + r;
			point_2->below->converted.rotated.y = point_2->below->y;
			point_2 = point_2->below;
		}
		point_2 = point_3->right;
		point_3 = point_3->right;
	}
}

void	get_scale(t_point	*point)
{
	double	r;
	double	max_x;
	double	max_y;
	double	temp_num;

	get_max(point, &max_x, &max_y);
	temp_num = (max_x + 20) / 20;
	r = 750 / (temp_num - 1);
	temp_num = (max_y + 20) / 20;
	if (r * (temp_num - 1) >= 575)
		r = 575 / (temp_num -1);
	change_scale_x(point, r);
	change_scale_y(point, r);
}
