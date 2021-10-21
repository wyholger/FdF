/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:36:27 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/29 16:36:21 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_window(t_data *data)
{
	data->mlx_d.mlx = mlx_init();
	data->mlx_d.mlx_win = mlx_new_window(data->mlx_d.mlx, 2300, 1800, "FDF");
	if (!data->mlx_d.mlx_win)
	{
		ft_putstr_fd("Error. Init window error", 1);
		end(data);
	}
}
