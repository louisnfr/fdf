/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/29 01:58:18 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x_max;
	int		y_max;
	int		x;
	int		y;

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

	mlx_loop(mlx_ptr);
	return (0);
}
