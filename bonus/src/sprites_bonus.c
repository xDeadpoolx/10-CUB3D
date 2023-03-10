/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:43:55 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/14 22:02:57 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

// -current-\-old-
//s_par \ sp_param
//s_ds_x \ drawStartX
//s_de_y \ drawEndY
//s_prio \ spriteOrder
//s_dist \ spriteDistance

void	sprite_casting(t_vault *data)
{
	int	i;

	i = -1;
	sprite_ordering(data);
	while (++i < NUMSPRITES)
	{
		sprite_computing(data, i);
		data->s_par->screen_x = data->s_par->s_ds_x;
		while (data->s_par->screen_x < data->s_par->s_de_x)
		{
			data->s_par->tex_sx = fabs((int)(256 * (data->s_par->screen_x
							- (-data->s_par->s_w / 2 + data->s_par->s_sc_x)))
					*TEXWIDTH / data->s_par->s_w / 256);
			if (data->s_par->tr_y > 0 && data->s_par->screen_x > 0
				&& data->s_par->screen_x < WIDTH
				&& data->s_par->tr_y
				< data->s_par->z_buff[data->s_par->screen_x])
				sprite_choice(data, i);
			data->s_par->screen_x++;
		}
	}
}

void	sprite_choice(t_vault *data, int i)
{
	int	frame;

	frame = 0;
	data->s_par->screen_y = data->s_par->s_ds_y;
	if (data->s_par->s[data->s_par->s_prio[i]].texture == 1)
		draw_sprite(data, data->tex->sprite1);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 2)
		draw_sprite(data, data->tex->sprite2);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 3)
		draw_sprite(data, data->tex->pillar);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 4)
	{
		while (frame < 5)
		{
			data->s_par->tex_sx = fabs((int)(256 * (data->s_par->screen_x
							- (-data->s_par->s_w / 2 + data->s_par->s_sc_x)))
					*TEXWIDTH / data->s_par->s_w / 256) + frame * 256;
			printf("frame : %d\n", frame);
			draw_sprite(data, data->tex->fire_tor);
			frame++;
		}
	}
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 5)
		draw_sprite(data, data->tex->plants);
}

void	draw_sprite(t_vault *data, int **tex_buff)
{
	int	tex_y;
	int	d;

	while (data->s_par->screen_y < data->s_par->s_de_y)
	{
		d = (int)((data->s_par->screen_y) * 256 - HEIGHT
				* 128 + data->s_par->s_h * 128);
		tex_y = fabs(((d * TEXHEIGHT) / data->s_par->s_h) / 256);
		if (tex_buff[tex_y][data->s_par->tex_sx] != (int)0xff00ffff)
			mlx_put_pixel(data->game->sprite, data->s_par->screen_x,
				data->s_par->screen_y, tex_buff[tex_y][data->s_par->tex_sx]);
		data->s_par->screen_y++;
	}
}

void	sprite_computing(t_vault *data, int i)
{
	data->s_par->s_diff_col
		= data->s_par->s[data->s_par->s_prio[i]].s_row - (data->plr->row);
	data->s_par->s_diff_row
		= data->s_par->s[data->s_par->s_prio[i]].s_col - (data->plr->col);
	data->s_par->inv_det = 1.0 / (data->raycaster->plane_x * data->plr->pdy
			- data->plr->pdx * data->raycaster->plane_y);
	data->s_par->tr_x
		= data->s_par->inv_det * (data->plr->pdy * data->s_par->s_diff_row
			- data->plr->pdx * data->s_par->s_diff_col);
	data->s_par->tr_y
		= data->s_par->inv_det * (-data->raycaster->plane_y
			* data->s_par->s_diff_row + data->raycaster->plane_x
			* data->s_par->s_diff_col);
	data->s_par->s_sc_x = (int)((WIDTH / 2)
			* (1 + data->s_par->tr_x / data->s_par->tr_y));
	sprite_computing2(data);
}

void	sprite_computing2(t_vault *data)
{
	data->s_par->s_h = abs((int)(HEIGHT / data->s_par->tr_y));
	data->s_par->s_ds_y = -data->s_par->s_h / 2 + HEIGHT / 2;
	if (data->s_par->s_ds_y < 0)
		data->s_par->s_ds_y = 0;
	data->s_par->s_de_y = data->s_par->s_h / 2 + HEIGHT / 2;
	if (data->s_par->s_de_y >= HEIGHT)
		data->s_par->s_de_y = HEIGHT - 1;
	data->s_par->s_w = abs((int)(HEIGHT / data->s_par->tr_y));
	data->s_par->s_ds_x = -data->s_par->s_w / 2 + data->s_par->s_sc_x;
	if (data->s_par->s_ds_x < 0)
		data->s_par->s_ds_x = 0;
	data->s_par->s_de_x = data->s_par->s_w / 2 + data->s_par->s_sc_x;
	if (data->s_par->s_de_x >= WIDTH)
		data->s_par->s_de_x = WIDTH - 1;
}

// void	draw_sprite_loop(void *temp)
// {
// 	int		tex_y;
// 	int		d;
// 	int		frame;
// 	int		max;
// 	t_vault	*data;

// 	max = 0;
// 	data = temp;
// 	while (max < 10)
// 	{
// 		frame = 0;
// 		while (frame < 5)
// 		{
// 			data->s_par->screen_y = data->s_par->s_ds_y;
// 			while (data->s_par->screen_y < data->s_par->s_de_y)
// 			{
// 				d = (int)((data->s_par->screen_y) * 256 - HEIGHT
// 						* 128 + data->s_par->s_h * 128);
// 				tex_y = fabs(((d * TEXHEIGHT) / data->s_par->s_h) / 256);
// 				if (data->tex->fire_tor[tex_y][data->s_par->tex_sx + frame * 256] != (int)0xff00ffff)
// 					mlx_put_pixel(data->game->sprite, data->s_par->screen_x,
// 						data->s_par->screen_y, data->tex->fire_tor[tex_y][data->s_par->tex_sx + frame * 256]);
// 				data->s_par->screen_y++;
// 			}
// 			// usleep(1000);
// 			// reinit_sprites(data);
// 			frame++;
// 		}
// 		max++;
// 	}
// }
