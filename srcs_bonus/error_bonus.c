/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:59:41 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/16 22:54:08 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

void	check_args(int argc, char **argv)
{
	char	**split_string;
	int		i;

	if (argc < 2)
		ft_error(1);
	if (argc > 2)
		ft_error(2);
	i = 0;
	split_string = ft_split(argv[1], '.');
	while (split_string[i] != NULL)
		i++;
	i--;
	if (ft_strncmp(split_string[i], "fdf", 4) != 0)
	{
		i++;
		while (i >= 0)
			free(split_string[i--]);
		free(split_string);
		ft_error(3);
	}
	i++;
	while (i >= 0)
		free(split_string[i--]);
	free(split_string);
}

void	ft_error(int error_num)
{
	if (error_num == 1)
		ft_putstr_fd("File missing\n", 1);
	if (error_num == 2)
		ft_putstr_fd("More then one argument\n", 1);
	if (error_num == 3)
		ft_putstr_fd("Wrong type of file\n", 1);
	if (error_num == 4)
		ft_putstr_fd("Cannot read file\n", 1);
	if (error_num == 5)
		ft_putstr_fd("Empty file\n", 1);
	if (error_num == 6)
		ft_putstr_fd("Unexpected argument in file\n", 1);
	exit(0);
}

void	check_line(t_point *point, char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
		if ((line[i][0] < 48 && line[i][0] != '-' && line[i][0]
			!= '+' && line[i][0] != '\n') || line[i][0] > 57)
		{
			if (point != NULL)
			{
				while (point->below != NULL)
					free_points(point);
				free_first_line(point);
			}
			i = 0;
			while (line[i] != NULL)
				free(line[i++]);
			free(line);
			ft_error(6);
		}
		i++;
	}
}
