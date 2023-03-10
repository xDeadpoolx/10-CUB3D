/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fc_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:37:22 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/23 09:01:58 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_f_params(t_vault *data, int i, int j, int slen)
{
	char	*temp;
	char	*temp2;

	j = 1;
	if (data->scene_param->f_exist == 1)
	{
		data->error_code = 17;
		errors(data);
	}
	data->scene_param->f_exist = 1;
	while (data->scene[i][j])
	{
		while (check_white_spaces(data->scene[i][j]) == 0)
			j++;
		temp = ft_substr(data->scene[i], j, slen);
		temp2 = ft_strtrim(temp, "\n");
		data->scene_param->f_color = ft_strdup(temp2);
		free (temp);
		free (temp2);
		break ;
	}
}

void	check_c_params(t_vault *data, int i, int j, int slen)
{
	char	*temp;
	char	*temp2;

	j = 1;
	if (data->scene_param->c_exist == 1)
	{
		data->error_code = 17;
		errors(data);
	}
	data->scene_param->c_exist = 1;
	while (data->scene[i][j])
	{
		while (check_white_spaces(data->scene[i][j]) == 0)
			j++;
		temp = ft_substr(data->scene[i], j, slen);
		temp2 = ft_strtrim(temp, "\n");
		data->scene_param->c_color = ft_strdup(temp2);
		free (temp);
		free (temp2);
		break ;
	}
}

void	check_color_code(t_vault *data)
{
	if (correct_rgb_char(data->scene_param->c_color) == 0
		|| correct_rgb_char(data->scene_param->f_color) == 0)
		data->error_code = 15;
	errors(data);
	correct_rgb_range(data, data->scene_param->c_color, 'C');
	correct_rgb_range(data, data->scene_param->f_color, 'F');
	errors(data);
}

int	correct_rgb_char(char *rgb_code)
{
	int	i;

	i = 0;
	while (rgb_code && rgb_code[i])
	{
		while (check_white_spaces(rgb_code[i]) == 0)
		{
			i++;
			if (rgb_code[i] == '\0')
				return (0);
		}
		if (ft_isdigit(rgb_code[i]) == 1 || rgb_code[i] == ',')
			i++;
		else
			return (0);
	}
	return (1);
}

void	rgb_to_hex(t_vault *data, char flag)
{
	unsigned int	a;
	int				r;
	int				g;
	int				b;

	r = 0;
	g = 0;
	b = 0;
	a = 0xff;
	if (flag == 'C')
	{
		r = data->scene_param->r_ceiling;
		g = data->scene_param->g_ceiling;
		b = data->scene_param->b_ceiling;
		data->scene_param->hex_ceiling = (r << 24) | (g << 16) | (b << 8) | a;
	}
	else if (flag == 'F')
	{
		r = data->scene_param->r_floor;
		g = data->scene_param->g_floor;
		b = data->scene_param->b_floor;
		data->scene_param->hex_floor = (r << 24) | (g << 16) | (b << 8) | a;
	}
}
