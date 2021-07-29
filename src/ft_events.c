/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:35:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/29 16:18:29 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int ft_deal_key(int key, void *param)
{
	t_map *map = param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 123)
		map->shift_x -= 10;
	if (key == 124)
		map->shift_x += 10;
	if (key == 125)
		map->shift_y += 10;
	if (key == 126)
		map->shift_y -= 10;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	return (0);
}
