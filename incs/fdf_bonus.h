/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:31:10 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/02 16:41:34 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "keys.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_translated
{
	double	trans_x;
	double	trans_y;
}	t_translated;

typedef struct s_rotated
{
	double		x;
	double		y;
	double		z;
	short int	rot_x;
	short int	rot_y;
	short int	rot_z;
}	t_rotated;

typedef struct s_converted
{
	t_rotated		rotated;
	t_translated	translated;
	double			x;
	double			y;
	double			z;
}	t_converted;

typedef struct s_point
{
	double			x;
	double			y;
	double			z;
	struct s_point	*right;
	struct s_point	*below;
	t_converted		converted;
}	t_point;

typedef struct s_fdf
{
	t_image		image;
	void		*mlx;
	void		*win;
	t_point		*i_point;
}	t_fdf;

typedef struct s_line
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
}	t_line;

// Bresenham_bonus.c
void	lower_slope(t_line *l, t_fdf *fdf, int dx, int dy);
void	bigger_slope(t_line *l, t_fdf *fdf, int dx, int dy);
void	drawline(t_line *line, t_fdf *fdf, int dx, int dy);
void	bresenham_r(t_point *point, t_fdf *fdf);
void	bresenham_b(t_point *point, t_fdf *fdf);
// Close_bonus.c
void	ft_pointdellast(t_point *point, t_point *point_2);
void	free_points(t_point *point);
void	free_first_line(t_point *point);
void	destroy_all(t_fdf *fdf);
int		end_loop(t_fdf *fdf);
// Connect_bonus.c
void	connect_list(t_point *point);
void	connect_lines(t_point *point, t_point *point_below);
// Convert_bonus.c
void	get_scale(t_point	*point);
void	change_scale_x(t_point *point, double r);
void	change_scale_y(t_point *point, double r);
// Draw_bonus.c
void	my_pixel_put(t_fdf *fdf, int x, int y, int color);
void	draw_fdf(t_point *point, t_fdf *fdf);
void	draw_columns(t_point *point, t_point *point_below, t_fdf *fdf);
void	draw_lines(t_point *point, t_point *point_right, t_fdf *fdf);
void	get_max(t_point *point, double *max_x, double *max_y);
// Error_bonus.c
void	check_args(int argc, char **argv);
void	ft_error(int error_num);
void	check_line(t_point *point, char **split_line);
// Isometric_bonus.c
double	rad(double num);
int		abs(int num);
void	convert_point(t_point *point, double max_x, double max_y);
// Keyhandle_bonus.c
int		key_handle(int keycode, t_fdf *fdf);
// Read_bonus.c
t_point	*ft_read_file(int fd, double x, double y);
void	create_points(double x, double y, char **line, t_point *i_point);
t_point	*ft_pointlast(t_point *point);
t_point	*ft_pointnew(double x, double y, double z);
// Transformation_bonus.c
void	change_z(t_point *point);
double	check_max_min_z(t_point *point, double *max_z);
// Main_bonus.c
int		render(t_fdf *fdf);
// Clear_bonus.c
void	clear_img(t_fdf *fdf);
// Change_scale_bonus.c
void	increase_scale(t_point	*point);
void	decrease_scale(t_point	*point);
void	handle_scale(int keycode, t_fdf *fdf);
// Change_z_bonus.c
void	decrease_z(t_point *point);
void	increase_z(t_point *point);
void	init_converted_z(t_point *point);
void	handle_z(int keycode, t_fdf *fdf);
// Reset_bonus.c
void	reset(t_point *point, t_fdf *fdf);
// Rotate_x_bonus.c
void	rotation_x(t_point *point, t_fdf *fdf, int keycode);
void	rotate_x(t_point *point, double angle);
// Rotate_y_bonus.c
void	rotation_y(t_point *point, t_fdf *fdf, int keycode);
void	rotate_y(t_point *point, double angle);
// Rotate_z_bonus.c
void	rotation_z(t_point *point, t_fdf *fdf, int keycode);
void	rotate_z(t_point *point, double angle);
// Change_axis_bonus.c
void	change_axis(t_point *point);
void	revert_axis(t_point *point);
// Translation_x_bonus.c
void	translation_x(t_point *point, t_fdf *fdf, int keycode);
// Translation_y_bonus.c
void	translation_y(t_point *point, t_fdf *fdf, int keycode);

#endif
