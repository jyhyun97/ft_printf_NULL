/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:59:39 by jso               #+#    #+#             */
/*   Updated: 2021/02/23 13:25:12 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_printf(char *fmt, ...)
{
	va_list ap;
	int cnt;

	cnt = 0;
	va_start(ap, fmt);
	printf("%s\n", fmt);
	printf("%d\n", va_arg(ap, int));
	va_end(ap);
	++cnt;
	return (cnt);
}

int main(void)
{
	char *str;

	str = "Hello";
	ft_printf(str, 'a');
	return (0);
}
