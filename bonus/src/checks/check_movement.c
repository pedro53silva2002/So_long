/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:41:05 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/18 17:30:44 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_counter_id(int id)
{
	int	counter_id;

	counter_id = 1;
	if (id == 1)
		counter_id = 0;
	return (counter_id);
}

int	ft_check_up(t_game *game, int id, int cid)
{
	int	x;
	int	y;

	x = game->player[id]->x_coords;
	y = game->player[id]->y_coords;
	if (game->player[id]->y_coords == 1)
		return (0);
	if (game->map->design[y - 1][x] == 'C')
	{
		game->map->iscollectible--;
		game->map->design[y - 1][x] = '0';
	}
	if (game->map->design[y - 1][x] == '1'
		|| ((y - 1) == game->player[cid]->y_coords
		&& x == game->player[cid]->x_coords))
		return (0);
	else if (game->map->design[y - 1][x] == 'B')
		return (ft_display_defeat(game), 0);
	else if (game->map->design[y - 1][x] == 'E' && !game->map->iscollectible)
		return (ft_display_success(game, id), 0);
	else if (game->map->design[y - 1][x] == 'E' && game->map->iscollectible)
		return (0);
	return (1);
}

int	ft_check_down(t_game *game, int id, int cid)
{
	int	x;
	int	y;

	x = game->player[id]->x_coords;
	y = game->player[id]->y_coords;
	if (game->player[id]->y_coords == game->map->height - 1)
		return (0);
	if (game->map->design[y + 1][x] == 'C')
	{
		game->map->iscollectible--;
		game->map->design[y + 1][x] = '0';
	}
	if (game->map->design[y + 1][x] == '1'
		|| ((y + 1) == game->player[cid]->y_coords
		&& x == game->player[cid]->x_coords))
		return (0);
	else if (game->map->design[y + 1][x] == 'B')
		return (ft_display_defeat(game), 0);
	else if (game->map->design[y + 1][x] == 'E' && !game->map->iscollectible)
		return (ft_display_success(game, id), 0);
	else if ((game->map->design[y + 1][x] == 'E' && game->map->iscollectible))
		return (0);
	return (1);
}

int	ft_check_right(t_game *game, int id, int cid)
{
	int	x;
	int	y;

	x = game->player[id]->x_coords;
	y = game->player[id]->y_coords;
	if (game->player[id]->x_coords == game->map->width - 1)
		return (0);
	if (game->map->design[y][x + 1] == 'C')
	{
		game->map->iscollectible--;
		game->map->design[y][x + 1] = '0';
	}
	if (game->map->design[y][x + 1] == '1'
		|| (y == game->player[cid]->y_coords
		&& (x + 1) == game->player[cid]->x_coords))
		return (0);
	else if (game->map->design[y][x + 1] == 'B')
		return (ft_display_defeat(game), 0);
	else if (game->map->design[y][x + 1] == 'E' && !game->map->iscollectible)
		return (ft_display_success(game, id), 0);
	else if ((game->map->design[y][x + 1] == 'E' && game->map->iscollectible))
		return (0);
	return (1);
}

int	ft_check_left(t_game *game, int id, int cid)
{
	int	x;
	int	y;

	x = game->player[id]->x_coords;
	y = game->player[id]->y_coords;
	if (game->player[id]->x_coords == 1)
		return (0);
	if (game->map->design[y][x - 1] == 'C')
	{
		game->map->iscollectible--;
		game->map->design[y][x - 1] = '0';
	}
	if (game->map->design[y][x - 1] == '1'
		|| (y == game->player[cid]->y_coords
		&& (x - 1) == game->player[cid]->x_coords))
		return (0);
	else if (game->map->design[y][x - 1] == 'B')
		return (ft_display_defeat(game), 0);
	else if (game->map->design[y][x - 1] == 'E' && !game->map->iscollectible)
		return (ft_display_success(game, id), 0);
	else if ((game->map->design[y][x - 1] == 'E' && game->map->iscollectible))
		return (0);
	return (1);
}
