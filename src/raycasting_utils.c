/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:21:30 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/27 13:31:39 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	dist_and_pos(t_vault *data)
{
	data->raycaster->pdx_ray = data->player->pdx + data->raycaster->plane_x
		* data->raycaster->screen_2d_x;
	data->raycaster->pdy_ray = data->player->pdy + data->raycaster->plane_y
		* data->raycaster->screen_2d_x;
	data->raycaster->col = data->player->col;
	data->raycaster->row = data->player->row;
	if (data->raycaster->pdx_ray == 0)
		data->raycaster->delta_dist_x = 1e30;
	else
		data->raycaster->delta_dist_x = fabs(1 / data->raycaster->pdx_ray);
	if (data->raycaster->pdy_ray == 0)
		data->raycaster->delta_dist_y = 1e30;
	else
		data->raycaster->delta_dist_y = fabs(1 / data->raycaster->pdy_ray);
	dist_and_pos2(data);
}

void	dist_and_pos2(t_vault *data)
{
	if (data->raycaster->pdx_ray < 0)
	{
		data->raycaster->map_2d_col = -1;
		data->raycaster->ray_len_x = (data->player->col - data->raycaster->col)
			* data->raycaster->delta_dist_x;
	}
	else
	{
		data->raycaster->map_2d_col = 1;
		data->raycaster->ray_len_x = (data->raycaster->col + 1.0
				- data->player->col) * data->raycaster->delta_dist_x;
	}
	if (data->raycaster->pdy_ray < 0)
	{
		data->raycaster->map_2d_row = -1;
		data->raycaster->ray_len_y = (data->player->row - data->raycaster->row)
			* data->raycaster->delta_dist_y;
	}
	else
	{
		data->raycaster->map_2d_row = 1;
		data->raycaster->ray_len_y = (data->raycaster->row + 1.0
				- data->player->row) * data->raycaster->delta_dist_y;
	}
}
