/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:56:45 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/17 12:35:17 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_terminate(char *error_message, t_map *map)
{
	if (errno == 0)
		ft_putendl_fd(error_message, 2);
	else
		perror(error_message);
	free_all(map);
	exit(EXIT_FAILURE);
}

void	free_all(t_map *map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	// free(map->mlx_ptr);
	// free(map->img_ptr);
	// free(map->win_ptr);
	// free(map->mouse);
	while (++i < map->height)
		free(map->matrix[i]);
	free(map->matrix);
	free(map);
	map = NULL;
}
