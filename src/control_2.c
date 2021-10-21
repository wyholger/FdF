/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:57:38 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/29 16:35:44 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move(int key, t_data *data)
{
	mlx_clear_window(data->mlx_d.mlx, data->mlx_d.mlx_win);
	if (key == 126)
		data->index.y_trans -= 20;
	if (key == 125)
		data->index.y_trans += 20;
	if (key == 123)
		data->index.x_trans -= 20;
	if (key == 124)
		data->index.x_trans += 20;
	get_rotate(data, data->map_d.rad_x, data->map_d.rad_y, data->map_d.rad_z);
	draw_image(data);
}

void	zoom(int key, t_data *data)
{
	mlx_clear_window(data->mlx_d.mlx, data->mlx_d.mlx_win);
	if (key == 69)
		data->index.zoom_index += 50;
	if (key == 78 && data->index.zoom_index > 100)
		data->index.zoom_index -= 50;
	get_rotate(data, data->map_d.rad_x, data->map_d.rad_y, data->map_d.rad_z);
	draw_image(data);
}

void	isometric(t_data *data)
{
	data->map_d.rad_x = 45;
	data->map_d.rad_y = 0;
	data->map_d.rad_z = 45;
	get_rotate(data, data->map_d.rad_x, data->map_d.rad_y, data->map_d.rad_z);
	mlx_clear_window(data->mlx_d.mlx, data->mlx_d.mlx_win);
	draw_image(data);
}

void	parallel(t_data *data)
{
	data->map_d.rad_x = 0;
	data->map_d.rad_y = 0;
	data->map_d.rad_z = 0;
	get_rotate(data, data->map_d.rad_x, data->map_d.rad_y, data->map_d.rad_z);
	mlx_clear_window(data->mlx_d.mlx, data->mlx_d.mlx_win);
	draw_image(data);
}
