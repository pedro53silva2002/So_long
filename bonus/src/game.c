/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:10 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/20 14:11:35 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_endgame(t_game *game)
{
	ft_free_all(game);
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

void	ft_make_map(t_game *game)
{
	if (!ft_render_map(game))
	{
		ft_printf("Error\nSomething wrong with game.");
		ft_endgame(game);
	}
}

void	ft_start_game(t_map *map,
	t_player *player, t_player *player2, t_game game)
{
	game.map = map;
	game.total_moves = 0;
	game.player = malloc(sizeof(t_player *) * 3);
	game.player[0] = player;
	game.player[0]->x_coords = game.map->start_x;
	game.player[0]->y_coords = game.map->start_y;
	game.player[1] = player2;
	game.player[1]->x_coords = game.map->start2_x;
	game.player[1]->y_coords = game.map->start2_y;
	game.player[2] = NULL;
	ft_printf("X2: %d\tY2: %d\n", game.map->start2_x, game.map->start2_y);
	game.img = malloc(sizeof(t_data) * (game.map->height * game.map->width));
	if (!game.img)
		ft_endgame(&game);
	game.pos = 0;
	game.win = mlx_new_window(game.mlx, (RES * map->width),
			(RES * map->height), "so_long_bonus");
	ft_make_map(&game);
	game.map->design[game.map->start_y][game.map->start_x] = '0';
	game.map->design[game.map->start2_y][game.map->start2_x] = '0';
	mlx_mouse_show(game.mlx, game.win);
	mlx_hook(game.win, 2, 1L << 0, &ft_handle_keys, &game);
	mlx_hook(game.win, 17, 1L << 0, &ft_display_defeat, &game);
	mlx_loop_hook(game.mlx, &ft_display_moves, &game);
	mlx_loop(game.mlx);
}
