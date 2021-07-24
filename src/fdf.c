/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:42:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/25 00:00:49 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/libft.h"

void fdf(char *av)
{
	int		fd;
	int		i;
	int		nbline;
	char	*line;
	char	**split;

	nbline = -1;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nbline++;
		i = -1;
		split = ft_split(line, ' ');
		while (split[++i])
		{
			printf("point[%d] = {%d, %d}\n", i, nbline, ft_atoi(split[i]));
		}
	}
}
