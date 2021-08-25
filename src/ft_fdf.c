/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:42:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/25 02:56:21 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_controls(t_map *map)
{
	map->mouse = malloc(sizeof(t_mouse));
	ft_mouse_init(map->mouse);
	mlx_hook(map->win_ptr, 2, 0, ft_key_press, map);
	mlx_hook(map->win_ptr, 4, 0, ft_mouse_press, map);
	mlx_hook(map->win_ptr, 5, 0, ft_mouse_release, map);
	mlx_hook(map->win_ptr, 6, 0, ft_mouse_move, map);
}

void	ft_fdf(t_map *map)
{
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "fdf");
	map->zoom = 20;
	map->shift_x = 200;
	map->shift_y = 200;
	ft_draw(map);
	ft_controls(map);
	mlx_loop(map->mlx_ptr);
}
