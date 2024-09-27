/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:36:03 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/20 14:15:58 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_display_success(t_game *game, int id)
{
	game->player[id]->moves++;
	game->total_moves++;
	ft_printf("Moves: %d\n", game->total_moves);
	ft_printf(game->player[0]->suc_msg);
	ft_endgame(game);
	return (0);
}

int	ft_display_defeat(t_game *game)
{
	ft_printf(game->player[0]->def_msg);
	ft_endgame(game);
	return (0);
}

void	ft_display_string(t_game *game, char *str, char *str2)
{
	int	x;
	int	y;

	x = (game->map->width - 1);
	y = 35;
	mlx_string_put(game->mlx, game->win, (x - 1) * 64,
		y, 16777215, "PLAYER 1: ");
	mlx_string_put(game->mlx, game->win, x * 64,
		y, 16711680, str);
	mlx_string_put(game->mlx, game->win, (x - 1) * 64,
		y + 15, 16777215, "PLAYER 2: ");
	mlx_string_put(game->mlx, game->win, x * 64,
		y + 15, 16711680, str2);
}

int	ft_display_moves(t_game *game)
{
	char	*str;
	char	*str2;
	int		width;

	width = game->map->width;
	str = ft_itoa(game->player[0]->moves);
	str2 = ft_itoa(game->player[1]->moves);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img[width - 2].img, (width - 2) * 64, 0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img[width - 1].img, (width - 1) * 64, 0);
	ft_display_string(game, str, str2);
	free(str);
	str = NULL;
	free(str2);
	str2 = NULL;
	ft_sprite_it(game, 1);
	ft_sprite_it(game, 0);
	return (0);
}
