/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:55:57 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/03 23:53:30 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
