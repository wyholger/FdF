/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:18:39 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/29 16:36:04 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_m	*get_scale(int sx, int sy, float sz)
{
	static t_m	m;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			m.m[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	m.m[0][0] = sx;
	m.m[1][1] = sy;
	m.m[2][2] = sz;
	m.m[3][3] = 1;
	return (&m);
}

t_m	*get_rot_x(int angle)
{
	static t_m	m;
	float		rad;
	int			i;
	int			j;

	i = 0;
	j = 0;
	rad = M_PI / 180 * angle;
	while (i < 4)
	{
		while (j < 4)
		{
			m.m[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	m.m[0][0] = 1;
	m.m[1][1] = cos(rad);
	m.m[1][2] = -sin(rad);
	m.m[2][1] = sin(rad);
	m.m[2][2] = cos(rad);
	m.m[3][3] = 1;
	return (&m);
}

t_m	*get_rot_y(int angle)
{
	float		rad;
	static t_m	m;
	int			i;
	int			j;

	i = 0;
	j = 0;
	rad = M_PI / 180 * angle;
	while (i < 4)
	{
		while (j < 4)
		{
			m.m[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	m.m[0][0] = cos(rad);
	m.m[0][2] = sin(rad);
	m.m[1][1] = 1;
	m.m[2][0] = -sin(rad);
	m.m[2][2] = cos(rad);
	m.m[3][3] = 1;
	return (&m);
}

t_m	*get_rot_z(int angle)
{
	float		rad;
	static t_m	m;
	int			i;
	int			j;

	i = 0;
	j = 0;
	rad = M_PI / 180 * angle;
	while (i < 4)
	{
		while (j < 4)
		{
			m.m[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	m.m[0][0] = cos(rad);
	m.m[0][1] = -sin(rad);
	m.m[1][0] = sin(rad);
	m.m[1][1] = cos(rad);
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (&m);
}

void	multiply_list_on_matrix(t_data *data, t_list *lst, t_m *m)
{
	static t_list	*tmp;

	tmp = lst;
	tmp->x_t = m->m[0][0] * tmp->x + m->m[0][1] * tmp->y + \
	m->m[0][2] * ((float)tmp->z * data->index.z_zoom_index) + m->m[0][3];
	tmp->y_t = m->m[1][0] * tmp->x + m->m[1][1] * tmp->y + \
	m->m[1][2] * ((float)tmp->z * data->index.z_zoom_index) + m->m[1][3];
	tmp->z_t = m->m[2][0] * tmp->x + m->m[2][1] * tmp->y + \
	m->m[2][2] * ((float)tmp->z * data->index.z_zoom_index) + m->m[2][3];
}
