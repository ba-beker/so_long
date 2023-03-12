/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_change.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:20:05 by mobabeke          #+#    #+#             */
/*   Updated: 2023/03/12 14:47:56 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	r_buttom(t_data *data)
{
	int	x;
	int	y;

	x = data->pos.x / data->image.height;
	y = data->pos.y / data->image.width;
	if (data->map[y + 1][x] != data->content.wall)
	{
		if (!(data->map[y + 1][x] == data->content.exit))
		{
			data->map[y + 1][x] = data->content.player;
			data->map[y][x] = data->content.space;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (count_pix(data) == 0)
				is_win(data);
		}
	}
}

void	is_win(t_data *data)
{
	ft_printf("You have wined the game with %d steps\n", data->count);
	end(data);
}

void	r_top(t_data *data)
{
	int	x;
	int	y;

	x = data->pos.x / data->image.height;
	y = data->pos.y / data->image.width;
	if (data->map[y - 1][x] != data->content.wall)
	{
		if (!(data->map[y - 1][x] == data->content.exit))
		{
			data->map[y - 1][x] = data->content.player;
			data->map[y][x] = data->content.space;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (count_pix(data) == 0)
				is_win(data);
		}
	}
}

void	r_right(t_data *data)
{
	int	x;
	int	y;

	x = data->pos.x / data->image.height;
	y = data->pos.y / data->image.width;
	if (data->map[y][x + 1] != data->content.wall)
	{
		if (!(data->map[y][x + 1] == data->content.exit))
		{
			data->map[y][x + 1] = data->content.player;
			data->map[y][x] = data->content.space;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (count_pix(data) == 0)
				is_win(data);
		}
	}
}

void	r_left(t_data *data)
{
	int	x;
	int	y;

	x = data->pos.x / data->image.height;
	y = data->pos.y / data->image.width;
	if (data->map[y][x - 1] != data->content.wall)
	{
		if (!(data->map[y][x - 1] == data->content.exit))
		{
			data->map[y][x - 1] = data->content.player;
			data->map[y][x] = data->content.space;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (count_pix(data) == 0)
				is_win(data);
		}
	}
}
