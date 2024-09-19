/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:51:36 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/18 14:14:57 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_free_design(t_map *map)
{
	int	i;

	i = -1;
	if (!map->design)
	{
		return ;
	}
	while (++i < map->height)
	{
		if (map->design[i])
			free(map->design[i]);
	}
	free(map->design);
}

void	ft_free_img(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
	if (game->img)
	{
		if (game->img[0].img)
		{
			while (--game->pos >= 0)
			{
				mlx_destroy_image(game->mlx, game->img[game->pos].img);
			}
		}
		free(game->img);
	}
}

void	ft_free_all(t_game *game)
{
	if (game->map)
		ft_free_design(game->map);
	ft_free_img(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->player)
		free(game->player);
	free(game->mlx);
	exit(0);
}
