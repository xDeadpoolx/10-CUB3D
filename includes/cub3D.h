/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:34:40 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/14 09:38:32 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libart/includes/libart.h"
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define TRUE 1
# define FALSE 0
# define PI 3.1415926535
# define WIDTH 1024
# define HEIGHT 768
# define RED 0xFF0000FF
# define YELLOW 0xFFFF00FF
# define GREEN 0x00FF00FF
# define BLUE 0x00FFFFFF
# define DGRAY 0x3C3C3FFF
# define LGRAY 0x89898DFF

/***** STRUCTURES *****/

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	void	*p_right;
	void	*p_left;
	int		start_x;
	int		start_y;
	double	row;
	double	col;
	double	pdx;
	double	pdy;
	char	direction;
}	t_player;

typedef struct s_tex
{
	xpm_t	*tex_n;
	xpm_t	*tex_s;
	xpm_t	*tex_e;
	xpm_t	*tex_w;
	int		**north;
	int		**south;
	int		**east;
	int		**west;
}	t_tex;

typedef struct s_rays
{
	double	pdx_ray;
	double	pdy_ray;
	double	delta_dist_x;
	double	delta_dist_y;
	double	screen_2d_x;
	int		map_2d_col;
	int		map_2d_row;
	int		col;
	int		row;
	double	ray_len_x;
	double	ray_len_y;
	int		side;
	double	ray_len;
	double	plane_x;
	double	plane_y;
	double	rot_speed;
	double	mov_speed;
	double	height_3d;
}	t_rays;

typedef struct s_map
{
	char	**map;
	char	**temp_map;
	int		lines;
	int		max_lenght;
}	t_map;

typedef struct s_game
{
	mlx_image_t		*ddd;
	char			*wall_n;
	char			*wall_s;
	char			*wall_e;
	char			*wall_w;
	int				wall_height;
	int				wall_start;
	int				wall_end;
	unsigned int	wall_color;
	int				tex_x;
}	t_game;

typedef struct s_param
{
	char			*no_wall_path;
	int				no_exist;
	int				r_ceiling;
	int				g_ceiling;
	int				b_ceiling;
	int				r_floor;
	int				g_floor;
	int				b_floor;
	unsigned int	hex_floor;
	unsigned int	hex_ceiling;
	char			*so_wall_path;
	int				so_exist;
	char			*we_wall_path;
	int				we_exist;
	char			*ea_wall_path;
	int				ea_exist;
	char			*f_color;
	int				f_exist;
	char			*c_color;
	int				c_exist;
}	t_param;

typedef struct s_vault
{
	void		*mlx;
	char		**scene;
	char		*argv;
	int			map_start;
	int			error_code;
	int			lines;
	int			scene_element;
	t_player	*plr;
	t_param		*scene_param;
	t_map		*map;
	t_point		*size;
	t_point		*actual;
	t_game		*game;
	t_rays		*raycaster;
	t_tex		*tex;
}	t_vault;

/***** FONCTIONS *****/

/***** cub3D.c *****/
int		create_game(t_vault *data);
void	keyhandler(mlx_key_data_t keydata, void *param);
void	init_data(t_vault *data, char **argv);
void	quit_game(t_vault *data);

/***** error_management.c *****/
void	errors(t_vault *data);
void	errors_2(t_vault *data);
void	free_map(t_vault *data);
void	destroy_and_free_level(t_vault *data);
void	free_all(t_vault *data);

/***** scene_parsing.c *****/
void	check_scene_name(t_vault *data);
void	scene_to_array(t_vault *data);
void	check_scene_params(t_vault *data);
void	check_scene_syntax(t_vault *data, int *x);
void	check_random_scene_params(t_vault *data, int i);

/***** scene_parsing_utils.c *****/
void	check_fd(t_vault *data, int fd);
int		check_param_existence(t_vault *data);
void	skip_white_space(t_vault *data, int x, int y, int *slen);
int		isinset(char *s1, char *set);
void	check_valid_char(t_vault *data, int x);

/***** check_orientation_params.c *****/
void	check_no_params(t_vault *data, int x, int y, int slen);
void	check_so_params(t_vault *data, int x, int y, int slen);
void	check_we_params(t_vault *data, int x, int y, int slen);
void	check_ea_params(t_vault *data, int x, int y, int slen);
void	check_wall_path(t_vault *data);

/***** check_fc_params.c *****/
void	check_f_params(t_vault *data, int x, int y, int slen);
void	check_c_params(t_vault *data, int x, int y, int slen);
void	check_color_code(t_vault *data);
int		correct_rgb_char(char *rgb_code);
void	correct_rgb_range(t_vault *data, char *rgb_code, char c);
void	rgb_to_hex(t_vault *data, char flag);

/***** cub3d_utils.c *****/
void	map_to_new_array(t_vault *data, int x);
int		check_white_spaces(char c);
int		ft_find_char(char *src, char c);

/***** map_parsing.c *****/
void	check_map(t_vault *data);
void	find_player_start(t_vault *data);
void	fill_map_void(t_vault *data);
void	replace_voids(t_vault *data, int x);
void	fill_rest_of_line(t_vault *data, int x);

/***** map_parsing_utils.c *****/
void	map_to_new_array(t_vault *data, int x);
void	find_map_start(t_vault *data);
void	map_max_lenght(t_vault *data);

/***** check_ceiling_rgb.c *****/
void	extract_r_ceiling(t_vault *data, char *rgb_code, int *i, int *len);
void	extract_g_ceiling(t_vault *data, char *rgb_code, int *i, int *len);
void	extract_b_ceiling(t_vault *data, char *rgb_code, int *i, int *len);

/***** check_floor_rbg.c *****/
void	extract_r_floor(t_vault *data, char *rgb_code, int *i, int *len);
void	extract_g_floor(t_vault *data, char *rgb_code, int *i, int *len);
void	extract_b_floor(t_vault *data, char *rgb_code, int *i, int *len);

/***** flood_fill *****/
void	flood_fill(t_vault *data, int x, int y, char **temp);

/***** init_player.c *****/
void	load_player(t_vault *data);
void	init_player(t_vault *data);
void	find_orientation(t_vault *data, char direction);
void	find_orientation_2(t_vault *data, char direction);

/***** raycasting.c *****/
void	raycaster(t_vault *data);
void	dda(t_vault *data, int impact);
void	creating_3d_img(t_vault *data);
void	draw_tex_wall(t_vault *data, int pixels_2d);

/***** raycasting_utils.c *****/
void	dist_and_pos(t_vault *data);
void	dist_and_pos2(t_vault *data);

/***** textures.c *****/
int		rgb_to_hex2(int r, int g, int b, int a);
void	load_textures(t_vault *data);
int		**get_texture(xpm_t *tex);
void	find_tex_hit(t_vault *data, xpm_t *texture);
void	draw_line(t_vault *data, xpm_t *texture, int **tex_buff, int pixels_2d);

/***** moves.c *****/
void	move_forward(t_vault *data);
void	move_backward(t_vault *data);
void	move_left(t_vault *data);
void	move_right(t_vault *data);

/***** camera.c *****/
void	reinit_3d(t_vault *data);
void	rotate_left(t_vault *data);
void	rotate_right(t_vault *data);

/***** init_3d.c *****/
void	load_3d(t_vault *data);
void	background_3d(t_vault *data);

#endif