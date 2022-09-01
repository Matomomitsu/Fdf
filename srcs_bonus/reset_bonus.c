/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:24:24 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/23 03:47:26 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	reset_z(t_point *point)
{
	t_point	*p_2;

	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			p_2->converted.z = p_2->z;
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

void	reset_rot(t_point *point)
{
	point->converted.rotated.rot_x = 0;
	point->converted.rotated.rot_y = 0;
	point->converted.rotated.rot_z = 0;
}

void	reset_translation(t_point *point)
{
	t_point	*p_2;

	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			p_2->converted.translated.trans_x = 0.0;
			p_2->converted.translated.trans_y = 0.0;
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

void	reset(t_point *point, t_fdf *fdf)
{
	revert_axis(point);
	reset_z(point);
	change_scale_x(point, 20);
	change_scale_y(point, 20);
	get_scale(point);
	change_axis(point);
	rotate_x(point, 0);
	rotate_y(point, 0);
	rotate_z(point, 0);
	reset_translation(point);
	reset_rot(point);
	clear_img(fdf);
	draw_fdf(fdf->i_point, fdf);
	render(fdf);
}
