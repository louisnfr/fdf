/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:37:43 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/28 21:08:55 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_iso(t_point *a)
{
	(*a).x = ((*a).x - (*a).y) * cos(0.8);
	(*a).y = ((*a).x + (*a).y) * sin(0.8) - (*a).z;
}

void	bresen(t_mlx *mlx, t_point a, t_point b)
{
	float x_step;
	float y_step;
	int color;
	int max;

	// ZOOM
	a.x *= mlx->zoom;
	a.y *= mlx->zoom;
	b.x *= mlx->zoom;
	b.y *= mlx->zoom;

	// COLOR
	color = (a.z || b.z) ? RED : GREEN;

	// 3D
	ft_iso(&a);
	ft_iso(&b);

	// SHIFT
	a.x += 150;
	a.y += 150;
	b.x += 150;
	b.y += 150;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = FT_MAX(FT_ABS(x_step), FT_ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, a.x, a.y, color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	ft_line(t_mlx *mlx, t_point a, t_point b)
{
	a.x *= mlx->zoom;
	a.y *= mlx->zoom;
	b.x *= mlx->zoom;
	b.y *= mlx->zoom;

	int dx = FT_ABS(b.x - a.x), sx = a.x < b.x ? 1 : -1;
	int dy = -ft_abs(b.y - a.y), sy = a.y < b.y ? 1 : -1;
	int err = dx + dy, e2;
	int color;

	while (1)
	{
		color = (a.z || b.z) ? RED : GREEN;
		ft_iso(&a);
		//ft_iso(&b);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			a.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			a.y += sy;
		}
	}
}

void	ft_draw(t_mlx *mlx, t_map *map)
{
	int x;
	int y;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (1)
		{
			if (map->matrix[y + 1])
				bresen(mlx, map->matrix[y][x], map->matrix[y + 1][x]);
			if (!map->matrix[y][x].is_last)
				bresen(mlx, map->matrix[y][x], map->matrix[y][x + 1]);
			if (map->matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
