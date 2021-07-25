/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:35:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/25 17:14:21 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int deal_key(int key, void *param)
{
	t_mlx *win = param;
	if (key == 53)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (key == 49)
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	return (0);
}

int mouse_move(int key, int x, int y, void *param)
{
	t_mlx *win = param;
	t_point o = {500, 500};
	t_point p;

	if (key == 1)
	{
		p.x = x;
		p.y = y;
		plot_line(win->mlx_ptr, win->win_ptr, o, p);
	}
	return (0);
}
