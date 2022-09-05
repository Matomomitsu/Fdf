/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:31:02 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/02 16:40:38 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

static void	verify_rot_z(t_point *p_2, double angle)
{
	double	temp_x;
	double	temp_y;

	temp_x = p_2->converted.rotated.x * cos(rad(angle)) \
	- p_2->converted.rotated.y * sin(rad(angle));
	temp_y = p_2->converted.rotated.x * sin(rad(angle)) \
	+ p_2->converted.rotated.y * cos(rad(angle));
	p_2->converted.rotated.x = temp_x;
	p_2->converted.rotated.y = temp_y;
}

void	rotate_z(t_point *point, double angle)
{
	t_point	*p_2;

	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			verify_rot_z(p_2, angle);
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

static void	change_angle(t_point *point)
{
	if (point->converted.rotated.rot_z <= -1)
		point->converted.rotated.rot_z = 359;
	if (point->converted.rotated.rot_z >= 360)
		point->converted.rotated.rot_z = 0;
}

void	rotation_z(t_point *point, t_fdf *fdf, int keycode)
{
	size_t	temp_angle;

	if (keycode == KEY_M)
		point->converted.rotated.rot_z++;
	if (keycode == KEY_N)
		point->converted.rotated.rot_z--;
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
