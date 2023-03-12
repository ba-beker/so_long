/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 07:40:45 by mobabeke          #+#    #+#             */
/*   Updated: 2023/03/12 14:49:31 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		output_error("Error\nThis programe take 1 argument .ber\n ");
		return (0);
	}
	else
	{
		data.count = 0;
		data.mlx_ptr = mlx_init();
		init_content(&(data.content));
		data.map = map_core(argv, &data);
		if (data.map != NULL)
		{
			init_image(&data);
			rend(&data);
		}
		else
			end(&data);
	}
	return (1);
}

int	count_pix(t_data *data)
{
	int	count;
	int	j;
	int	x;

	count = 0;
	j = 0;
	x = 0;
	while (data->map[x])
	{
		while (data->map[x][j])
		{
			if (data->map[x][j] == data->content.collect)
				count++;
			j++;
		}
			j = 0;
			x++;
	}
	return (count);
}

int	end(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		mlx_destroy_image(data->mlx_ptr, data->image.image_wall);
		mlx_destroy_image(data->mlx_ptr, data->image.image_floor);
		mlx_destroy_image(data->mlx_ptr, data->image.image_collect);
		mlx_destroy_image(data->mlx_ptr, data->image.image_player);
		mlx_destroy_image(data->mlx_ptr, data->image.image_exit);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	pressed_key(int k_system, t_data *data)
{
	if (k_system == XK_Escape)
		end(data);
	if (k_system == XK_z)
		r_top(data);
	if (k_system == XK_d)
		r_right(data);
	if (k_system == XK_q)
		r_left(data);
	if (k_system == XK_s)
		r_buttom(data);
	return (0);
}
