/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:59:39 by jso               #+#    #+#             */
/*   Updated: 2021/03/02 16:00:30 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_printf(char *fmt, ...)
{
	va_list ap;
	int n_byte;
	char *dup_str;

	va_start(ap, fmt);
	dup_str = ft_strdup(fmt);
	n_byte = print_rst(ap, dup_str);
	va_end(ap);
	free (dup_str);
	return (n_byte);
}

int main(void)
{
	char *str;
	int ret;

	str = "aaa%-5.*saaa%000*.*daaa\n";
	ret = ft_printf(str, 2, "!@#$", 3, 4, 9999);
	printf("return value\t: %d\n", ret);
	return (0);
}
