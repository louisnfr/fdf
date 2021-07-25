/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:29:51 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/25 17:31:01 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
} t_mlx;

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

#endif
