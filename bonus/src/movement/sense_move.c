/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sense_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:47:30 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/18 17:35:12 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_set_direction(t_game *game, char *direction, int id)
{
	game->player[id]->up = 0;
	game->player[id]->down = 0;
	game->player[id]->left = 0;
	game->player[id]->right = 0;
	if (ft_strncmp(direction, "up", 2) == 0)
		game->player[id]->up = 1;
	else if (ft_strncmp(direction, "down", 4) == 0)
		game->player[id]->down = 1;
	else if (ft_strncmp(direction, "left", 4) == 0)
		game->player[id]->left = 1;
	else if (ft_strncmp(direction, "right", 5) == 0)
		game->player[id]->right = 1;
}

void	ft_sense_move2(int keycode, t_game *game)
{
	if (keycode == XK_Up)
	{
		ft_set_direction(game, "up", 1);
		ft_go_up(game, 1, PLAYER2_UP_1);
	}
	else if (keycode == XK_Down)
	{
		ft_set_direction(game, "down", 1);
		ft_go_down(game, 1, PLAYER2_DOWN_1);
	}
	else if (keycode == XK_Right)
	{
		ft_set_direction(game, "right", 1);
		ft_go_right(game, 1, PLAYER2_RIGHT_1);
	}
	else if (keycode == XK_Left)
	{
		ft_set_direction(game, "left", 1);
		ft_go_left(game, 1, PLAYER2_LEFT_1);
	}
}

void	ft_sense_move(int keycode, t_game *game)
{
	if (keycode == XK_w)
	{
		ft_set_direction(game, "up", 0);
		ft_go_up(game, 0, PLAYER_UP_1);
	}
	else if (keycode == XK_s)
	{
		ft_set_direction(game, "down", 0);
		ft_go_down(game, 0, PLAYER_DOWN_1);
	}
	else if (keycode == XK_d)
	{
		ft_set_direction(game, "right", 0);
		ft_go_right(game, 0, PLAYER_RIGHT_1);
	}
	else if (keycode == XK_a)
	{
		ft_set_direction(game, "left", 0);
		ft_go_left(game, 0, PLAYER_LEFT_1);
	}
	else
		ft_sense_move2(keycode, game);
}
