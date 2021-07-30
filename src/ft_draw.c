/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:37:43 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/30 16:47:04 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_iso(t_map *map, t_point *a)
{
	(*a).x = ((*a).x - (*a).y) * cos(map->angle);
	(*a).y = ((*a).x + (*a).y) * sin(map->angle) - (*a).z;
}

void	bresen(t_map *map, t_point a, t_point b)
{
	float x_step;
	float y_step;
	int color;
	int max;

	a.x *= map->zoom;
	a.y *= map->zoom;
	b.x *= map->zoom;
	b.y *= map->zoom;
	color = (a.z || b.z) ? RED : BLUE;
	ft_iso(map, &a);
	ft_iso(map, &b);
	a.x += map->shift_x;
	a.y += map->shift_y;
	b.x += map->shift_x;
	b.y += map->shift_y;
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = FT_MAX(FT_ABS(x_step), FT_ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, a.x, a.y, color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	ft_draw(t_map *map)
{
	int x;
	int y;

	y = 0;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	while (map->matrix[y])
	{
		x = 0;
		while (1)
		{
			if (map->matrix[y + 1])
				bresen(map, map->matrix[y][x], map->matrix[y + 1][x]);
			if (!map->matrix[y][x].is_last)
				bresen(map, map->matrix[y][x], map->matrix[y][x + 1]);
			if (map->matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	// mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}
