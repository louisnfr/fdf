/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:32:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/25 18:41:17 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "error.h"
# include "colors.h"
# include "struct.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <errno.h>

# define HEIGHT 1080
# define WIDTH 1920

void	ft_fdf(char *av);
int		ft_parse(char *av);
void	ft_plot_line(void *mlx_ptr, void *win_ptr, t_point a, t_point b);
int		ft_deal_key(int key, void *param);
int		ft_mouse_move(int key, int x, int y, void *param);
void	ft_terminate(char *error_message);

#endif
