/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:37:43 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/28 18:36:28 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_iso(t_map *map, t_point *a)
{
	(*a).x = ((*a).x - (*a).y) * cos(map->angle);
	(*a).y = (-(*a).z * map->z_multiplier)
		+ ((*a).x + (*a).y) * sin(map->angle);
}

void	ft_adjust_zoom(t_point *a, t_point *b, t_map *map)
{
	(*a).x *= map->zoom;
	(*a).y *= map->zoom;
	(*b).x *= map->zoom;
	(*b).y *= map->zoom;
}

void	ft_adjust_shift(t_point *a, t_point *b, t_map *map)
{
	(*a).x += map->shift_x;
	(*a).y += map->shift_y;
	(*b).x += map->shift_x;
	(*b).y += map->shift_y;
}

void	bresen(t_map *map, t_point a, t_point b)
{
	float	x_step;
	float	y_step;
	int		color;
	int		max;

	ft_adjust_zoom(&a, &b, map);
	if (a.z || b.z)
		color = RED;
	else
		color = BLUE;
	ft_iso(map, &a);
	ft_iso(map, &b);
	ft_adjust_shift(&a, &b, map);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
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
	int	x;
	int	y;

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
}
