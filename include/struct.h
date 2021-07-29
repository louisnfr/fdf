/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:29:51 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/29 16:06:39 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	int			color;
	int			is_last;
}				t_point;

typedef struct s_map
{
	char		*file;
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	t_point		**matrix;
	int			zoom;
	int			x;
	int			y;
	int			shift_x;
	int			shift_y;
	int			height;
	int			width;
}				t_map;

#endif
