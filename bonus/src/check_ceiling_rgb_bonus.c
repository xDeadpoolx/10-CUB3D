/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceiling_rgb_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:11:11 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/24 15:06:20 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	extract_r_ceiling(t_vault *data, char *rgb_code, int *i, int *len)
{
	char	*temp;

	temp = NULL;
	while (rgb_code && rgb_code[*i] && rgb_code[*i] != ',')
	{
		if (ft_isdigit(rgb_code[*i]) == 1
			|| check_white_spaces(rgb_code[*i]) == 0)
			(*i)++;
	}
	temp = ft_substr(rgb_code, *len, *i - *len);
	if (temp[0] != '\0')
		data->scene_param->r_ceiling = ft_atoi(temp);
	free (temp);
	(*i)++;
	*len = *i;
	if (data->scene_param->r_ceiling > 255 || data->scene_param->r_ceiling < 0)
		data->error_code = 16;
	errors(data);
	extract_g_ceiling(data, rgb_code, i, len);
}

void	extract_g_ceiling(t_vault *data, char *rgb_code, int *i, int *len)
{
	char	*temp;

	temp = NULL;
	while (rgb_code && rgb_code[*i] && rgb_code[*i] != ',')
	{
		if (ft_isdigit(rgb_code[*i]) == 1
			|| check_white_spaces(rgb_code[*i]) == 0)
			(*i)++;
	}
	temp = ft_substr(rgb_code, *len, *i - *len);
	if (temp[0] != '\0')
		data->scene_param->g_ceiling = ft_atoi(temp);
	free (temp);
	(*i)++;
	*len = *i;
	if (data->scene_param->g_ceiling > 255 || data->scene_param->g_ceiling < 0)
		data->error_code = 16;
	errors(data);
	extract_b_ceiling(data, rgb_code, i, len);
}

void	extract_b_ceiling(t_vault *data, char *rgb_code, int *i, int *len)
{
	char	*temp;

	temp = NULL;
	while (rgb_code && rgb_code[*i] && rgb_code[*i] != ',')
	{
		if (ft_isdigit(rgb_code[*i]) == 1
			|| check_white_spaces(rgb_code[*i]) == 0)
			(*i)++;
	}
	temp = ft_substr(rgb_code, *len, *i - *len);
	if (temp[0] != '\0')
		data->scene_param->b_ceiling = ft_atoi(temp);
	free (temp);
	temp = NULL;
	if (data->scene_param->b_ceiling > 255 || data->scene_param->b_ceiling < 0)
		data->error_code = 16;
	errors(data);
}
