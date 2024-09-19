/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:17:28 by peferrei          #+#    #+#             */
/*   Updated: 2024/09/16 14:00:55 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_checkfile(t_map *map, char *file)
{
	char	*str;
	char	*filecpy;
	int		len;

	str = ".ber";
	len = ft_strlen(file);
	filecpy = ft_substr(file, len - 4, 4);
	if (ft_strncmp(str, filecpy, 4) != 0)
	{
		free(filecpy);
		(*map).design = NULL;
		return (0);
	}
	free(filecpy);
	return (1);
}
