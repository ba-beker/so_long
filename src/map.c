#include "../includes/so_long.h"

char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = gnl(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = gnl(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	output_error("Error\nWrong lecture map\n");
	return (NULL);
}
void    *free_map(t_data *data)
{
    int i;

    i = 0;
    while (data->map[i] != NULL)
    {
        free(data->map[i]);
        i++;
    }
    free(data->map);
    data->map = NULL;
    return (0);
}
char    **map_parse(int fd, t_data *data)
{
    int i;

    i = 1;
    data->map = ft_split(get_map(fd), '\n');
    count_item(data);
    if (!(check_forma(data->map)))
        return (free_map(data));
    if (!(wall_line(data->map[0], data->content.wall)))
        return (free_map(data));
    while(data->map[i] != NULL)
    {
        if (!(wall_column(data->map[i], data->content.wall, data)))
            return (free_map(data));
        else if (!(check_inside(data->map[i], &(data->content))))
            return(free_map(data));
        i++;
    }
    data->height= i;
    if (!(wall_line(data->map[i - 1], data->content.wall)))
        return (free_map(data));
    return(data->map);
}

char    **map_core(char **str, t_data *data)
{
    int fd;

    fd = 0;
    data->map = NULL;
    if (sstrchr(str[1], ".ber") == 0)
        return (output_error("Error: No correct format map founded\n"));
    else
    {
        fd = open(str[1], O_RDONLY);
        if (fd > 0)
            data->map = map_parse(fd, data);
        else
            return (output_error("Errror: failed to open file\n"));
        if ((data->content.count_c == 0 || data->content.count_e != 1
                || data->content.count_p != 1) && data->map != NULL)
        {
            free_map(data);
            return (output_error("Error: 1 Player/Exit and at least 1 object"));
        }
    }
    return (data->map);
}

int	sstrchr(char *str, char *cmp)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (cmp[y] == '\0' && str[i] == '\0')
		return (1);
	while (str[i])
	{
		while (str[i + y] == cmp[y] && str[i + y] && cmp[y])
			y++;
		if (cmp[y] == '\0' && str[i + y] == '\0')
			return (1);
		else
			y = 0;
		i++;
	}
	return (0);
}