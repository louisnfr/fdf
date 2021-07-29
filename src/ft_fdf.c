/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:42:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/29 16:14:48 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ft_fdf(t_map *map)
{
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "fdf");
	map->zoom = 20;
	map->shift_x = 150;
	map->shift_y = 150;

	ft_draw(map);

	mlx_key_hook(map->win_ptr, ft_deal_key, map);
	mlx_loop(map->mlx_ptr);
}
