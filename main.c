/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/01 16:49:30 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

// only works for lines with slope < 1
void ft_line(void *mlx_ptr, void *win_ptr, t_point a, t_point b)
{
	int x;
	int y;
	int dx;
	int dy;
	int P;

	x = a.x;
	y = a.y;
	dx = b.x - a.x;
	dy = b.y - a.y;
	P = 2 * dy - dx;

	while (x < b.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		x++;
		if (P <= 0)
			P = P + 2 * dy;
		else
		{
			P = P + 2 * dy - 2 * dx;
			y++;
		}
	}
}

int main(void)
{
	void *mlx_ptr0;
	void *win_ptr0;
	t_point A = {150, 50};
	t_point B = {200, 300};

	mlx_ptr0 = mlx_init();
	win_ptr0 = mlx_new_window(mlx_ptr0, 500, 500, "my mlx");

	ft_line(mlx_ptr0, win_ptr0, A, B);

	mlx_loop(mlx_ptr0);
	return (0);
}
