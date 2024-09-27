/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:10 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/23 13:46:02 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

char	*ft_selec_img2(int x, int y, t_map *map)
{
	if (map->design[y][x] == '1')
		return (WALL_MIDDLE);
	if (map->design[y][x] == 'C')
		return (CHEST);
	else if (map->design[y][x] == 'E')
		return (EXIT);
	else if (map->design[y][x] == 'B')
		return (BUSH);
	else if (map->design[y][x] == 'P' && y == map->start_y && x == map->start_x)
		return (PLAYER_DOWN_1);
	else if (map->design[y][x] == 'P'
		&& y == map->start2_y && x == map->start2_x)
		return (PLAYER2_DOWN_1);
	return (NULL);
}

char	*ft_selec_img(int x, int y, t_map *map)
{
	if (x == 0 && y == 0)
		return (WALL_TOP_LEFT);
	else if (x == (map->width - 1) && y == 0)
		return (WALL_TOP_RIGHT);
	else if (x == 0 && y == (map->height - 1))
		return (WALL_BOTTOM_LEFT);
	else if (x == (map->width - 1) && y == (map->height - 1))
		return (WALL_BOTTOM_RIGHT);
	else if (y == 0)
		return (WALL_HORIZONTAL_UP);
	else if (y == (map->height - 1))
		return (WALL_HORIZONTAL_DOWN);
	else if (x == (map->width - 1))
		return (WALL_VERTICAL_RIGHT);
	else if (x == 0)
		return (WALL_VERTICAL_LEFT);
	else if (ft_selec_img2(x, y, map))
		return (ft_selec_img2(x, y, map));
	return (GROUND);
}

int	ft_put_img_in_window(t_game *game, int x, int y, t_map *map)
{
	int		img_width;
	int		img_height;
	char	*relative_path;

	relative_path = NULL;
	relative_path = ft_selec_img(x, y, map);
	img_width = 64;
	img_height = 64;
	game->img[game->pos].img = mlx_xpm_file_to_image(game->mlx, relative_path,
			&img_width, &img_height);
	if (!game->img[game->pos].img)
		return (0);
	mlx_put_image_to_window(game->mlx, game->win, game->img[game->pos++].img,
		x * 64, y * 64);
	return (1);
}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;
	int	image;

	y = -1;
	x = 0;
	while (++y < (game->map->height))
	{
		x = -1;
		while (++x < (game->map->width))
		{
			image = ft_put_img_in_window(game, x, y, game->map);
			if (!image)
				return (ft_printf("Error\nMissing image\n")
					, 0);
		}
	}
	return (1);
}
