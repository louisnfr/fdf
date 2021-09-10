/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:55:57 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/11 00:35:29 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_close(t_map *map)
{
	close(map->fd);
	if (map->fd < 0)
		ft_terminate(ERR_CLOSE, map);
}

void	ft_init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->angle = 0.8;
	map->z_multiplier = 1;
}

void	ft_mouse_init(t_mouse *mouse)
{
	mouse->mb_is_pressed = false;
	mouse->lb_is_pressed = false;
	mouse->rb_is_pressed = false;
	mouse->x = 0;
	mouse->y = 0;
	mouse->previous_x = 0;
	mouse->previous_y = 0;
}

int	ft_mouse_release(int key, int x, int y, void *param)
{
	t_map	*map;

	(void)x;
	(void)y;
	(void)key;
	map = param;
	map->mouse->mb_is_pressed = false;
	map->mouse->lb_is_pressed = false;
	map->mouse->rb_is_pressed = false;
	return (0);
}

int	ft_mouse_move(int x, int y, void *param)
{
	t_map	*map;

	map = param;
	map->mouse->previous_x = map->mouse->x;
	map->mouse->previous_y = map->mouse->y;
	map->mouse->x = x;
	map->mouse->y = y;
	if (map->mouse->mb_is_pressed)
	{
		map->shift_x += (x - map->mouse->previous_x);
		map->shift_y += (y - map->mouse->previous_y);
		ft_draw(map);
	}
	if (map->mouse->rb_is_pressed)
	{
		map->angle += (x - map->mouse->previous_x) * 0.002;
		map->angle += (y - map->mouse->previous_y) * 0.002;
		ft_draw(map);
	}
	return (0);
}
