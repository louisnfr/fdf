/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:35:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/17 16:53:33 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_map *map, int key)
{
	if (key == 65361)
		map->shift_x -= 10;
	if (key == 65363)
		map->shift_x += 10;
	if (key == 65364)
		map->shift_y += 10;
	if (key == 65362)
		map->shift_y -= 10;
	ft_draw(map);
}

void	ft_zoom(t_map *map, int key)
{
	if (key == 4)
		map->zoom -= 1;
	if (key == 5)
		map->zoom += 1;
	ft_draw(map);
}

void	ft_scale(t_map *map, int key)
{
	if (key == 119)
		map->z_multiplier += 1;
	if (key == 115)
		map->z_multiplier -= 1;
	ft_draw(map);
}

int	ft_key_press(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == 65307)
	{
		mlx_destroy_display();
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		free_all(map);
		exit(EXIT_SUCCESS);
	}
	if (key == 65361 || key == 65362 || key == 65363 || key == 65364)
		ft_move(map, key);
	if (key == 115 || key == 119)
		ft_scale(map, key);
	return (0);
}

int	ft_mouse_press(int key, int x, int y, void *param)
{
	t_map	*map;

	(void)x;
	(void)y;
	map = param;
	if (key == 4 || key == 5)
		ft_zoom(map, key);
	if (key == 3)
		map->mouse->mb_is_pressed = true;
	if (key == 2)
		map->mouse->rb_is_pressed = true;
	return (0);
}
