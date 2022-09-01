/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_axis_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:32:36 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/16 22:53:46 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	change_axis(t_point *point)
{
	t_point	*p_2;
	double	max_x;
	double	max_y;

	get_max(point, &max_x, &max_y);
	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			p_2->converted.rotated.x = p_2->x - max_x / 2;
			p_2->converted.rotated.y = p_2->y - max_y / 2;
			p_2->x = p_2->x - max_x / 2;
			p_2->y = p_2->y - max_y / 2;
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}

void	revert_axis(t_point *point)
{
	t_point	*p_2;
	double	max_x;
	double	max_y;

	get_max(point, &max_x, &max_y);
	p_2 = point;
	while (p_2 != NULL)
	{
		while (p_2 != NULL)
		{
			p_2->converted.rotated.x = p_2->x + max_x;
			p_2->converted.rotated.y = p_2->y + max_y;
			p_2->x = p_2->x + max_x;
			p_2->y = p_2->y + max_y;
			p_2 = p_2->right;
		}
		p_2 = point->below;
		point = point->below;
	}
}
