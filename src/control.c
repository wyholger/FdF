/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:51:20 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/07 18:23:06 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	controls(t_data *data)
{
	mlx_hook(data->mlx_d.mlx_win, 2, 0, key_press, data);
}

int	key_press(int key, void *param)
{
	if (key == 53)
		end(param);
	if ((key >= 0 && key <= 3) || key == 13 || key == 12 || key == 14)
		rotate(key, param);
	if (key == 116 || key == 121)
		z_correct(key, param);
	if (key >= 123 && key <= 126)
		move(key, param);
	if (key == 69 || key == 78)
		zoom(key, param);
	if (key == 34)
		isometric(param);
	if (key == 35)
		parallel(param);
	return (0);
}

void	end(t_data *data)
{
	ft_lstclear(&data->map_d.list);
	mlx_destroy_window(data->mlx_d.mlx, data->mlx_d.mlx_win);
	exit(0);
}

void	rotate(int key, t_data *data)
{
	mlx_clear_window(data->mlx_d.mlx, data->mlx_d.mlx_win);
	if (key == 13)
		data->map_d.rad_x += 3;
	if (key == 1)
		data->map_d.rad_x -= 3;
	if (key == 0)
		data->map_d.rad_y -= 3;
	if (key == 2)
		data->map_d.rad_y += 3;
	if (key == 12)
		data->map_d.rad_z -= 3;
	if (key == 14)
		data->map_d.rad_z += 3;
	get_rotate(data, data->map_d.rad_x, data->map_d.rad_y, data->map_d.rad_z);
	draw_image(data);
}

void	z_correct(int key, t_data *data)
{
	if (key == 116)
	{
		mlx_clear_window(data->mlx_d.mlx, data->mlx_d.mlx_win);
		data->index.z_zoom_index += 0.05;
		get_rotate(data, data->map_d.rad_x, \
		data->map_d.rad_y, data->map_d.rad_z);
		draw_image(data);
	}
	if (key == 121)
	{
		mlx_clear_window(data->mlx_d.mlx, data->mlx_d.mlx_win);
		if (data->index.z_zoom_index > 0)
			data->index.z_zoom_index -= 0.05;
		get_rotate(data, data->map_d.rad_x, data->map_d.rad_y, \
		data->map_d.rad_z);
		draw_image(data);
	}	
}
