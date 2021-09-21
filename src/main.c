/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/21 22:10:11 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso(t_map *map, t_point *a)
{
	(*a).x = ((*a).x - (*a).y) * cos(map->angle);
	(*a).y = (-(*a).z * map->z_multiplier)
		+ ((*a).x + (*a).y) * sin(map->angle);
}

void	usage(void)
{
	write(2, "usage: ./fdf [file]\n", 20);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_map	*map;

	errno = 0;
	if (ac != 2)
		usage();
	map = malloc(sizeof(t_map));
	if (!map)
		ft_terminate(ERR_MALLOC, map);
	ft_init(map);
	map->file = av[1];
	ft_parse(map);
	ft_fdf(map);
	free(map);
	return (0);
}
