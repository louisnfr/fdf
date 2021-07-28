/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:42:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/28 20:53:48 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ft_fdf(t_map *map)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return ;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "fdf");
	mlx->zoom = 20;

	t_point A = {100, 100, 0, 0};
	t_point B = {300, 300, 0, 0};
	bresen(mlx, A, B);
	ft_line(mlx, A, B);
	//ft_draw(mlx, map);

	mlx_key_hook(mlx->win_ptr, ft_deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}
