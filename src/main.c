/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/24 23:51:25 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/libft.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		fdf(av[1]);
	else
		ft_putstr("usage: ./fdf [file]\n");




	// t_mlx	*win;
	// int fd;
	// int i;
	// char *line;
	// char **split;

	// i = -1;
	// win = malloc(sizeof(t_mlx));
	// if (!win)
	// 	return (0);

	// if (ac == 2)
	// {
	// 	fd = open(av[1], O_RDONLY);
	// 	get_next_line(fd, &line);
	// 	split = ft_split(line, ' ');
	// 	while (split[++i])
	// 		printf("%d: %s\n", i, split[i]);
	// 	win->mlx_ptr = mlx_init();
	// 	win->win_ptr = mlx_new_window(win->mlx_ptr, 1000, 1000, "fdf");
	// 	mlx_key_hook(win->win_ptr, deal_key, win);
	// 	mlx_hook(win->win_ptr, 4, 0L, mouse_move, win);
	// 	mlx_loop(win->mlx_ptr);
	// }
	// free(win);
	return (0);
}
