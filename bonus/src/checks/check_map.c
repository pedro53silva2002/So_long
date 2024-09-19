/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:05:42 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/18 14:01:22 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_check_assets(t_map *map)
{
	int	y;
	int	x;
	int	max_width;
	int	max_height;

	y = 0;
	max_width = map->width - 1;
	max_height = map->height - 1;
	while (++y < max_height)
	{
		x = 0;
		while (++x < max_width)
		{
			if (map->design[y][x] == 'E')
				map->isexit += 1;
			if (map->design[y][x] == 'C')
				map->iscollectible += 1;
			if (map->design[y][x] == 'P')
				map->isplayer += 1;
		}
	}
	if (map->isexit != 1 || map->iscollectible < 1
		|| map->isplayer != 2)
		return (0);
	return (1);
}

int	ft_check_vertical_walls(t_map *map)
{
	int	y;
	int	max_width;
	int	max_height;

	y = 0;
	max_width = map->width - 1;
	max_height = map->height;
	while (y < max_height)
	{
		if (map->design[y][0] != '1')
			return (0);
		y++;
	}
	y = 0;
	while (y < max_height)
	{
		if (map->design[y][max_width] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	ft_check_horizontal_walls(t_map *map)
{
	int	x;
	int	max_height;
	int	max_width;

	x = 0;
	max_height = map->height - 1;
	max_width = map->width;
	while (x < max_width)
	{
		if (map->design[0][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (x < max_width)
	{
		if (map->design[max_height][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_check_unkchr(t_map *map)
{
	int	y;
	int	x;
	int	max_width;
	int	max_height;

	y = 0;
	max_width = map->width;
	max_height = map->height;
	while (++y < max_height)
	{
		x = 0;
		while (++x < max_width)
		{
			if (map->design[y][x] != 'E' && map->design[y][x] != 'P'
				&& map->design[y][x] != 'C' && map->design[y][x] != '1'
				&& map->design[y][x] != '0' && map->design[y][x] != 'B')
				return (0);
		}
	}
	return (1);
}

int	ft_check_map(t_map *map, char *file)
{
	if ((map->height < 6 && map->width < 3)
		|| (map->height < 3 && map->width < 6))
		return (ft_printf("Size wrong\n"), 0);
	if (!ft_check_horizontal_walls(map))
		return (ft_printf("No horizontal\n"), 0);
	if (!ft_check_vertical_walls(map))
		return (ft_printf("No vertical\n"), 0);
	if (!ft_check_assets(map))
		return (ft_printf("No assets\n"), 0);
	if (!ft_check_path(map, file))
		return (ft_printf("No path\n"), 0);
	if (!ft_check_unkchr(map))
		return (ft_printf("Unknown character\n"), 0);
	return (1);
}
