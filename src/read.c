/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:27:00 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/06 19:06:45 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	read_on_file(t_data *data, char *argv)
{
	int		fd;
	int		flag_first_read;
	char	*line;
	char	**for_split;

	flag_first_read = 0;
	fd = open(argv, O_RDONLY);
	check_fd(fd);
	while (get_next_line(fd, &line))
	{
		if (flag_first_read == 0)
		{
			for_split = ft_split(line, ' ');
			flag_first_read = 1;
			while (for_split[data->map_d.with])
				data->map_d.with++;
		}
		data->map_d.height++;
		free(line);
	}
	free(line);
	cleaner_char(for_split, data->map_d.with + 1);
	data->index.medium_x = data->map_d.with / 2;
	data->index.medium_y = data->map_d.height / 2;
	close(fd);
}

void	init_null_data(t_data *data)
{
	data->map_d.with = 0;
	data->map_d.height = 0;
	data->index.flag_first_read = 0;
	data->index.z_zoom_index = 1;
	data->index.zoom_index = 1000;
	data->index.max_z = 0;
	data->index.min_z = 0;
	data->map_d.rad_x = 45;
	data->map_d.rad_y = 0;
	data->map_d.rad_z = 45;
	data->index.x_trans = 1200;
	data->index.y_trans = 700;
}

void	check_argc(int argc)
{
	if (argc == 2)
		return ;
	if (argc == 1)
	{
		ft_putstr_fd("Error. No aruments!\n", 1);
		exit(0);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Error. To many aruments!\n", 1);
		exit(0);
	}
}
