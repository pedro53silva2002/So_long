/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:17:28 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/19 18:08:32 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	ft_fill_design(t_map *map, char *file)
{
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	i = -1;
	map->design = malloc(sizeof(char *) * (map->height + 1));
	if (!map->design)
	{
		close(fd);
		return ;
	}
	while (++i < map->height)
		map->design[i] = get_next_line(fd);
	close(fd);
	map->design[i] = NULL;
}

void	ft_mapsize(t_map *map, char *file)
{
	int		fd;
	int		current_width;
	char	*str;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (free(str));
	map->width = ft_linelen(str);
	free(str);
	str = NULL;
	while (fd && map->height++ >= 0)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		current_width = ft_linelen(str);
		free(str);
		str = NULL;
		if (current_width != map->width)
			map->invalid = 1;
	}
	close(fd);
}

void	ft_give_value(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->isemptyplace = 0;
	map->iswall = 0;
	map->isexit = 0;
	map->iscollectible = 0;
	map->isplayer = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->design = NULL;
}

int	ft_init_map(t_map *map, char *file)
{
	int	fd;

	if (!ft_checkfile(map, file))
		return (0);
	map = ft_memset(map, 0, sizeof(t_map));
	fd = open(file, O_RDONLY);
	close(fd);
	if (fd == -1)
		return (0);
	ft_give_value(map);
	ft_mapsize(map, file);
	if (map->invalid)
		return (0);
	ft_fill_design(map, file);
	if (!ft_check_map(map, file))
		return (0);
	return (1);
}
