/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:56:45 by lraffin           #+#    #+#             */
/*   Updated: 2021/07/25 18:08:31 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_terminate(char *error_message)
{
	if (errno == 0)
		ft_putendl_fd(error_message, 2);
	else
		perror(error_message);
	exit(EXIT_FAILURE);
}

