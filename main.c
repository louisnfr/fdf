/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/24 16:53:07 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int deal_key(int key, void *param)
{
	t_mlx *win = param;
	if (key == 53)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (key == 49)
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	return (0);
}

void plot_line(void *mlx_ptr, void *win_ptr, t_point a, t_point b)
{
	int dx = ft_abs(b.x - a.x), sx = a.x < b.x ? 1 : -1;
	int dy = -ft_abs(b.y - a.y), sy = a.y < b.y ? 1 : -1;
	int err = dx + dy, e2;

	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, GREEN * a.x);
		if (a.x == b.x && a.y == b.y)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			a.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			a.y += sy;
		}
	}
}

int mouse_move(int key, int x, int y, void *param)
{
	t_mlx *win = param;
	t_line *line;
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

int main(int ac, char **av)
{
	t_mlx *win;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, 1000, 1000, "my mlx");

	

	mlx_key_hook(win->win_ptr, deal_key, win);
	mlx_hook(win->win_ptr, 4, 0L, mouse_move, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
