/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:29:51 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/17 20:59:14 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	int			is_last;
}				t_point;

typedef struct s_mouse
{
	char	mb_is_pressed;
	char	lb_is_pressed;
	char	rb_is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_map
{
	t_mouse		*mouse;
	t_point		**matrix;
	char		*file;
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			zoom;
	double		angle;
	int			x;
	int			y;
	int			z_multiplier;
	int			shift_x;
	int			shift_y;
	int			height;
	int			width;
}				t_map;

#endif
