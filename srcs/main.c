/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:51:13 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/16 22:38:31 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	render(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image.img, 0, 0);
	return (0);
}

void	init_fdf(t_fdf *fdf, t_point *point)
{
	fdf->i_point = point;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1200, 900, "FDF");
	fdf->image.img = mlx_new_image(fdf->mlx, 1200, 900);
	fdf->image.addr = mlx_get_data_addr(fdf->image.img,
			&fdf->image.bits_per_pixel,
			&fdf->image.line_length, &fdf->image.endian);
}

t_point	*create_list(int fd)
{
	t_point	*point;
	t_point	*last;

	point = NULL;
	point = ft_read_file(fd, 20, 20);
	if (point == NULL)
		ft_error(5);
	last = ft_pointlast(point);
	ft_pointdellast(last, point);
	connect_list(point);
	get_scale(point);
	change_z(point);
	return (point);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_fdf		fdf;
	t_point		*point;

	check_args(argc, argv);
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd < 0)
		ft_error(4);
	point = NULL;
	point = create_list(fd);
	close(fd);
	init_fdf(&fdf, point);
	draw_fdf(point, &fdf);
	mlx_expose_hook(fdf.win, &render, &fdf);
	mlx_key_hook(fdf.win, key_handle, &fdf);
	mlx_hook(fdf.win, 17, 1L << 24, end_loop, &fdf);
	mlx_loop(fdf.mlx);
	destroy_all(&fdf);
	while (point->below != NULL)
		free_points(point);
	free_first_line(point);
	return (0);
}
