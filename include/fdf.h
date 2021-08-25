/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:32:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/25 03:12:03 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "error.h"
# include "colors.h"
# include "struct.h"
# include "../minilibx-linux/mlx.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>

# define WIDTH 300
# define HEIGHT 240

typedef enum
{
	false,
	true
}	t_bool;

void	ft_fdf(t_map *map);
void	bresen(t_map *map, t_point a, t_point b);
void	ft_init(t_map *map);
void	ft_draw(t_map *map);
void	ft_parse(t_map *map);
void	ft_get_values(t_map *map);
void	ft_open(t_map *map);
void	ft_close(t_map *map);
void	ft_line(t_map *map, t_point a, t_point b);
int		ft_key_press(int key, void *param);
int		ft_mouse_press(int key, int x, int y, void *param);
int		ft_mouse_release(int key, int x, int y, void *param);
int		ft_mouse_move(int x, int y, void *param);
void	ft_mouse_init(t_mouse *mouse);
void	ft_terminate(char *error_message);

#endif

