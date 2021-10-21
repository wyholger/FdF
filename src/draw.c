/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:38:34 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/21 22:43:25 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_image(t_data *data)
{
	t_list	*tmp;

	tmp = data->map_d.list;
	while (tmp)
	{
		if (tmp->right)
			draw_line(data, tmp, tmp->right);
		if (tmp->lower)
			draw_line(data, tmp, tmp->lower);
		tmp = tmp->next;
	}
	put_message(data);
}

void	draw_line(t_data *data, t_list *x_y, t_list *x1_y1)
{
	if (x_y->x_t > 0 && x_y->y_t > 0 && x_y->x_t < 2300 && x_y->y_t < 1800)
	{
		if (data->index.max_z == data->index.min_z && x_y->color == 0)
			x_y->color = 0xffffff;
		else if (data->index.max_z == data->index.min_z && x1_y1->color == 0)
			x1_y1->color = 0xffffff;
		else if (data->index.max_z != data->index.min_z)
			color_for_no_set_color(data, x_y, x1_y1);
		r_g_b_init(data, x_y, x1_y1);
		color_step_init(data, x_y, x1_y1);
		drow_variable_init(data, x_y, x1_y1);
		draw(data);
	}
}

void	drow_variable_init(t_data *data, t_list *x_y, t_list *x1_y1)
{
	data->t_drw.x = x_y->x_t;
	data->t_drw.y = x_y->y_t;
	data->t_drw.x1 = x1_y1->x_t;
	data->t_drw.y1 = x1_y1->y_t;
	data->t_drw.delta_x = ft_abs(data->t_drw.x1 - data->t_drw.x);
	data->t_drw.delta_y = ft_abs(data->t_drw.y1 - data->t_drw.y);
	data->t_drw.sign_x = check_for_draw(data->t_drw.x, data->t_drw.x1);
	data->t_drw.sign_y = check_for_draw(data->t_drw.y, data->t_drw.y1);
	data->t_drw.error = data->t_drw.delta_x - data->t_drw.delta_y;
}

void	draw(t_data *data)
{
	int	error2;

	mlx_pixel_put(data->mlx_d.mlx, data->mlx_d.mlx_win, data->t_drw.x, \
	data->t_drw.y, data->color.color);
	while ((data->t_drw.x != data->t_drw.x1 || data->t_drw.y \
	!= data->t_drw.y1) && (data->t_drw.x > 0 && data->t_drw.y > 0))
	{
		get_color(data);
		mlx_pixel_put(data->mlx_d.mlx, data->mlx_d.mlx_win, data->t_drw.x, \
		data->t_drw.y, data->color.color);
		error2 = data->t_drw.error * 2;
		if (error2 > -data->t_drw.delta_y)
		{
			data->t_drw.error -= data->t_drw.delta_y;
			data->t_drw.x += data->t_drw.sign_x;
		}
		if (error2 < data->t_drw.delta_x)
		{
			data->t_drw.error += data->t_drw.delta_x;
			data->t_drw.y += data->t_drw.sign_y;
		}
	}
}

void	put_message(t_data *data)
{
	mlx_string_put(data->mlx_d.mlx, data->mlx_d.mlx_win, 0, 0, \
	0xe52845, "\t\tHey YOU!,\t\t\n Some tips for you : ");
	mlx_string_put(data->mlx_d.mlx, data->mlx_d.mlx_win, 0, 20, \
	0x40e0d0, "Move up: '^',Move left: '<', Move right: '>', Move down :" \
	"'\\/' (im sorry, cant inteprette unicode)");
	mlx_string_put(data->mlx_d.mlx, data->mlx_d.mlx_win, 0, 40, 0xffffff, \
	"Rotate X - 'w' / 's', Rotate Y - 'a' / 'd'," \
	"Rotate Z - 'q' / 'e'; Zoom '+' and '-' ;");
	mlx_string_put(data->mlx_d.mlx, data->mlx_d.mlx_win, 0, \
	60, 0x40e0d0, "Height adjustment, the arrow under the F15 button");
}
