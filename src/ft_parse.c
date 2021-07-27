/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:50:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/27 15:56:39 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_close(t_map *map)
{
	close(map->fd);
	if (map->fd < 0)
		ft_terminate(ERR_CLOSE);
}

void	ft_open(t_map *map)
{
	map->fd = open(map->file, O_RDONLY);
	if (map->fd < 0)
		ft_terminate(ERR_MAP);
}

void	ft_get_values(t_map *map)
{
	char	**split;
	char	*line;
	int		i;

	ft_open(map);
	get_next_line(map->fd, &line);
	map->height++;
	i = -1;
	split = ft_split(line, ' ');
	while (split[++i])
		map->width++;
	while (get_next_line(map->fd, &line))
		map->height++;
	free(line);
}

void	ft_fill_matrix(t_map *map, char *line, int y)
{
	char **values;
	int i;

	(void)map;
	(void)y;
	values = ft_split(line, ' ');
	//free(line);
	i = 0;
	while (values[i])
	{
		map->matrix[y][i].x = i;
		map->matrix[y][i].y = y;
		map->matrix[y][i].z = ft_atoi(values[i]);
		map->matrix[y][i].is_last = 0;
		//free(values[i]);
		i++;
	}
	map->matrix[y][--i].is_last = 1;
	//free(values);
}

void	ft_parse(t_map *map)
{
	char	*line;
	int		i;

	ft_get_values(map);
	ft_open(map);
	map->matrix = malloc(sizeof(t_point *) * (map->height + 1));
	i = -1;
	while (++i <= map->height)
		map->matrix[i] = malloc(sizeof(t_point) * (map->width + 1));
	i = 0;
	while (get_next_line(map->fd, &line))
	{
		ft_fill_matrix(map, line, i);
		free(line);
		i++;
	}


	free(line);
	ft_close(map);
}
