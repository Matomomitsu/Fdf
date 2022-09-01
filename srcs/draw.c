/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:41:00 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/12 21:27:38 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	get_max(t_point *point, double *max_x, double *max_y)
{
	while (point->right != NULL)
		point = point->right;
	*max_x = point->x;
	while (point->below != NULL)
		point = point->below;
	*max_y = point->y;
}

void	draw_lines(t_point *point, t_point *point_right, t_fdf *fdf)
{
	double	max_x;
	double	max_y;

	get_max(point, &max_x, &max_y);
	convert_point(point, max_x, max_y);
	while (point_right != NULL)
	{
		convert_point(point_right, max_x, max_y);
		bresenham_r(point, fdf);
		point = point->right;
		point_right = point_right->right;
	}
}

void	draw_columns(t_point *point, t_point *point_below, t_fdf *fdf)
{
	while (point_below != NULL)
	{
		bresenham_b(point, fdf);
		point = point->below;
		point_below = point_below->below;
	}
}

void	draw_fdf(t_point *point, t_fdf *fdf)
{
	t_point	*point_2;
	t_point	*point_3;
	t_point	*point_4;

	point_2 = point;
	point_3 = point->below;
	point_4 = point->right;
	while (point_2 != NULL)
	{
		draw_lines(point_2, point_4, fdf);
		point_2 = point_2->below;
		if (point_2 != NULL)
			point_4 = point_2->right;
	}
	point_2 = point;
	while (point_2 != NULL)
	{
		draw_columns(point_2, point_3, fdf);
		point_2 = point_2->right;
		if (point_2 != NULL)
			point_3 = point_2->below;
	}
}

void	my_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x <= 1200 && y <= 900 && y >= 0 && x >= 0)
	{
		dst = fdf->image.addr + (y * fdf->image.line_length + x
				* (fdf->image.bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
	}
}
