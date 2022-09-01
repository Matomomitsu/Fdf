/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:40:15 by mtomomit          #+#    #+#             */
/*   Updated: 2022/08/16 22:38:38 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

t_point	*ft_pointnew(double x, double y, double z)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (new == NULL)
		return (NULL);
	new->right = NULL;
	new->below = NULL;
	new->x = x;
	new->y = y;
	new->z = z;
	new->converted.z = 0.0;
	new->converted.x = 0.0;
	new->converted.y = 0.0;
	return (new);
}

t_point	*ft_pointlast(t_point *point)
{
	if (!point)
		return (NULL);
	while (point)
	{
		if (point->below == NULL)
			break ;
		point = point->below;
	}
	return (point);
}

void	create_points(double x, double y, char **line, t_point *i_point)
{
	t_point	*point;
	int		i;

	if (i_point->right == NULL)
		i = 1;
	else
		i = 0;
	point = ft_pointlast(i_point);
	while (line[i] != NULL)
	{
		if (i == 0)
		{
			point->z = ft_atoi(line[0]);
			i++;
		}
		point->right = ft_pointnew(point->x + x, point->y, ft_atoi(line[i]));
		point = point->right;
		i++;
	}
	point = ft_pointlast(i_point);
	point->below = ft_pointnew(0.0, point->y + y, 0.0);
}

t_point	*ft_read_file(int fd, double x, double y)
{
	int		i;
	t_point	*inicial_point;
	char	**split_line;
	char	*line;

	inicial_point = NULL;
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		split_line = ft_split(line, ' ');
		free(line);
		check_line(inicial_point, split_line);
		if (inicial_point == NULL)
			inicial_point = ft_pointnew(0.0, 0.0, ft_atoi(split_line[0]));
		create_points(x, y, split_line, inicial_point);
		while (split_line[i] != NULL)
			free(split_line[i++]);
		free(split_line);
		line = get_next_line(fd);
	}
	free(line);
	return (inicial_point);
}
