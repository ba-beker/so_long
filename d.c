int	main_part(char	*l, t_list **a, t_list **b)
{
	while (1)
	{
		l = get_next_line(0);
		if (l == NULL)
			break ;
		
		free(l);
	}
	return (0);
}
char *get_map(int fd)
{
    char    *temp_buffer;
    char    *l_map;
    char    *buffer;
    int     c_count;

    l_map = ft_strdup("");
    buffer = ft_strdup("");
    c_count = gnl(fd, &l_map);
    if (c_count > 0)
    {
        temp_buffer = buffer;
        while(c_count > 0)
        {
            buffer = ft_strjoin(buffer, l_map);
            free(temp_buffer);
            free(l_map);
            l_map = ft_strdup("");
            c_count = gnl(fd, &l_map);
            temp_buffer = buffer;
        }
        return (buffer);
    }
    output_error("Error: Wrong map!");
    return (NULL);
}