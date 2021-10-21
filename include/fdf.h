/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:21:28 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/06 19:15:52 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# define MX_R 243
# define MX_G 240
# define MX_B 7
# define MN_R 110
# define MN_G 18
# define MN_B 230
# define DIFF_R 133
# define DIFF_G 222
# define DIFF_B -223
typedef struct s_data
{
	struct s_map_data
	{
		t_list	*list;
		int		with;
		int		height;
		int		rad_x;
		int		rad_y;
		int		rad_z;
	}		map_d;
	struct s_coordinate
	{
		int		zoom_index;
		float	z_zoom_index;
		int		max_z;
		int		min_z;
		int		z_differ;
		int		flag_first_read;
		int		x_trans;
		int		y_trans;
		int		z_trans;
		int		medium_x;
		int		medium_y;
	}		index;
	struct s_mlx
	{
		void	*mlx;
		void	*mlx_win;
	}		mlx_d;
	struct s_color
	{
		int		color;
		float	r_step;
		float	g_step;
		float	b_step;
		float	r;
		float	g;
		float	b;
		int		r_1;
		int		g_1;
		int		b_1;
	}		color;
	struct s_draw_ints
	{
		int		delta_x;
		int		delta_y;
		int		sign_x;
		int		sign_y;
		int		error;
		int		x;
		int		y;
		int		x1;
		int		y1;
	}		t_drw;
}				t_data;
typedef struct s_matrx
{
	float	m[4][4];
}			t_m;
void	check_fd(int fd);
void	check_argc(int argc);
void	read_on_file(t_data *data, char *argv);
void	init_null_data(t_data *data);
void	cleaner_char(char **for_split, int len);
int		max(int a, int b);
float	max_float(float a, float b);
float	abs_float(float a);
float	module_difference(int a, int b);
void	init_map(t_data *data, char *argv);
int		writing_map(t_data *data, char *for_split, int x, int y);
void	max_and_min_z_init(t_data *data, int z);
int		color_parsing(char *for_split);
void	init_lower(t_list *tmp);
void	init_right(t_data *data);
t_m		*get_scale(int sx, int sy, float sz);
t_m		*get_rot_x(int angle);
t_m		*get_rot_y(int angle);
t_m		*get_rot_z(int angle);
t_m		*get_scale_transform(t_data *data);
t_m		*multiply_matrix(t_m *a, t_m *b);
void	multiply_list_on_matrix(t_data *data, t_list *lst, t_m *m);
void	get_rotate(t_data *data, int x, int y, int z);
void	init_window(t_data *data);
void	draw_image(t_data *data);
void	draw_line(t_data *data, t_list *x_y, t_list *x1_y1);
void	drow_variable_init(t_data *data, t_list *x_y, t_list *x1_y1);
void	draw(t_data *data);
void	put_message(t_data *data);
void	get_color(t_data *data);
void	r_g_b_init(t_data *data, t_list *x_y, t_list *x1_y1);
void	color_step_init(t_data *data, t_list *x_y, t_list *x1_y1);
int		assemble_color(int r, int g, int b);
void	color_for_no_set_color(t_data *data, t_list *x_y, t_list *x1_y1);
void	z_correct(int key, t_data *data);
void	rotate(int key, t_data *data);
void	end(t_data *data);
int		key_press(int key, void *param);
void	controls(t_data *data);
void	parallel(t_data *data);
void	isometric(t_data *data);
void	zoom(int key, t_data *data);
void	move(int key, t_data *data);
int		ft_abs(int a);
int		check_for_draw(int a, int b);
void	check_argc(int argc);
void	init_null_data(t_data *data);
void	read_on_file(t_data *data, char *argv);
void	check_read(char *argv);
#endif