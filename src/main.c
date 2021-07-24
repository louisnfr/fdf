/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/24 20:14:36 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/libft.h"

int main(void)
{
	t_mlx *win = NULL;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, 1000, 1000, "my mlx");

	// mlx_key_hook(win->win_ptr, deal_key, win);
	// mlx_hook(win->win_ptr, 4, 0L, mouse_move, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
