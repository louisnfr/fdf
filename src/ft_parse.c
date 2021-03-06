/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:50:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/21 22:04:57 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **args, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(args[i++]);
	free(args);
}

int	ft_count_width(int width, char *line)
{
	char	**split;
	int		w;
	int		i;

	i = -1;
	w = 0;
	split = ft_split(line, ' ');
	while (split[++i])
		w++;
	free_split(split, i);
	if (width == w)
		return (1);
	return (0);
}

void	ft_get_values(t_map *map)
{
	char	**split;
	char	*line;
	int		ret;
	int		i;

	ft_open(map);
	ret = get_next_line(map->fd, &line);
	map->height++;
	if (!line || line[0] == 0 || !ft_str_digit(line) || ret < 0)
		ft_map_error(map, line);
	i = -1;
	split = ft_split(line, ' ');
	free(line);
	while (split[++i])
		map->width++;
	free_split(split, i);
	while (get_next_line(map->fd, &line))
	{
		if (!ft_count_width(map->width, line) || !ft_str_digit(line))
			ft_map_error(map, line);
		map->height++;
		free(line);
	}
	free(line);
	ft_close(map);
}

void	ft_fill_matrix(t_map *map, char *line, int y)
{
	char	**values;
	int		x;

	values = ft_split(line, ' ');
	x = 0;
	while (values[x])
	{
		if (ft_atoi(values[x]) > 1000 || ft_atoi(values[x]) < -1000)
		{
			free_split(values, map->width);
			free_matrix(map);
			ft_map_error(map, line);
		}
		map->matrix[y][x].x = x;
		map->matrix[y][x].y = y;
		map->matrix[y][x].z = ft_atoi(values[x]);
		map->matrix[y][x].is_last = 0;
		free(values[x]);
		x++;
	}
	free(values);
	free(line);
	map->matrix[y][--x].is_last = 1;
}

void	ft_parse(t_map *map)
{
	char	*line;
	int		i;

	ft_get_values(map);
	ft_open(map);
	map->matrix = malloc(sizeof(t_point *) * (map->height + 1));
	i = -1;
	while (++i < map->height)
		map->matrix[i] = malloc(sizeof(t_point) * (map->width));
	map->matrix[i] = NULL;
	i = 0;
	while (get_next_line(map->fd, &line))
	{
		ft_fill_matrix(map, line, i);
		i++;
	}
	free(line);
	ft_close(map);
}
