/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:17:34 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/13 16:37:28 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_player(t_player *player)
{
	if (!player)
		return (0);
	player->def_msg = "Even my grandma plays better.";
	player->suc_msg = "Well atleast you can do baby level";
	player->down = 0;
	player->left = 0;
	player->right = 0;
	player->up = 0;
	player->moves = 0;
	player->x_coords = 0;
	player->y_coords = 0;
	return (1);
}
