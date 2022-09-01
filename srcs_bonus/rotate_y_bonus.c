/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:27:48 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/16 22:54:30 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

static void	verify_rot_y(t_point *p_2, double angle)
{
	if (p_2->converted.rotated.z == p_2->converted.z)
	{
		p_2->converted.rotated.x = p_2->x * cos(rad(angle)) \
		- p_2->converted.z * sin(rad(angle));
		p_2->converted.rotated.z = p_2->x * sin(rad(angle)) \
		+ p_2->converted.z * cos(rad(angle));
	}
	else
	{
		p_2->converted.rotated.x = p_2->x * cos(rad(angle)) \
		- p_2->converted.rotated.z * sin(rad(angle));
		p_2->converted.rotated.z = p_2->x * sin(rad(angle)) \
		+ p_2->converted.rotated.z * cos(rad(angle));
	}
}

void	rotate_y(t_point *point, double angle)
{
	t_point	*p_2;

	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			verify_rot_y(p_2, angle);
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

static void	change_angle(t_point *point)
{
	if (point->converted.rotated.rot_y <= -1)
		point->converted.rotated.rot_y = 359;
	if (point->converted.rotated.rot_y >= 360)
		point->converted.rotated.rot_y = 0;
}

void	rotation_y(t_point *point, t_fdf *fdf, int keycode)
{
	size_t	temp_angle;

	if (keycode == 65363)
		point->converted.rotated.rot_y--;
	if (keycode == 65361)
		point->converted.rotated.rot_y++;
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
