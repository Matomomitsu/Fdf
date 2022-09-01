/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 01:36:26 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/16 22:54:29 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	rotate_x(t_point *point, double angle)
{
	t_point	*p_2;

	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			p_2->converted.rotated.y = p_2->y * cos(rad(angle)) \
			- p_2->converted.z * sin(rad(angle));
			p_2->converted.rotated.z = p_2->y * sin(rad(angle)) \
			+ p_2->converted.z * cos(rad(angle));
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

static void	change_angle(t_point *point)
{
	if (point->converted.rotated.rot_x <= -1)
		point->converted.rotated.rot_x = 359;
	if (point->converted.rotated.rot_x >= 360)
		point->converted.rotated.rot_x = 0;
}

void	rotation_x(t_point *point, t_fdf *fdf, int keycode)
{
	size_t	temp_angle;

	if (keycode == 65364)
		point->converted.rotated.rot_x--;
	if (keycode == 65362)
		point->converted.rotated.rot_x++;
	change_angle(point);
	temp_angle = point->converted.rotated.rot_x;
	rotate_x(point, temp_angle);
	temp_angle = point->converted.rotated.rot_y;
	rotate_y(point, temp_angle);
	temp_angle = point->converted.rotated.rot_z;
	rotate_z(point, temp_angle);
	clear_img(fdf);
	draw_fdf(fdf->i_point, fdf);
	render(fdf);
}
