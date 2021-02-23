/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:59:39 by jso               #+#    #+#             */
/*   Updated: 2021/02/23 13:37:53 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	check 	
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

int	main(void)
{
	char *str;
	int ret;

	str = "Hello";
	ret = ft_printf("asdf%dasdf%d", 10, 20);
	printf("ret : %d\n", ret);
	return (0);
}
