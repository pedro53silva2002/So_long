/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:04:28 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/18 17:35:33 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_sprite_ani(t_game *game, char *path1, char *path2, int id)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player[id]->x_coords;
	y = game->player[id]->y_coords * game->map->width;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	if (game->player[id]->bi == 0)
	{
		game->img[y + x].img = mlx_xpm_file_to_image(game->mlx,
				path1, &res, &res);
		game->player[id]->bi = 1;
	}
	else if (game->player[id]->bi == 1)
	{
		game->img[y + x].img = mlx_xpm_file_to_image(game->mlx,
				path2, &res, &res);
		game->player[id]->bi = 0;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	usleep(100000);
}

int	ft_sprite_it(t_game *game, int id)
{
	if (game->player[id]->up == 1 && id == 0)
		ft_sprite_ani(game, PLAYER_UP_1, PLAYER_UP_2, 0);
	else if (game->player[id]->down == 1 && id == 0)
		ft_sprite_ani(game, PLAYER_DOWN_1, PLAYER_DOWN_2, 0);
	else if (game->player[id]->left == 1 && id == 0)
		ft_sprite_ani(game, PLAYER_LEFT_1, PLAYER_LEFT_2, 0);
	else if (game->player[id]->right == 1 && id == 0)
		ft_sprite_ani(game, PLAYER_RIGHT_1, PLAYER_RIGHT_2, 0);
	else if (game->player[id]->up == 1 && id == 1)
		ft_sprite_ani(game, PLAYER2_UP_1, PLAYER2_UP_2, 1);
	else if (game->player[id]->down == 1 && id == 1)
		ft_sprite_ani(game, PLAYER2_DOWN_1, PLAYER2_DOWN_2, 1);
	else if (game->player[id]->left == 1 && id == 1)
		ft_sprite_ani(game, PLAYER2_LEFT_1, PLAYER2_LEFT_2, 1);
	else if (game->player[id]->right == 1 && id == 1)
		ft_sprite_ani(game, PLAYER2_RIGHT_1, PLAYER2_RIGHT_2, 1);
	return (0);
}
