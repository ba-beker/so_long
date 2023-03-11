#include "../includes/so_long.h"

void    init_content(t_cnt *content)
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
void    init_image(t_data *data)
{
    data->image.height = 80;
    data->image.width = 80;
    data->image.floor = "./rsrc/floor_texture.xpm";
    data->image.wall = "./rsrc/wall_texture.xpm";
    data->image.collect = "./rsrc/collect.xpm";
    data->image.player = "./rsrc/mario_player.xpm";
    data->image.exit = "./rsrc/exit_texture.xpm";
    data->image.image_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->image.wall,
            &(data->image.width), &(data->image.height));
    data->image.image_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->image.floor,
            &(data->image.width), &(data->image.height));
    data->image.image_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->image.exit,
            &(data->image.width), &(data->image.height));
    data->image.image_collect = mlx_xpm_file_to_image(data->mlx_ptr, data->image.collect,
            &(data->image.width), &(data->image.height));
    data->image.image_player = mlx_xpm_file_to_image(data->mlx_ptr, data->image.player,
            &(data->image.width), &(data->image.height));
}