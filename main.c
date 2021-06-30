/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/30 16:43:03 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// only works for lines with slope < 1
void	ft_line(void *mlx_ptr, void *win_ptr, t_point a, t_point b)
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
			P = P + 2 * dy - 2 *dx;
			x++;
		}
	}
}

int	main(void)
{
	void	*mlx_ptr0;
	void	*win_ptr0;
	t_point A = {125, 100};
	t_point B = {375, 25};

	mlx_ptr0 = mlx_init();
	win_ptr0 = mlx_new_window(mlx_ptr0, 500, 500, "my mlx");

	ft_line(mlx_ptr0, win_ptr0, A, B);

	mlx_loop(mlx_ptr0);
	return (0);
}

/*** DRAW FULL LINES ***/

	// ligne horizontale
	// x = -1;
	// while (++x < x_max)
	// 	mlx_pixel_put(mlx_ptr, win_ptr, x, 250, 0xFFFFFF);

	// ligne verticale
	// y = -1;
	// while (++y < y_max)
	// 	mlx_pixel_put(mlx_ptr, win_ptr, 250, y, 0xFFFFFF);

	// diagonale
	// x = -1;
	// while (++x < x_max)
	// 	mlx_pixel_put(mlx_ptr, win_ptr, x, x, 0xFFFFFF);

	// diagonale inverse
	// x = -1;
	// while (++x < x_max/2)
	// 	mlx_pixel_put(mlx_ptr, win_ptr, x_max - x, x, 0xFFFFFF);

/*** EVENTS ***/

	// mlx_key_hook(win_ptr, deal_key, (void *)0);

	// int	deal_key(int key, void *param)
	// {
	// 	printf("key_number: %d\n", key);
	// 	if (key == 53)
	// 		printf("ESC Key pressed\n");
	// 	return (0);
	// }
