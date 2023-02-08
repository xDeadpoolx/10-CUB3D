/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:33:50 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/08 10:56:50 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	quit_game(t_vault *data)
{
	printf("%s\n", "Au revoir !");
	free_all(data);
}

void	keyhandler(mlx_key_data_t keydata, void *param)
{
	t_vault	*data;

	data = (t_vault *) param;
	// if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	// 	forward(data);
	// if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	// 	backward(data);
	// if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	// 	straf_left(data);
	// if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	// 	straf_right(data);
	// if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	// 	rotate_left(data);
	// if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	// 	rotate_right(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit_game(data);
}

// static mlx_image_t *minimap; // attention global variable

// pour écran plus grand
// data->mlx = mlx_init(1920, 1080, "Une autre journée à 42 Québec !", true);
int	create_win(t_vault *data)
{
	data->mlx = mlx_init(1280, 720, "Une autre journée à 42 Québec !", true);
	if (!data->mlx)
		exit (EXIT_FAILURE);
	mlx_key_hook(data->mlx, &keyhandler, (void *) data);
	data->minimap->minimap = mlx_new_image(data->mlx, data->map->max_lenght * 11, data->map->lines * 11);
	init_minimap(data);
	mlx_image_to_window(data->mlx, data->minimap->minimap, 0, 0);   // Adds an image to the render queue.
    // mlx_put_pixel(minimap, data->player->start_x, data->player->start_y, 0xFFFFFFFF); // Single white pixel in the middle.
	// mlx_hook(data->mlx_win, 02, 0, key_hook, data); // cliquer sur la croix
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->minimap->minimap); // Once the application request an exit, cleanup.
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}

void	init_data(t_vault *data, char **argv)
{
	data->argv = argv[1];
	data->player = ft_calloc(1, sizeof(t_player));
	data->lvl1 = ft_calloc(1, sizeof(t_level));
	data->minimap = ft_calloc(1, sizeof(t_minimap));
	data->scene_param = ft_calloc(1, sizeof(t_param));
	data->map = ft_calloc(1, sizeof(t_map));
	data->size = ft_calloc(1, sizeof(t_point));
	data->actual = ft_calloc(1, sizeof(t_point));
	data->scene_param->r_ceiling = -1;
	data->scene_param->g_ceiling = -1;
	data->scene_param->b_ceiling = -1;
	data->scene_param->r_floor = -1;
	data->scene_param->g_floor = -1;
	data->scene_param->b_floor = -1;
}

int	main(int argc, char **argv)
{
	t_vault	data;

	data.error_code = 0;
	if (argc != 2)
		data.error_code = 9;
	errors(&data);
	init_data(&data, argv);
	check_scene_name(&data);
	scene_to_array(&data);
	check_scene_params(&data);
	check_map(&data);
	// errors(&data);
	// newgame(&data);
	create_win(&data);
	return (0);
}
