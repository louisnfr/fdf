/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:32:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/24 17:40:08 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#define WHITE 0xFFFFFF
#define GREEN 0x00FF59
#define BLUE 0x00B6FF
#define RED 0xFF0000

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_line
{
	t_point a;
	t_point b;
} t_line;

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
} t_mlx;

int deal_key(int key, void *param);
int mouse_move(int key, int x, int y, void *param);
void plot_line(void *mlx_ptr, void *win_ptr, t_point a, t_point b);


#endif
