/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:36:27 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/13 20:40:29 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_sprites(t_vault *data)
{
	data->s_par->s[0].s_row = 9.5;
	data->s_par->s[0].s_col = 20.5;
	data->s_par->s[0].texture = 1;
	data->s_par->s[1].s_row = 33.5;
	data->s_par->s[1].s_col = 8.5;
	data->s_par->s[1].texture = 2;
}

void	sprite_ordering(t_vault *data)
{
	int	i;

	i = 0;
	while (i < NUMSPRITES)
	{
		data->s_par->s_prio[i] = i;
		data->s_par->s_dist[i]
			= ((data->plr->row - data->s_par->s[i].s_row)
				* (data->plr->row - data->s_par->s[i].s_row)
				+ (data->plr->col - data->s_par->s[i].s_col)
				* (data->plr->col - data->s_par->s[i].s_col));
		i++;
	}
	sort_sprites(data);
}

void	sort_sprites(t_vault *data)
{
	int		i;
	int		j;
	double	tmp;

	i = 0;
	while (i < NUMSPRITES)
	{
		j = 0;
		while (j < NUMSPRITES - 1)
		{
			if (data->s_par->s_dist[j]
				< data->s_par->s_dist[j + 1]
				&& (data->s_par->s_prio[j]
					< data->s_par->s_prio[j + 1]))
			{
				tmp = data->s_par->s_prio[j];
				data->s_par->s_prio[j] = data->s_par->s_prio[j + 1];
				data->s_par->s_prio[j + 1] = (int)tmp;
			}
			j++;
		}
		i++;
	}
}