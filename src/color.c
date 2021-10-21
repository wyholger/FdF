/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:39:07 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/29 16:35:02 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_color(t_data *data)
{
	data->color.r += data->color.r_step;
	data->color.g += data->color.g_step;
	data->color.b += data->color.b_step;
	data->color.color = ((int)data->color.r | 0);
	data->color.color <<= 8;
	data->color.color |= ((int)data->color.g | 0);
	data->color.color <<= 8;
	data->color.color |= ((int)data->color.b | 0);
}

void	r_g_b_init(t_data *data, t_list *x_y, t_list *x1_y1)
{
	data->color.b = x_y->color & 0xff;
	data->color.g = (x_y->color >> 8) & 0xff;
	data->color.r = (x_y->color >> 16) & 0xff;
	data->color.b_1 = x1_y1->color & 0xff;
	data->color.g_1 = (x1_y1->color >> 8) & 0xff;
	data->color.r_1 = (x1_y1->color >> 16) & 0xff;
	data->color.color = x_y->color;
}

void	color_step_init(t_data *data, t_list *x_y, t_list *x1_y1)
{
	float	x_step;
	float	y_step;
	float	max_step;

	x_step = x1_y1->x_t - x_y->x_t;
	y_step = x1_y1->y_t - x_y->y_t;
	max_step = max_float(abs_float(x_step), abs_float(y_step));
	data->color.r_step = module_difference(data->color.r_1, (int)data->color.r);
	data->color.g_step = module_difference(data->color.g_1, (int)data->color.g);
	data->color.b_step = module_difference(data->color.b_1, (int)data->color.b);
	data->color.r_step /= max_step;
	data->color.g_step /= max_step;
	data->color.b_step /= max_step;
}

int	assemble_color(int r, int g, int b)
{
	static int	color;

	color = 0;
	color = r | 0;
	color <<= 8;
	color |= g | 0;
	color <<= 8;
	color |= b | 0;
	return (color);
}

void	color_for_no_set_color(t_data *data, t_list *x_y, t_list *x1_y1)
{
	static float	z_coof;
	static int		r;
	static int		g;
	static int		b;

	if (x_y->color == 0)
	{
		z_coof = (float)x_y->z / (float)data->index.max_z;
		r = MN_R + (z_coof * (float)DIFF_R);
		g = MN_G + (z_coof * (float)DIFF_G);
		b = MN_B + (z_coof * (float)DIFF_B);
		x_y->color = assemble_color(r, g, b);
	}
	if (x1_y1->color == 0)
	{
		z_coof = (float)x1_y1->z / (float)data->index.max_z;
		r = MN_R + (z_coof * (float)DIFF_R);
		g = MN_G + (z_coof * (float)DIFF_G);
		b = MN_B + (z_coof * (float)DIFF_B);
		x1_y1->color = assemble_color(r, g, b);
	}
}
