/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:31:14 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/24 10:31:49 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"


void	draw_tiles(t_vault *data,
			int screen_x, int screen_y, unsigned int color)
{
	int	rows;
	int	cols;
	int	end_x;
	int	end_y;

	rows = screen_y;
	end_x = screen_x + TILE - 1;
	end_y = screen_y + TILE - 1;
	while (rows < end_y)
	{
		cols = screen_x;
		while (cols < end_x)
		{
			mlx_put_pixel(data->minimap->minimap, rows, cols, color);
			cols++;
		}
		rows++;
	}
}

void	full_line_minimap_hor(t_vault *data, int screen_y, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = data->map->max_lenght * TILE;
	while (start < len)
	{
		mlx_put_pixel(data->minimap->minimap, start, screen_y, color);
		start++;
	}
}

void	full_line_minimap_ver(t_vault *data, int screen_x, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = data->map->lines * TILE;
	while (start < len)
	{
		mlx_put_pixel(data->minimap->minimap, screen_x, start, color);
		start++;
	}
}

void	draw_ray_minimap(t_vault *data)
{
	double	x;
	double	y;
	int		len;

	len = 0;
	x = data->player->ppx;
	y = data->player->ppy;
	while (len < fabs(data->raycaster->ray_len) * TILE)
	{
		mlx_put_pixel(data->minimap->minimap, x, y, 0x00FF00FF);
		x = x + data->raycaster->pdx_ray;
		y = y + data->raycaster->pdy_ray;
		len++;
	}
}