/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:01:38 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/13 16:45:13 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# define _GNU_SOURCE

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../Libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# define RES 64
# define CHEST "textures/map/ground_chest_close.xpm"
# define EXIT "textures/map/ground_exit.xpm"
# define GROUND "textures/map/ground.xpm"
# define PLAYER "textures/player/player_front_1.xpm"
# define WALL_TOP_RIGHT "textures/map/wall_curve_top_right.xpm"
# define WALL_BOTTOM_RIGHT "textures/map/wall_curve_bottom_right.xpm"
# define WALL_TOP_LEFT "textures/map/wall_curve_top_left.xpm"
# define WALL_BOTTOM_LEFT "textures/map/wall_curve_bottom_left.xpm"
# define WALL_HORIZONTAL_DOWN "textures/map/wall_horizontal_down.xpm"
# define WALL_HORIZONTAL_UP "textures/map/wall_horizontal_up.xpm"
# define WALL_VERTICAL_LEFT "textures/map/wall_vertical_left.xpm"
# define WALL_VERTICAL_RIGHT "textures/map/wall_vertical_right.xpm"
# define WALL_MIDDLE "textures/map/wall_middle.xpm"

typedef struct s_map
{
	int		width;
	int		height;
	int		isemptyplace;
	int		iswall;
	int		isexit;
	int		iscollectible;
	int		isplayer;
	int		start_x;
	int		start_y;
	char	**design;
}				t_map;

typedef struct s_player
{
	int		y_coords;
	int		x_coords;
	int		moves;
	char	*suc_msg;
	char	*def_msg;
	int		right;
	int		left;
	int		up;
	int		down;
}				t_player;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
	t_data		*img;
	int			pos;
}				t_game;

int		ft_init_player(t_player *player);
int		ft_init_map(t_map *map, char *file);
char	**ft_malloc_map(int height, int width);
void	ft_fill_design(t_map *map, char *file);
int		ft_check_vertical_walls(t_map *map);
int		ft_check_horizontal_walls(t_map *map);
int		ft_check_path(t_map *map, char *file);
int		ft_check_map(t_map *map, char *file);
void	ft_start_game(t_map *map, t_player *player, t_game vars);
int		ft_render_map(t_game *game);
int		ft_endgame(t_game *game);
void	ft_free_all(t_game *vars);
void	ft_free_design(t_map *map);
void	ft_free_img(t_game *vars);
void	ft_sense_move(int keycode, t_game *game);
void	ft_go_up(t_game *game);
int		ft_check_up(t_game *game);
int		ft_check_down(t_game *game);
int		ft_check_right(t_game *game);
int		ft_check_left(t_game *game);

#endif