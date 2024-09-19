/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:17:34 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/18 18:00:44 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_player(t_player *player)
{
	if (!player)
		return (0);
	player->def_msg = "Maybe try harder...";
	player->suc_msg = "Yay you win!";
	player->moves = 0;
	player->x_coords = 0;
	player->y_coords = 0;
	return (1);
}
