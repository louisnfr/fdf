/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:50:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/26 14:19:21 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_parse(char *av)
{
	//t_point	**point;
	char	**tab;
	char	*line;
	int		nbline;
	int		fd;

	tab = NULL;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_terminate(ERR_MAP);
	nbline = 0;
	while (get_next_line(fd, &line))
	{
		*(tab[nbline]) = ft_split(line, ' ');
		nbline++;
	}

	close(fd);
	return (0);
}
