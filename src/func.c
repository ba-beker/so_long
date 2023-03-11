#include "../includes/so_long.h"

int is_same_char(char *str)
{
    int     i;
    char    buff;

    i = 0;
    buff = '1';
    if (str == NULL)
        return (-1);
    while (str[i])
    {
        if (str[i] != buff && str[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}

void    *output_error(char *str)
{
    write(2, str, ft_strlen(str));
    return (0);
}