/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 06:50:57 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/23 04:09:57 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		end_loop(fdf);
	if (keycode == 97 || keycode == 100)
		handle_scale(keycode, fdf);
	if (keycode == 119 || keycode == 115)
		handle_z(keycode, fdf);
	if (keycode == 114)
		reset(fdf->i_point, fdf);
	if (keycode == 65362 || keycode == 65364)
		rotation_x(fdf->i_point, fdf, keycode);
	if (keycode == 65363 || keycode == 65361)
		rotation_y(fdf->i_point, fdf, keycode);
	if (keycode == 109 || keycode == 110)
		rotation_z(fdf->i_point, fdf, keycode);
	if (keycode == 102 || keycode == 104)
		translation_x(fdf->i_point, fdf, keycode);
	if (keycode == 116 || keycode == 103)
		translation_y(fdf->i_point, fdf, keycode);
	return (0);
}
