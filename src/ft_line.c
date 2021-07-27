/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:37:43 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/27 15:57:53 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_line(t_mlx *mlx, t_point a, t_point b)
{
	int dx = FT_ABS(b.x - a.x), sx = a.x < b.x ? 1 : -1;
	int dy = -ft_abs(b.y - a.y), sy = a.y < b.y ? 1 : -1;
	int err = dx + dy, e2;

	while (1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, a.x, a.y, GREEN);
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
	x = 0;
	// t_point A = {500, 500, 5, BLUE};
	// t_point B = {750, 750, 0, BLUE};

	// ft_line(mlx, A, B);

	while (map->matrix[y])
	{
		x = 0;
		while (1)
		{
			if (map->matrix[y + 1])
				ft_line(mlx, map->matrix[y][x], map->matrix[y + 1][x]);
			if (!map->matrix[y][x].is_last)
				ft_line(mlx, map->matrix[y][x], map->matrix[y][x + 1]);
			if (map->matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	// while (map->matrix[y])
	// {
	// 	while (1)
	// 	{
	// 		if (map->matrix[y + 1])
	// 			ft_line(mlx, map->matrix[x][y], map->matrix[x][y + 1]);
	// 		break ;
	// 		x++;
	// 	}
	// 	break ;
	// 	y++;
	// }
}
