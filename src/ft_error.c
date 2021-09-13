/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:56:45 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 21:50:52 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_terminate(char *error_message, t_map *map)
{
	if (errno == 0)
		ft_putendl_fd(error_message, 2);
	else
		perror(error_message);
	free(map);
	exit(EXIT_FAILURE);
}

void	free_all(t_map *map)
{
	if (!map)
		return ;
	free(map->mlx_ptr);
	free(map->img_ptr);
	free(map->win_ptr);
	free(map->mouse);
	free(map);
	map = NULL;
}
