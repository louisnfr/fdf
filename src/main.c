/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:12:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/28 21:14:26 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	errno = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		ft_terminate(ERR_MALLOC);
	ft_init(map);
	if (ac == 2)
	{
		map->file = av[1];
		ft_parse(map);
		ft_fdf(map);
	}
	else
		ft_terminate(ERR_USAGE);
	free(map);
	return (0);
}
