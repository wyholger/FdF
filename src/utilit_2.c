/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilit_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:13:46 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/06 19:29:24 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	max_and_min_z_init(t_data *data, int z)
{
	if (data->index.max_z < z)
		data->index.max_z = z;
	if (data->index.min_z > z)
		data->index.min_z = z;
}

void	check_fd(int fd)
{
	if (fd == -1)
	{
		ft_putstr_fd("Error. Riding file error!\n", 1);
		exit(0);
	}
}

int	check_for_draw(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}

void	check_read(char *argv)
{
	int		fd;
	int		read_len;
	char	buf[32];

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error. Open error!\n", 1);
		exit(0);
	}
	read_len = read(fd, buf, 32);
	if (read_len == -1)
	{
		ft_putstr_fd("Error. Read error!\n", 1);
		exit(0);
	}
	close(fd);
}
