/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:32:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/30 16:34:50 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <stdio.h>

typedef struct s_point
{
	int x;
	int y;
} t_point;

void	bresen_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1);

#endif
