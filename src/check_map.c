/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:27:09 by mobabeke          #+#    #+#             */
/*   Updated: 2023/03/12 14:42:06 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_forma(char **map)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	while (map[0][c])
		c++;
	while (map[y] != NULL)
	{
		while (map[y][x])
		x++;
		if (x != c)
		{
			output_error("Error: the map is neither a square nor a rectangle");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}

int	wall_column(char *line, char wall, t_data *data)
{
	int	j;

	j = 0;
	while (line[j])
		j++;
	if (line[0] != wall || line[j - 1] != wall)
	{
		output_error("Error: Map not closed from right/left!");
		return (0);
	}
	data->width = j;
	return (1);
}

int	wall_line(char *line, char wall)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] != wall)
		{
			output_error("Error: Map not closed from top/buttom!");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_inside(char *line, t_cnt *content)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (content->count_e > 1 || content->count_p > 1)
		{
			output_error("Error: wrong number of exits or players!");
			return (0);
		}
		if (line[j] != content->wall && line[j] != content->player && line[j]
			!= content->exit && line[j] != content->collect && line[j]
			!= content->space)
		{
			output_error("Error: Unvalid map element!");
			return (0);
		}
		j++;
	}
	return (1);
}

void	count_item(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[x])
	{
		while (data->map[x][y])
		{
			if (data->map[x][y] == data->content.collect)
				data->content.count_c += 1;
			if (data->map[x][y] == data->content.player)
				data->content.count_p += 1;
			if (data->map[x][y] == data->content.exit)
				data->content.count_e += 1;
			y++;
		}
		y = 0;
		x++;
	}
}
