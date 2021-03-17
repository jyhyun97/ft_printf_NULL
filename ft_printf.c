/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:01:11 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/03/17 11:05:01 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checker(va_list ap, char **format)
{
	init_flag();
	*format = check_flag(*format);
	*format = check_width(*format, ap);
	*format = check_precision(*format, ap);
	check_type(*format);
	print_all(ap);
}

void	print_rst(va_list ap, char *format)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			checker(ap, &format);
		}
		else
		{
			write(1, format, 1);
			g_flag.count++;
		}
		format++;
	}
}

int		ft_printf(const char *format, ...)
{
	char	*a;
	va_list	ap;

	a = ft_strdup(format);
	g_flag.count = 0;
	va_start(ap, format);
	print_rst(ap, a);
	va_end(ap);
	free(a);
	return (g_flag.count);
}
