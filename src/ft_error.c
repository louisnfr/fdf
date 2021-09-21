/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:56:45 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/21 22:17:15 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_terminate(char *error_message, t_map *map)
{
	if (errno == 0)
		ft_putendl_fd(error_message, 2);
	else
		perror(error_message);
	free_all(map);
	exit(EXIT_FAILURE);
}

void	free_matrix(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		free(map->matrix[i]);
	free(map->matrix);
}

void	free_all(t_map *map)
{
	if (!map)
		return ;
	if (map->matrix)
		free_matrix(map);
	if (map->mlx_ptr)
	{
		mlx_destroy_image(map->mlx_ptr, map->img_ptr);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
	}
	free(map->img);
	free(map->mouse);
	free(map);
	map = NULL;
}

void	ft_open(t_map *map)
{
	map->fd = open(map->file, O_RDONLY);
	if (map->fd < 0)
	{
		write(2, "incorrect map\n", 14);
		free(map);
		exit(EXIT_FAILURE);
	}
}

void	ft_map_error(t_map *map, char *line)
{
	write(2, "incorrect map\n", 14);
	ft_close(map);
	free(line);
	free(map);
	exit(EXIT_FAILURE);
}
