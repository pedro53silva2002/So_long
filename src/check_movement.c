/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:41:05 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/13 16:20:56 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x_coords;
	y = game->player->y_coords;
	if (game->player->y_coords == 1)
		return (0);
	if (game->map->design[y - 1][x] == 'C')
	{
		game->map->iscollectible--;
		game->map->design[y - 1][x] = '0';
	}
	if (game->map->design[y - 1][x] == '1')
		return (0);
	else if (game->map->design[y - 1][x] == 'E' && !game->map->iscollectible)
	{
		game->player->moves++;
		ft_printf("Moves: %d\n", game->player->moves);
		ft_printf(game->player->suc_msg);
		return (ft_endgame(game), 0);
	}
	else if (game->map->design[y - 1][x] == 'E' && game->map->iscollectible)
		return (0);
	return (1);
}

int	ft_check_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x_coords;
	y = game->player->y_coords;
	if (game->player->y_coords == game->map->height - 1)
		return (0);
	if (game->map->design[y + 1][x] == 'C')
	{
		game->map->iscollectible--;
		game->map->design[y + 1][x] = '0';
	}
	if (game->map->design[y + 1][x] == '1')
		return (0);
	else if (game->map->design[y + 1][x] == 'E' && !game->map->iscollectible)
	{
		game->player->moves++;
		ft_printf("Moves: %d\n", game->player->moves);
		ft_printf(game->player->suc_msg);
		return (ft_endgame(game), 0);
	}
	else if ((game->map->design[y + 1][x] == 'E' && game->map->iscollectible))
		return (0);
	return (1);
}

int	ft_check_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x_coords;
	y = game->player->y_coords;
	if (game->player->x_coords == game->map->width - 1)
		return (0);
	if (game->map->design[y][x + 1] == 'C')
	{
		game->map->iscollectible--;
		game->map->design[y][x + 1] = '0';
	}
	if (game->map->design[y][x + 1] == '1')
		return (0);
	else if (game->map->design[y][x + 1] == 'E' && !game->map->iscollectible)
	{
		game->player->moves++;
		ft_printf("Moves: %d\n", game->player->moves);
		ft_printf(game->player->suc_msg);
		return (ft_endgame(game), 0);
	}
	else if ((game->map->design[y][x + 1] == 'E' && game->map->iscollectible))
		return (0);
	return (1);
}

int	ft_check_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x_coords;
	y = game->player->y_coords;
	if (game->player->x_coords == 1)
		return (0);
	if (game->map->design[y][x - 1] == 'C')
	{
		game->map->iscollectible--;
		game->map->design[y][x - 1] = '0';
	}
	if (game->map->design[y][x - 1] == '1')
		return (0);
	else if (game->map->design[y][x - 1] == 'E' && !game->map->iscollectible)
	{
		game->player->moves++;
		ft_printf("Moves: %d\n", game->player->moves);
		ft_printf(game->player->suc_msg);
		return (ft_endgame(game), 0);
	}
	else if ((game->map->design[y][x - 1] == 'E' && game->map->iscollectible))
		return (0);
	return (1);
}
