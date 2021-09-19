/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:42:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/19 02:13:53 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_controls(t_map *map)
{
	map->mouse = malloc(sizeof(t_mouse));
	ft_mouse_init(map->mouse);
	mlx_hook(map->win_ptr, 2, 1L << 0, ft_key_press, map);
	mlx_hook(map->win_ptr, 4, 1L << 2, ft_mouse_press, map);
	mlx_hook(map->win_ptr, 5, 1L << 3, ft_mouse_release, map);
	mlx_hook(map->win_ptr, 6, 1L << 6, ft_mouse_move, map);
}

void	init_image(t_map *map)
{
	map->img = malloc(sizeof(t_image));
	if (!map->img)
	{
		free_all(map);
		exit(EXIT_FAILURE);
	}
	map->img_ptr = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->img->data = mlx_get_data_addr(map->img_ptr, &map->img->bpp,
					&map->img->length, &map->img->endian);
}

void	ft_fdf(t_map *map)
{
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "fdf");
	init_image(map);

	// my_mlx_pixel_put(map->img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	// mlx_loop(map->mlx_ptr);

	map->zoom = 1;
	map->shift_x = 200;
	map->shift_y = 200;
	ft_draw(map);
	ft_controls(map);
	mlx_loop(map->mlx_ptr);
}
