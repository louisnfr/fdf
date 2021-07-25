/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:42:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/25 17:14:26 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void fdf(char *av)
{
	t_mlx	*win;
	int		fd;
	int		i;
	int		nbline;
	char	*line;
	char	**split;

	win = malloc(sizeof(t_mlx));
	if (!win)
		return ;
	nbline = -1;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, 750, 750, "fdf");

	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nbline++;
		i = -1;
		split = ft_split(line, ' ');
		while (split[++i])
		{
		//	printf("{%d, %d, %d}\n", i, nbline, ft_atoi(split[i]));
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, i * 50, nbline * 50, GREEN);
		}
	}
	// mlx_key_hook(win->win_ptr, deal_key, win);
	// mlx_hook(win->win_ptr, 4, 0L, mouse_move, win);
	mlx_loop(win->mlx_ptr);
}
