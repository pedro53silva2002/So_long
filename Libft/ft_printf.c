/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:41:48 by peferrei          #+#    #+#             */
/*   Updated: 2024/06/18 15:41:59 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
/** @brief Checks the format and calls the corresponding function
 *  @param str - string
 * 	@param list_va - list of substrings to be formatted
 *  @return Returns the number of characters written
*/
static int	ft_check(unsigned char str, va_list list_va)
{
	int	nbr;

	nbr = 0;
	if (str == 's')
		nbr += ft_printfputstr_fd(va_arg(list_va, char *), 1);
	else if (str == 'd' || str == 'i')
		nbr += ft_printfputnbr_fd(va_arg(list_va, int), 1);
	else if (str == 'c')
		nbr += ft_printfputchar_fd(va_arg(list_va, int), 1);
	else if (str == 'x')
		nbr += ft_printfint_puthex(va_arg(list_va, unsigned long), 'x');
	else if (str == 'X')
		nbr += ft_printfint_puthex(va_arg(list_va, unsigned long), 'X');
	else if (str == 'u')
		nbr += ft_printfputnbr_base(va_arg(list_va, unsigned int), "ude");
	else if (str == 'p')
		nbr += ft_printfputptr(va_arg(list_va, unsigned long));
	else if (str == '%')
	{
		write(1, "%", 1);
		nbr += 1;
	}
	return (nbr);
}

/** @brief Displays a formatted string on the screen
 *  @param s - string
 * 	@param ... - the type of format for the string
 *  @return Returns the number of characters written
*/
int	ft_printf(const char *s, ...)
{
	unsigned char	*str;
	va_list			valist;
	int				i;

	if (!s)
		return (0);
	i = 0;
	va_start(valist, s);
	str = (unsigned char *)s;
	while (*str)
	{
		if (*str == '%')
		{
			i += ft_check(*(str + 1), valist);
			str += 2;
		}
		else
		{
			write(1, &*str, 1);
			i += 1;
			str++;
		}
	}
	return (i);
}
