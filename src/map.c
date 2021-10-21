/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:00:10 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/29 21:13:30 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_map(t_data *data, char *argv)
{
	int		fd;
	int		x;
	int		y;
	char	**for_split;
	char	*line;

	fd = open(argv, O_RDONLY);
	x = 0;
	y = 0;
	while (get_next_line(fd, &line))
	{
		for_split = ft_split(line, ' ');
		while (for_split[x])
			x = writing_map(data, for_split[x], \
			x - data->index.medium_x, y - data->index.medium_y);
		x = 0;
		y++;
		cleaner_char(for_split, data->map_d.with + 1);
		free(line);
	}
	data->index.z_differ = data->index.max_z - data->index.min_z;
	free(line);
}

int	writing_map(t_data *data, char *for_split, int x, int y)
{
	static int	z;
	static int	color;

	z = ft_atoi(for_split);
	max_and_min_z_init(data, z);
	color = color_parsing(for_split);
	if (data->index.flag_first_read == 0)
	{
		data->map_d.list = ft_lstnew(x, y, z, color);
		data->index.flag_first_read = 1;
	}
	else
		ft_lstadd_back(&data->map_d.list, ft_lstnew(x, y, z, color));
	x++;
	return (x + data->index.medium_x);
}

int	color_parsing(char *for_split)
{
	char	*char_color;
	int		color;

	char_color = ft_strchr(for_split, ',');
	if (char_color)
	{
		color = ft_atoi_base(&char_color[3], 16);
		if (color == 0)
			color = 1;
	}
	else
		color = 0;
	return (color);
}

void	init_lower(t_list *tmp)
{
	static int		flag;
	static t_list	*iter;

	iter = tmp->next;
	flag = 0;
	while (flag == 0 && iter)
	{
		if (tmp->x == iter->x && tmp->y + 1 == iter->y)
		{
			tmp->lower = iter;
			flag = 1;
		}
		else
			iter = iter->next;
	}
}

void	init_right(t_data *data)
{
	t_list	*tmp;
	t_list	*iter;

	tmp = data->map_d.list;
	iter = data->map_d.list;
	while (tmp->next)
	{
		if (iter)
			iter = iter->next;
		if (tmp->y == iter->y)
		{
			if (iter)
				tmp->right = iter;
		}
		else
			tmp->right = NULL;
		init_lower(tmp);
		tmp = tmp->next;
		iter = tmp;
	}
}
