/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:00:20 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/07 17:58:42 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	reinit_hud(t_vault *data)
{
	mlx_delete_image(data->mlx, data->hud_loc->hud_loc_static);
	mlx_delete_image(data->mlx, data->hud_loc->hud_loc_dynamic);
	load_hud(data);
}

void	load_hud(t_vault *data)
{
	data->hud_loc->hud_loc_static = mlx_new_image(data->mlx, 200, 50);
	data->hud_loc->hud_loc_dynamic = mlx_new_image(data->mlx, 200, 50);
	mlx_image_to_window(data->mlx, data->hud_loc->hud_loc_static, 65, 30);
	mlx_image_to_window(data->mlx, data->hud_loc->hud_loc_dynamic, 265, 30);
}

void	draw_tex_location(t_vault *data, xpm_t *texture,
	int **tex_buff, int pixels_2d)
{
	int	screen_y;

	while (pixels_2d < (int)texture->texture.width)
	{
		screen_y = 0;
		while (screen_y < (int)texture->texture.height)
		{
			mlx_put_pixel(data->hud_loc->hud_loc_static, pixels_2d, screen_y,
				tex_buff[screen_y][pixels_2d]);
			screen_y++;
		}
		pixels_2d++;
	}
}

void	draw_tex_location2(t_vault *data, xpm_t *texture,
	int **tex_buff, int pixels_2d)
{
	int	screen_y;

	while (pixels_2d < (int)texture->texture.width)
	{
		screen_y = 0;
		while (screen_y < (int)texture->texture.height)
		{
			mlx_put_pixel(data->hud_loc->hud_loc_dynamic, pixels_2d, screen_y,
				tex_buff[screen_y][pixels_2d]);
			screen_y++;
		}
		pixels_2d++;
	}
}
