/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_x_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 03:16:27 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/02 16:40:36 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	increase_x(t_point *point)
{
	t_point	*p_2;

	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			p_2->converted.translated.trans_x += 20;
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

void	decrease_x(t_point *point)
{
	t_point	*p_2;

	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			p_2->converted.translated.trans_x += -20;
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

void	translation_x(t_point *point, t_fdf *fdf, int keycode)
{
	size_t	temp_angle;

	if (keycode == KEY_H)
		increase_x(point);
	if (keycode == KEY_F)
		decrease_x(point);
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
