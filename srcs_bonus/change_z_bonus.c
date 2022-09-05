/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_z_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:33:33 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/02 16:40:20 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	increase_z(t_point *point)
{
	t_point	*p_2;

	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			if (p_2->converted.z + p_2->z * 0.05 != 0)
				p_2->converted.z = p_2->converted.z + p_2->z * 0.05;
			else
				p_2->converted.z = p_2->converted.z + p_2->z * 0.1;
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

void	decrease_z(t_point *point)
{
	t_point	*p_2;

	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			if (p_2->converted.z - p_2->z * 0.05 != 0)
				p_2->converted.z = p_2->converted.z - p_2->z * 0.05;
			else
				p_2->converted.z = p_2->converted.z - p_2->z * 0.1;
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

void	handle_z(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_W)
		increase_z(fdf->i_point);
	if (keycode == KEY_S)
		decrease_z(fdf->i_point);
	rotate_x(fdf->i_point, fdf->i_point->converted.rotated.rot_x);
	rotate_y(fdf->i_point, fdf->i_point->converted.rotated.rot_y);
	rotate_z(fdf->i_point, fdf->i_point->converted.rotated.rot_z);
	clear_img(fdf);
	draw_fdf(fdf->i_point, fdf);
	render(fdf);
}
