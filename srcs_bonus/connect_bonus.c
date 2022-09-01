/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:58:26 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/16 22:53:58 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	connect_lines(t_point *point, t_point *point_below)
{
	while (point_below != NULL && point != NULL)
	{
		point->below = point_below;
		point_below = point_below->right;
		point = point->right;
	}
}

void	connect_list(t_point *point)
{
	t_point	*point_2;
	t_point	*point_5;

	point_2 = point;
	point_5 = point->below;
	while (point_5 != NULL && point_2 != NULL)
	{
		connect_lines(point_2->right, point_5->right);
		point_2 = point_2->below;
		point_5 = point_5->below;
	}
}
