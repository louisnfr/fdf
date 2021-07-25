/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:32:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/25 17:30:41 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "error.h"
# include "colors.h"
# include "struct.h"

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>


int		deal_key(int key, void *param);
int		mouse_move(int key, int x, int y, void *param);
void	plot_line(void *mlx_ptr, void *win_ptr, t_point a, t_point b);
int		ft_open_error();
int		ft_parse(char *av);
void	fdf(char *av);


#endif
