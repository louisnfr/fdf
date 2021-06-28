/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/29 01:25:23 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "minilibx_macos/mlx_int.h"
#include "minilibx_macos/mlx_new_window.h"

int	main()
{
	void	*mlx_ptr;
	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, 500, 500, "test MLX");
	return (0);
}
