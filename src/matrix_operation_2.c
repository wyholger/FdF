/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operation_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:20:19 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/29 16:36:00 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_m	*multiply_matrix(t_m *a, t_m *b)
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
			m.m[i][j] = a->m[i][0] * b->m[0][j] + a->m[i][1] * \
			b->m[1][j] + a->m[i][2] * b->m[2][j] + a->m[i][3] * b->m[3][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (&m);
}

t_m	*get_scale_transform(t_data *data)
{
	int	max_side;
	int	zoom;
	t_m	*m;

	max_side = max(data->map_d.with, data->map_d.height);
	zoom = data->index.zoom_index / max_side;
	m = get_scale(zoom, zoom, 1);
	return (m);
}
