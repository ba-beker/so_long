/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 09:22:53 by mobabeke          #+#    #+#             */
/*   Updated: 2023/03/12 09:24:58 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct img_s
{
	void	*image_floor;
	void	*image_player;
	void	*image_exit;
	void	*image_wall;
	void	*image_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct cnt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				t_cnt;

typedef struct pos_s
{
	int	x;
	int	y;
}				t_pos;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	t_cnt	content;
	t_img	image;
	t_pos	pos;
	int		count;
}				t_data;

int		is_same_char(char *str);
void	init_content(t_cnt *content);
void	rend(t_data *data);
void	*output_error(char *str);
char	**map_core(char **str, t_data *data);
char	*get_map(int fd);
void	*free_map(t_data *data);
char	**map_parse(int fd, t_data *data);
char	**map_core(char **str, t_data *data);
int		wall_column(char *line, char wall, t_data *data);
int		wall_line(char *line, char wall);
int		check_inside(char *line, t_cnt *content);
void	count_item(t_data *data);
int		check_forma(char **map);
int		sstrchr(char *str, char *cmp);
int		end(t_data *data);
int		count_pix(t_data *data);
void	is_win(t_data *data);
void	r_top(t_data *data);
void	r_right(t_data *data);
void	r_left(t_data *data);
void	r_buttom(t_data *data);
void	init_image(t_data *data);
int		pressed_key(int k_system, t_data *data);
void	p_image(t_data *data, void *image, int x, int y);

#endif
