/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_scale_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:50:45 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/02 16:40:20 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	scale_z(t_point *point, double scale)
{
	t_point	*p_2;

	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			p_2->converted.z = p_2->converted.z + p_2->converted.z * scale;
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

void	increase_scale(t_point	*point)
{
	double	r;

	r = 0;
	if (point->right != NULL)
		r = point->right->x;
	if (point->below != NULL && r != 0)
		r = point->below->y;
	change_scale_x(point, r + r * 0.05);
	change_scale_y(point, r + r * 0.05);
	scale_z(point, 0.05);
}

void	decrease_scale(t_point	*point)
{
	double	r;

	r = 0;
	if (point->right != NULL)
		r = point->right->x;
	if (point->below != NULL && r != 0)
		r = point->below->y;
	change_scale_x(point, r - r * 0.05);
	change_scale_y(point, r - r * 0.05);
	scale_z(point, -0.05);
}

void	handle_scale(int keycode, t_fdf *fdf)
{
	revert_axis(fdf->i_point);
	if (keycode == KEY_A)
		increase_scale(fdf->i_point);
	if (keycode == KEY_D)
		decrease_scale(fdf->i_point);
	change_axis(fdf->i_point);
	rotate_x(fdf->i_point, fdf->i_point->converted.rotated.rot_x);
	rotate_y(fdf->i_point, fdf->i_point->converted.rotated.rot_y);
	rotate_z(fdf->i_point, fdf->i_point->converted.rotated.rot_z);
	clear_img(fdf);
	draw_fdf(fdf->i_point, fdf);
	render(fdf);
}
