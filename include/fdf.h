/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:32:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/04 19:19:19 by lraffin          ###   ########.fr       */
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

typedef struct s_triangle
{
	t_point a;
	t_point b;
} t_triangle;

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
} t_mlx;

#endif
