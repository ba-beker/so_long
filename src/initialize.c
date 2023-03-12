/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:31:52 by mobabeke          #+#    #+#             */
/*   Updated: 2023/03/12 14:44:04 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_content(t_cnt *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->space = '0';
	content->wall = '1';
	content->collect = 'C';
	content->count_c = 0;
	content->count_e = 0;
	content->count_p = 0;
}

void	init_image(t_data *data)
{
	data->image.height = 80;
	data->image.width = 80;
	data->image.floor = "./assets/floor.xpm";
	data->image.wall = "./assets/wall.xpm";
	data->image.collect = "./assets/collect.xpm";
	data->image.player = "./assets/mario.xpm";
	data->image.exit = "./assets/exit.xpm";
	data->image.image_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->image.wall,
			&(data->image.width), &(data->image.height));
	data->image.image_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			data->image.floor,
			&(data->image.width), &(data->image.height));
	data->image.image_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			data->image.exit,
			&(data->image.width), &(data->image.height));
	data->image.image_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->image.collect,
			&(data->image.width), &(data->image.height));
	data->image.image_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->image.player,
			&(data->image.width), &(data->image.height));
}
