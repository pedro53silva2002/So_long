/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:41:05 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/13 16:42:18 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_go_up(t_game *game)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player->x_coords;
	y = game->player->y_coords * game->map->width;
	if (!ft_check_up(game))
		return ;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, GROUND, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	y -= game->map->width;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, PLAYER, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	game->player->y_coords--;
	game->player->moves++;
	ft_printf("Moves: %d\n", game->player->moves);
}

void	ft_go_down(t_game *game)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player->x_coords;
	y = game->player->y_coords * game->map->width;
	if (!ft_check_down(game))
		return ;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, GROUND, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	y += game->map->width;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, PLAYER, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	game->player->y_coords++;
	game->player->moves++;
	ft_printf("Moves: %d\n", game->player->moves);
}

void	ft_go_right(t_game *game)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player->x_coords;
	y = game->player->y_coords * game->map->width;
	if (!ft_check_right(game))
		return ;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, GROUND, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	x += 1;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, PLAYER, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	game->player->x_coords++;
	game->player->moves++;
	ft_printf("Moves: %d\n", game->player->moves);
}

void	ft_go_left(t_game *game)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player->x_coords;
	y = game->player->y_coords * game->map->width;
	if (!ft_check_left(game))
		return ;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, GROUND, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	x -= 1;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, PLAYER, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	game->player->x_coords--;
	game->player->moves++;
	ft_printf("Moves: %d\n", game->player->moves);
}

void	ft_sense_move(int keycode, t_game *game)
{
	if (keycode == XK_w)
	{
		ft_go_up(game);
	}
	else if (keycode == XK_s)
		ft_go_down(game);
	else if (keycode == XK_d)
		ft_go_right(game);
	else if (keycode == XK_a)
		ft_go_left(game);
}
