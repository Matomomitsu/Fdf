/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 06:50:57 by mtomomit          #+#    #+#             */
/*   Updated: 2022/10/25 02:27:54 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		end_loop(fdf);
	if (keycode == KEY_A || keycode == KEY_D)
		handle_scale(keycode, fdf);
	if (keycode == KEY_W || keycode == KEY_S)
		handle_z(keycode, fdf);
	if (keycode == KEY_R)
		reset(fdf->i_point, fdf);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		rotation_x(fdf->i_point, fdf, keycode);
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		rotation_y(fdf->i_point, fdf, keycode);
	if (keycode == KEY_M || keycode == KEY_N)
		rotation_z(fdf->i_point, fdf, keycode);
	if (keycode == KEY_H || keycode == KEY_F)
		translation_x(fdf->i_point, fdf, keycode);
	if (keycode == KEY_T || keycode == KEY_G)
		translation_y(fdf->i_point, fdf, keycode);
	return (0);
}
