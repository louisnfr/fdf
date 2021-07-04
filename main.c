/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/04 20:33:57 by lraffin          ###   ########.fr       */
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
	return (0);
}

int mouse_move(int key, int x, int y, void *param)
{
	t_line *line = param;

	if (key == 1)
	{
		printf("key: %d\n", key);
		// printf("FIRST POINT:\nx: %d\ny: %d\n", x, y);
		if (key == 1)
		{
		printf("key: %d\n", key);
			// printf("SECOND POINT:\nx: %d\ny: %d\n", x, y);
		}
	}
	return (0);
}

// only works for lines with slope <= 1
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

	if (ft_abs(dx) > ft_abs(dy))
	{
		while (x < b.x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, GREEN);
			x++;
			if (P < 0)
				P = P + 2 * ft_abs(dy);
			else
			{
				P = P + 2 * ft_abs(dy) - 2 * ft_abs(dx);
				y++;
			}
		}
	}
	else
	{
		while (x < b.x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, GREEN);
			y++;
			if (P <= 0)
				P = P + 2 * ft_abs(dx);
			else
			{
				P = P + 2 * ft_abs(dx) - 2 * ft_abs(dy);
				x++;
			}
		}
	}
}

void plot_line(void *mlx_ptr, void *win_ptr, t_point a, t_point b)
{
	int dx = ft_abs(b.x - a.x), sx = a.x < b.x ? 1 : -1;
	int dy = -ft_abs(b.y - a.y), sy = a.y < b.y ? 1 : -1;
	int err = dx + dy, e2; /* error value e_xy */

	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, GREEN);
		if (a.x == b.x && a.y == b.y)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			a.x += sx;
		} /* e_xy+e_x > 0 */
		if (e2 <= dx)
		{
			err += dx;
			a.y += sy;
		} /* e_xy+e_y < 0 */
	}
}

int main(void)
{
	t_mlx *win;
	t_point A = {50, 50};
	t_point B = {900, 751};

	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, 1000, 1000, "my mlx");

	ft_line(win->mlx_ptr, win->win_ptr, A, B);
	plot_line(win->mlx_ptr, win->win_ptr, A, B);

	mlx_key_hook(win->win_ptr, deal_key, win);
	//mlx_mouse_hook(win->win_ptr, mouse_move, win);
	mlx_hook(win->win_ptr, 4, 0L, mouse_move, win);
	mlx_hook(win->win_ptr, 5, 0L, mouse_move, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
