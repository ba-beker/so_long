# include "../includes/so_long.h"

void    r_background(t_data *data)
{
    int y;
    int i;

    i = 0;
    y = 0;
    while (data->map[y] != NULL)
    {
        while (data->map[y][i] != '\0')
        {
            if (data->map[y][i] == data->content.wall)
                p_image(data, data->image.image_wall, i, y);
            if (data->map[y][i] == data->content.space)
                p_image(data, data->image.image_floor, i, y);
            i++;
        }
        i = 0;
        y++;
    }
}

void    r_other(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map[j] != NULL)
    {
        while (data->map[j][i])
        {
            if (data->map[j][i] ==data->content.collect)
                p_image(data, data->image.image_collect, i, j);
            if (data->map[j][i] == data->content.player)
            {
                data->pos.x = i * data->image.width;
                data->pos.y = j * data->image.height;
                p_image(data, data->image.image_player, i, j);
            }
            if (data->map[j][i] == data->content.exit)
                p_image(data, data->image.image_exit, i, j);
            i++;
        }
        i = 0;
        j++;
    }
}
int render(t_data *data)
{
    r_background(data);
    r_other(data);
    return (0);
}

void    rend(t_data *data)
{
    data->mlx_win = mlx_new_window(data->mlx_ptr, (data->width * data->image.width), (data->height * data->image.height), "so_long");
    if (data->mlx_win == NULL)
    {
        free(data->mlx_ptr);
        return;
    }
    mlx_loop_hook(data->mlx_ptr, &render, data);
    mlx_hook(data->mlx_win,KeyRelease, KeyReleaseMask, &pressed_key, data);
    mlx_hook(data->mlx_win, 17, 0, &end, data);
    mlx_loop(data->mlx_ptr);
    end(data);
}

void    p_image(t_data *data, void *image, int x, int y)
{
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, image, data->image.width * x, data->image.height * y);
}