/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:25:17 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/07 17:23:05 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	check_argc(argc);
	check_read(argv[1]);
	init_null_data(&data);
	read_on_file(&data, argv[1]);
	init_map(&data, argv[1]);
	init_right(&data);
	get_rotate(&data, data.map_d.rad_x, data.map_d.rad_y, data.map_d.rad_z);
	init_window(&data);
	draw_image(&data);
	controls(&data);
	mlx_loop(data.mlx_d.mlx);
}
