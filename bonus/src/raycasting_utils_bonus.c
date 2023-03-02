/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:21:30 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/02 00:43:26 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	dist_and_pos(t_vault *data)
{
	data->raycaster->pdx_ray = data->plr->pdx + data->raycaster->plane_x
		* data->raycaster->screen_2d_x;
	data->raycaster->pdy_ray = data->plr->pdy + data->raycaster->plane_y
		* data->raycaster->screen_2d_x;
	data->raycaster->col = data->plr->col;
	data->raycaster->row = data->plr->row;
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
		data->raycaster->ray_len_x = (data->plr->col - data->raycaster->col)
			* data->raycaster->delta_dist_x;
	}
	else
	{
		data->raycaster->map_2d_col = 1;
		data->raycaster->ray_len_x = (data->raycaster->col + 1.0
				- data->plr->col) * data->raycaster->delta_dist_x;
	}
	if (data->raycaster->pdy_ray < 0)
	{
		data->raycaster->map_2d_row = -1;
		data->raycaster->ray_len_y = (data->plr->row - data->raycaster->row)
			* data->raycaster->delta_dist_y;
	}
	else
	{
		data->raycaster->map_2d_row = 1;
		data->raycaster->ray_len_y = (data->raycaster->row + 1.0
				- data->plr->row) * data->raycaster->delta_dist_y;
	}
}

void	check_type_wall(t_vault *data, int *impact)
{
	if (data->map->map[data->raycaster->row][data->raycaster->col] == '1'
		|| data->map->map[data->raycaster->row][data->raycaster->col] == 'Z')
		*impact = 1;
	else if (data->map->map[data->raycaster->row][data->raycaster->col]
		== '2')
	{
		*impact = 1;
		if (data->raycaster->side == 0)
			data->raycaster->side = 5;
		else if (data->raycaster->side == 1)
			data->raycaster->side = 4;
		else if (data->raycaster->side == 2)
			data->raycaster->side = 6;
		else if (data->raycaster->side == 3)
			data->raycaster->side = 7;
	}
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == 'D')
		check_type_wall_d(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '3')
		check_type_wall_3(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '4')
		check_type_wall_4(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '5')
		check_type_wall_5(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '6')
		check_type_wall_6(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '7')
		check_type_wall_7(data, impact);
}

void	check_type_wall_d(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 8;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 9;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 10;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 11;
}

void	check_type_wall_3(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 12;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 13;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 14;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 15;
}

void	check_type_wall_4(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 16;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 17;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 18;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 19;
}

void	check_type_wall_5(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 20;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 21;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 22;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 23;
}

void	check_type_wall_6(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 24;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 25;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 26;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 27;
}

void	check_type_wall_7(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 28;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 29;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 30;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 31;
}
