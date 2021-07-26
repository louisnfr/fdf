/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:50:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/26 19:15:40 by lraffin          ###   ########.fr       */
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

void	ft_fill_matrix(int *m_line, char *line)
{
	char **values;
	int i;

	values = ft_split(line, ' ');
	i = 0;
	while (values[i])
	{
		m_line[i] = ft_atoi(values[i]);
		free(values[i]);
		i++;
	}
	free(values);
}

void	ft_parse(t_map *map)
{
	char	*line;
	int		i;

	ft_get_values(map);
	ft_open(map);
	map->matrix = malloc(sizeof(int *) * (map->height + 1));
	i = -1;
	while (++i <= map->height)
		map->matrix[i] = malloc(sizeof(int) * (map->width + 1));
	i = 0;
	while (get_next_line(map->fd, &line))
	{
		ft_fill_matrix(map->matrix[i], line);
		free(line);
		i++;
	}
	map->matrix[i] = NULL;
	ft_close(map);
}
