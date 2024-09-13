/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:10 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/13 16:33:57 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_endgame(t_game *game)
{
	ft_free_all(game);
	return (0);
}

int	ft_display_defeat(t_game *game)
{
	ft_printf(game->player->def_msg);
	ft_endgame(game);
	return (0);
}

int	ft_handle_keys(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		ft_display_defeat(game);
	}
	else
	{
		ft_sense_move(keycode, game);
	}
	return (0);
}

void	ft_start_game(t_map *map, t_player *player, t_game game)
{
	game.map = map;
	game.player = player;
	game.player->x_coords = game.map->start_x;
	game.player->y_coords = game.map->start_y;
	game.img = malloc(sizeof(t_data) * (game.map->height * game.map->width));
	if (!game.img)
		ft_endgame(&game);
	game.pos = 0;
	game.win = mlx_new_window(game.mlx, (RES * map->width),
			(RES * map->height), "so_long");
	ft_render_map(&game);
	mlx_mouse_show(game.mlx, game.win);
	mlx_hook(game.win, 2, 1L << 0, &ft_handle_keys, &game);
	mlx_hook(game.win, 17, 1L << 0, &ft_display_defeat, &game);
	mlx_loop(game.mlx);
}

	//ft_put_img_in_window(mlx, mlx_win, 2, 2);
	/* img.img = mlx_new_image(mlx, 64,64);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 10, 50, 0x00FF0000); */