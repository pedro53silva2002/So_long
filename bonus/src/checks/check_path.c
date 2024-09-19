/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:23:06 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/18 17:38:31 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	ft_one_of_the_assets(char c)
{
	if (c == 'E')
		return (1);
	else if (c == 'C')
		return (1);
	else if (c == 'P')
		return (1);
	else if (c == '0')
		return (1);
	else if (c == 'F')
		return (1);
	return (0);
}

static void	ft_find_path(t_map *map, int x, int y)
{
	if (map->design[y][x] == '1' || map->design[y][x] == 'F'
		|| map->design[y][x] == 'B')
		return ;
	if (ft_one_of_the_assets(map->design[y][x]))
	{
		if (map->design[y][x] == 'C')
		{
			map->iscollectible--;
		}
		if (map->design[y][x] == 'E' && map->isexit)
		{
			map->isexit--;
		}
	}
	if (map->design[y][x] == 'E')
		return ;
	map->design[y][x] = 'F';
	ft_find_path(map, x - 1, y);
	ft_find_path(map, x, y - 1);
	ft_find_path(map, x + 1, y);
	ft_find_path(map, x, y + 1);
}

static void	ft_get_players(t_map *map)
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
			if (map->design[y][x] == 'P' && map->start_x && map->start_y)
			{
				map->start2_x = x;
				map->start2_y = y;
			}
			else if (map->design[y][x] == 'P')
			{
				map->start_x = x;
				map->start_y = y;
			}
		}
	}
}

int	ft_check_path(t_map *map, char *file)
{
	char	**path;
	int		collec;
	int		x;
	int		y;

	ft_get_players(map);
	x = map->start_x;
	y = map->start_y;
	collec = map->iscollectible;
	path = map->design;
	ft_find_path(map, x, y);
	ft_find_path(map, map->start2_x, map->start2_y);
	ft_free_design(map);
	ft_fill_design(map, file);
	if (map->iscollectible != 0 || map->isexit)
		return (0);
	map->iscollectible = collec;
	map->isexit = 1;
	return (1);
}
