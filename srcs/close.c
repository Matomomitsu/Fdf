/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 06:51:54 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/12 21:27:29 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	end_loop(t_fdf *fdf)
{
	mlx_loop_end(fdf->mlx);
	return (0);
}

void	destroy_all(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->image.img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
}

void	free_points(t_point *point)
{
	t_point	*last;
	t_point	*temp_point;
	t_point	*temp_point_2;
	t_point	*last_2;

	last = ft_pointlast(point);
	temp_point = ft_pointlast(point);
	last_2 = point;
	while (last_2->below->below != NULL)
		last_2 = last_2->below;
	while (last->right != NULL)
		last = last->right;
	while (temp_point != last)
	{
		temp_point_2 = temp_point->right;
		if (temp_point->below != NULL)
			temp_point->below = NULL;
		free(temp_point);
		temp_point = NULL;
		temp_point = temp_point_2;
	}
	free(temp_point);
	temp_point = NULL;
	last_2->below = NULL;
}

void	free_first_line(t_point *point)
{
	t_point	*last;
	t_point	*temp_point;
	t_point	*temp_point_2;

	last = ft_pointlast(point);
	temp_point = ft_pointlast(point);
	while (last->right != NULL)
		last = last->right;
	while (temp_point != last)
	{
		temp_point_2 = temp_point->right;
		if (temp_point->below != NULL)
			temp_point->below = NULL;
		free(temp_point);
		temp_point = NULL;
		temp_point = temp_point_2;
	}
	free(temp_point);
	temp_point = NULL;
}

void	ft_pointdellast(t_point *point, t_point *point_2)
{
	if (!point_2 || !point)
		return ;
	while (point_2)
	{
		if (point_2->below == point)
			break ;
		point_2 = point_2->below;
	}
	free(point);
	point = NULL;
	point_2->below = NULL;
}
