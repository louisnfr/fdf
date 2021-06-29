/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:29:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/29 20:36:02 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void bresen_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
	int dy, dx, incrE, incrNE, d, x, y;

	dx = x1 - x0;
	dy = y1 - y0;
	d = 2 * dy - dx;
	incrE = 2 * dy;
	incrNE = 2 * (dy - dx);
	x = x0;
	y = y0;

	mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);

	while (x < x1)
	{
		if (d <= 0)
		{
			d += incrE;
			x++;
		}
		else
		{
			d += incrNE;
			x++;
			y++;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
	}
}
