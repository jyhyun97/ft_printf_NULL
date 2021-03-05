/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:59:39 by jso               #+#    #+#             */
/*   Updated: 2021/03/05 12:43:57 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void checker(va_list ap, const char **fmt)
{

}

void print_rst(va_list ap, const char *fmt)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			checker(ap, &fmt);
		}
		else
		{
			write(1, fmt, 1);
			++g_flag.count;
		}
		++fmt;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	print_rst(ap, fmt);
	va_end(ap);
	return (g_flag.count);
}
