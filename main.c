/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/29 20:36:50 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;

	dx = x0 - x1;
	dy = y0 - y1;
	while (x0++ < x1)
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xFFFFFF);
	while (y0++ < y1)
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xFFFFFF);

}

int	main(void)
{
	void	*mlx_ptr0;
	void	*win_ptr0;
	void	*win_ptr1;

	mlx_ptr0 = mlx_init();
	win_ptr0 = mlx_new_window(mlx_ptr0, 500, 500, "my mlx");
	win_ptr1 = mlx_new_window(mlx_ptr0, 500, 500, "real mlx");

	ft_line(mlx_ptr0, win_ptr0, 100, 50, 250, 150);
	bresen_line(mlx_ptr0, win_ptr1, 100, 50, 250, 150);



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
