/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:45 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/08 16:31:07 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_player(t_vault *data)
{
	data->player->px = data->player->start_x;
	data->player->py = data->player->start_y;
}

void	move_forward(t_vault *data)
{
	mlx_delete_image(data->mlx, data->minimap->minimap);
	data->minimap->minimap = mlx_new_image(data->mlx, data->map->max_lenght * 11, data->map->lines * 11);
	init_minimap(data);
	draw_minimap(data);
	mlx_image_to_window(data->mlx, data->minimap->minimap, 0, 0);
	data->player->px = data->player->px + data->player->pdx;
	data->player->py = data->player->py + data->player->pdy;
	player_pixels(data, 'N');
}

void	move_backward(t_vault *data)
{
	mlx_delete_image(data->mlx, data->minimap->minimap);
	data->minimap->minimap = mlx_new_image(data->mlx, data->map->max_lenght * 11, data->map->lines * 11);
	init_minimap(data);
	draw_minimap(data);
	mlx_image_to_window(data->mlx, data->minimap->minimap, 0, 0);
	data->player->px = data->player->px - data->player->pdx;
	data->player->py = data->player->py - data->player->pdy;
	player_pixels(data, 'S');
}

void	move_left(t_vault *data)
{
	mlx_delete_image(data->mlx, data->minimap->minimap);
	data->minimap->minimap = mlx_new_image(data->mlx, data->map->max_lenght * 11, data->map->lines * 11);
	init_minimap(data);
	draw_minimap(data);
	mlx_image_to_window(data->mlx, data->minimap->minimap, 0, 0);
	data->player->pa -= 0.1;
	if (data->player->pa < 0)
	{
		data->player->pa = data->player->pa + 2 * PI;
	}
	data->player->pdx = cos(data->player->pa) * 5;
	data->player->pdy = sin(data->player->pa) * 5;
	// data->player->py = data->player->py - 0.3;
	player_pixels(data, 'W');
}

void	move_right(t_vault *data)
{
	mlx_delete_image(data->mlx, data->minimap->minimap);
	data->minimap->minimap = mlx_new_image(data->mlx, data->map->max_lenght * 11, data->map->lines * 11);
	init_minimap(data);
	draw_minimap(data);
	mlx_image_to_window(data->mlx, data->minimap->minimap, 0, 0);
	data->player->pa += 0.1;
	if (data->player->pa > 2 * PI)
	{
		data->player->pa = data->player->pa - 2 * PI;
	}
	data->player->pdx = cos(data->player->pa) * 5;
	data->player->pdy = sin(data->player->pa) * 5;
	// data->player->py = data->player->py + 0.3;
	player_pixels(data, 'E');
}
