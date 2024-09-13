/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strlcpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:26:38 by peferrei          #+#    #+#             */
/*   Updated: 2024/06/18 15:41:50 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
/** @brief Copies a size of the string src to the string dst
 *  @param dst - destiny string
 *  @param src - source string
 *  @param size - size of string src you want to copy
 *  @return returns the length of src
*/
size_t	ft_printfstrlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_printfstrlen(src);
	i = 0;
	if (size == 0)
	{
		return (len);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
