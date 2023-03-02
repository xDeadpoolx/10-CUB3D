/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_textures_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:51:54 by maison            #+#    #+#             */
/*   Updated: 2023/03/02 08:55:52 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	draw_tex_wall(t_vault *data, int pixels_2d)
{
	if (data->raycaster->side == 0)
	{
		find_tex_hit(data, data->tex->tex_e);
		draw_line(data, data->tex->tex_e, data->tex->east, pixels_2d);
	}
	if (data->raycaster->side == 1)
	{
		find_tex_hit(data, data->tex->tex_w);
		draw_line(data, data->tex->tex_w, data->tex->west, pixels_2d);
	}
	if (data->raycaster->side == 2 || data->raycaster->side == 14
		|| data->raycaster->side == 18 || data->raycaster->side == 22
		|| data->raycaster->side == 26 || data->raycaster->side == 30)
	{
		find_tex_hit(data, data->tex->tex_s);
		draw_line(data, data->tex->tex_s, data->tex->south, pixels_2d);
	}
	if (data->raycaster->side == 3)
	{
		find_tex_hit(data, data->tex->tex_n);
		draw_line(data, data->tex->tex_n, data->tex->north, pixels_2d);
	}
	draw_tex_wall_2(data, pixels_2d);
}

void	draw_tex_wall_2(t_vault *data, int pixels_2d)
{
	if (data->raycaster->side == 4 || data->raycaster->side == 5
		|| data->raycaster->side == 6 || data->raycaster->side == 7)
	{
		find_tex_hit(data, data->tex->tex_window);
		draw_line(data, data->tex->tex_window, data->tex->window, pixels_2d);
	}
	if (data->raycaster->side == 8 || data->raycaster->side == 9
		|| data->raycaster->side == 10 || data->raycaster->side == 11)
	{
		find_tex_hit(data, data->tex->tex_door);
		draw_line(data, data->tex->tex_door, data->tex->door, pixels_2d);
	}
	if (data->raycaster->side == 13 || data->raycaster->side == 15
		|| data->raycaster->side == 12)
	{
		find_tex_hit(data, data->tex->tex_dungeon);
		draw_line(data, data->tex->tex_dungeon, data->tex->dungeon, pixels_2d);
	}
	if (data->raycaster->side == 16 || data->raycaster->side == 17
		|| data->raycaster->side == 19)
	{
		find_tex_hit(data, data->tex->tex_tribute);
		draw_line(data, data->tex->tex_tribute, data->tex->tribute, pixels_2d);
	}
	draw_tex_wall_3(data, pixels_2d);
}

void	draw_tex_wall_3(t_vault *data, int pixels_2d)
{
	if (data->raycaster->side == 20 || data->raycaster->side == 21
		|| data->raycaster->side == 23)
	{
		find_tex_hit(data, data->tex->tex_marc);
		draw_line(data, data->tex->tex_marc, data->tex->marc, pixels_2d);
	}
	if (data->raycaster->side == 24 || data->raycaster->side == 25
		|| data->raycaster->side == 27)
	{
		find_tex_hit(data, data->tex->tex_armada);
		draw_line(data, data->tex->tex_armada, data->tex->armada, pixels_2d);
	}
	if (data->raycaster->side == 28 || data->raycaster->side == 29
		|| data->raycaster->side == 31)
	{
		find_tex_hit(data, data->tex->tex_torrent);
		draw_line(data, data->tex->tex_torrent, data->tex->torrent, pixels_2d);
	}
}
