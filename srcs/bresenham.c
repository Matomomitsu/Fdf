/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 06:23:49 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/12 21:27:14 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	lower_slope(t_line *l, t_fdf *fdf, int dx, int dy)
{
	int	d;
	int	i;
	int	o;

	i = -1;
	if (l->start_y > l->end_y)
		o = -1;
	else
		o = 1;
	my_pixel_put(fdf, l->start_x, l->start_y, 0x00FFFFFF);
	d = (2 * abs(dy)) - abs(dx);
	while (++i < abs(dx))
	{
		l->start_x = l->start_x + 1;
		if (d < 0)
			d = d + (2 * abs(dy));
		else
		{
			l->start_y = l->start_y + o;
			d = d + (2 * abs(dy)) - (2 * abs(dx));
		}
		my_pixel_put(fdf, l->start_x, l->start_y, 0x00FFFFFF);
	}
}

void	bigger_slope(t_line *l, t_fdf *fdf, int dx, int dy)
{
	int	d;
	int	i;
	int	o;

	i = -1;
	if (l->start_y > l->end_y)
		o = -1;
	else
		o = 1;
	my_pixel_put(fdf, l->start_x, l->start_y, 0x00FF0000);
	d = (2 * abs(dx) - abs(dy));
	while (++i < abs(dy))
	{
		l->start_y = l->start_y + o;
		if (d < 0)
			d = d + (2 * abs(dx));
		else
		{
			l->start_x = l->start_x + 1;
			d = d + (2 * abs(dx)) - (2 * abs(dy));
		}
		my_pixel_put(fdf, l->start_x, l->start_y, 0x00FF0000);
	}
}

void	drawline(t_line *line, t_fdf *fdf, int dx, int dy)
{
	if (abs(dx) > abs(dy))
		lower_slope(line, fdf, dx, dy);
	else
		bigger_slope(line, fdf, dx, dy);
}

void	bresenham_r(t_point *point, t_fdf *fdf)
{
	t_point	*right;
	t_line	*line;

	right = point->right;
	line = malloc(sizeof(t_line));
	if (point->converted.x < right->converted.x)
	{
		line->start_x = point->converted.x;
		line->end_x = right->converted.x;
		line->start_y = point->converted.y;
		line->end_y = right->converted.y;
	}
	else
	{
		line->end_x = point->converted.x;
		line->start_x = right->converted.x;
		line->end_y = point->converted.y;
		line->start_y = right->converted.y;
	}
	drawline(line, fdf, line->end_x - line->start_x,
		line->end_y - line->start_y);
	free(line);
}

void	bresenham_b(t_point *point, t_fdf *fdf)
{
	t_point	*below;
	t_line	*line;

	below = point->below;
	line = malloc(sizeof(t_line));
	if (point->converted.x < below->converted.x)
	{
		line->start_x = point->converted.x;
		line->end_x = below->converted.x;
		line->start_y = point->converted.y;
		line->end_y = below->converted.y;
	}
	else
	{
		line->end_x = point->converted.x;
		line->start_x = below->converted.x;
		line->end_y = point->converted.y;
		line->start_y = below->converted.y;
	}
	drawline(line, fdf, line->end_x - line->start_x,
		line->end_y - line->start_y);
	free(line);
}
