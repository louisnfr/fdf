/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/29 02:21:50 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

int	deal_key(int key, void *param)
{
	printf("key_number: %d\n", key);
	if (key == 53)
		printf("ESC Key pressed\n");
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x_max;
	int		y_max;
	float		x;
	float		y;

	x_max = 500;
	y_max = 500;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, x_max, y_max, "test MLX 1");

	// ligne horizontale
	x = -1;
	while (++x < x_max)
		mlx_pixel_put(mlx_ptr, win_ptr, x, 250, 0xFFFFFF);

	// ligne verticale
	y = -1;
	while (++y < y_max)
		mlx_pixel_put(mlx_ptr, win_ptr, 250, y, 0xFFFFFF);

	// diagonale
	x = -1;
	while (++x < x_max)
		mlx_pixel_put(mlx_ptr, win_ptr, x, x, 0xFFFFFF);

	// diagonale inverse
	x = -1;
	while (++x < x_max)
		mlx_pixel_put(mlx_ptr, win_ptr, x_max - x, x, 0xFFFFFF);

	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
