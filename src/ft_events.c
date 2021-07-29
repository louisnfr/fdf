/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:35:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/29 20:53:54 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_move(t_map *map, int key)
{
	if (key == 123)
		map->shift_x -= 10;
	if (key == 124)
		map->shift_x += 10;
	if (key == 125)
		map->shift_y += 10;
	if (key == 126)
		map->shift_y -= 10;
}

void	ft_zoom(t_map *map, int key)
{
	if (key == 4)
		map->zoom -= 1;
	if (key == 5)
		map->zoom += 1;
}

int	ft_key_press(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move(map, key);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move(map, key);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	return (0);
}

int	ft_mouse_press(int key, int x, int y, void *param)
{
	t_map	*map;

	(void)x;
	(void)y;
	printf("mouse: %d\n", key);
	map = param;
	if (key == 4 || key == 5)
		ft_zoom(map, key);
	if (key == 3)
		map->mouse->mb_is_pressed = true;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	return (0);
}

int	ft_mouse_release(int key, int x, int y, void *param)
{
	t_map	*map;

	(void)x;
	(void)y;
	map = param;
	map->mouse->mb_is_pressed = false;
	return (0);
}
