/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:12:37 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/18 17:56:50 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_early_exit(t_map *map, t_game game)
{
	ft_free_design(map);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_player	player1;
	t_player	player2;
	t_game		game;

	if (argc != 2)
		return (0);
	game.mlx = mlx_init();
	if (!ft_init_map(&map, argv[1]))
	{
		ft_early_exit(&map, game);
		return (ft_printf("Something wrong with map!\n"), 0);
	}
	if (!ft_init_player(&player1))
	{
		ft_early_exit(&map, game);
		return (ft_printf("Something wrong with player!\n"), 0);
	}
	if (!ft_init_player(&player2))
	{
		ft_early_exit(&map, game);
		return (ft_printf("Something wrong with player2!\n"), 0);
	}
	ft_start_game(&map, &player1, &player2, game);
	return (0);
}
