/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:27:04 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/29 20:50:41 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_rotate(t_data *data, int x, int y, int z)
{
	t_m		*x_t;
	t_m		*y_t;
	t_m		*z_t;
	t_m		*res;
	t_list	*l;

	z_t = get_rot_z(z);
	y_t = get_rot_y(y);
	res = multiply_matrix(y_t, z_t);
	x_t = get_rot_x(x);
	res = multiply_matrix(x_t, res);
	z_t = get_scale_transform(data);
	res = multiply_matrix(z_t, res);
	l = data->map_d.list;
	while (l)
	{
		multiply_list_on_matrix(data, l, res);
		l->x_t += data->index.x_trans;
		l->y_t += data->index.y_trans;
		l = l->next;
	}
}
