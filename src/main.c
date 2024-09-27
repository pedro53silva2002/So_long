/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:12:37 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/23 13:46:45 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map		map;
	t_player	player;
	t_game		game;

	if (argc != 2)
		return (0);
	game.mlx = mlx_init();
	if (!ft_init_map(&map, argv[1]))
	{
		ft_free_design(&map);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (0);
	}
	if (!ft_init_player(&player))
	{
		ft_free_design(&map);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		ft_printf("Error\n	Something wrong with player!\n");
		return (0);
	}
	ft_start_game(&map, &player, game);
	return (0);
}
