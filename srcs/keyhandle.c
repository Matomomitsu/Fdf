/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 06:50:57 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/23 04:10:09 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		end_loop(fdf);
	return (0);
}
