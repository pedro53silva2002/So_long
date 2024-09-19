/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:41:05 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/18 17:25:24 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_go_up(t_game *game, int id, char *path)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player[id]->x_coords;
	y = game->player[id]->y_coords * game->map->width;
	if (!ft_check_up(game, id, ft_counter_id(id)))
		return ;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, GROUND, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	y -= game->map->width;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx,
			path, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	game->player[id]->y_coords--;
	game->player[id]->moves++;
	game->total_moves++;
	ft_printf("Moves: %d\n", game->total_moves);
}

void	ft_go_down(t_game *game, int id, char *path)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player[id]->x_coords;
	y = game->player[id]->y_coords * game->map->width;
	if (!ft_check_down(game, id, ft_counter_id(id)))
		return ;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, GROUND, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	y += game->map->width;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx,
			path, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	game->player[id]->y_coords++;
	game->player[id]->moves++;
	game->total_moves++;
	ft_printf("Moves: %d\n", game->total_moves);
}

void	ft_go_right(t_game *game, int id, char *path)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player[id]->x_coords;
	y = game->player[id]->y_coords * game->map->width;
	if (!ft_check_right(game, id, ft_counter_id(id)))
		return ;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, GROUND, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	x += 1;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx,
			path, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	game->player[id]->x_coords++;
	game->player[id]->moves++;
	game->total_moves++;
	ft_printf("Moves: %d\n", game->total_moves);
}

void	ft_go_left(t_game *game, int id, char *path)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player[id]->x_coords;
	y = game->player[id]->y_coords * game->map->width;
	if (!ft_check_left(game, id, ft_counter_id(id)))
		return ;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx, GROUND, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	x -= 1;
	mlx_destroy_image(game->mlx, game->img[y + x].img);
	game->img[y + x].img = mlx_xpm_file_to_image(game->mlx,
			path, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[y + x].img, x * 64,
		y / game->map->width * 64);
	game->player[id]->x_coords--;
	game->player[id]->moves++;
	game->total_moves++;
	ft_printf("Moves: %d\n", game->total_moves);
}
