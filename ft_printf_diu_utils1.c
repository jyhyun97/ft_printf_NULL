/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:38:42 by jawpark           #+#    #+#             */
/*   Updated: 2021/03/04 17:14:41 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

static char	sign_checker(int di)
{
	if (di < 0)
		return ('-');
	else if (di > 0)
		return ('+');
	return (' ');
}

static char	ptr_di_input(int di)
{
	char	*hex;

	hex = ft_hexadecimal('d');
	if (di < 0)
		return (hex[-(di % 10)]);
	return (hex[di % 10]);
}

static void	sign_input(char *ptr, int len, int cp_len, char sign)
{
	if (g_flag.minus == 0 && g_flag.precision > -1
		&& (sign == '-' || g_flag.plus == 1))
	{
		if (g_flag.precision > len && len > 0)
			len = g_flag.width - g_flag.precision - 1;
		else if (sign == '-' && g_flag.precision >= cp_len)
			len = g_flag.width - g_flag.precision - 1;
		if (g_flag.minus == 1 || len < 0 || g_flag.zero == 1)
			len = 0;
		ptr[len] = sign;
	}
	else if (g_flag.minus == 1 && g_flag.precision > -1
		&& (sign == '-' || g_flag.plus == 1))
	{
		if (g_flag.precision > cp_len && cp_len > 0)
			cp_len = g_flag.width - g_flag.precision - 1;
		if (g_flag.minus == 1 || cp_len < 0 || g_flag.zero == 1)
			cp_len = 0;
		ptr[cp_len] = sign;
	}
}

char		*pf_di_input(char *ptr, int di, int len, int cp_len)
{
	char	sign;

	sign = sign_checker(di);
	if (g_flag.minus == 1 && g_flag.precision >= g_flag.width && len > cp_len)
		cp_len = len;
	else if (g_flag.minus == 1 && di < 0 && g_flag.precision == cp_len
			&& len > g_flag.precision + 1)
		cp_len += 1;
	else if (g_flag.minus == 1 && di < 0 && g_flag.precision == cp_len)
		cp_len = len;
	while (1)
	{
		if (g_flag.minus == 0 && g_flag.precision > -1)
			ptr[--len] = ptr_di_input(di);
		else if (g_flag.minus == 1 && g_flag.precision > -1)
			ptr[--cp_len] = ptr_di_input(di);
		di = di / 10;
		if (di == 0)
			break ;
	}
	if (g_flag.precision > -1)
		sign_input(ptr, --len, --cp_len, sign);
	return (ptr);
}

void		u_dot_input(char *ptr, int len)
{
	int		i;

	if (g_flag.minus == 0 && g_flag.dot == 1 && g_flag.precision > 0)
	{
		i = len - g_flag.precision - 1;
		while (i > -2 && ++i < len)
			ptr[i] = '0';
	}
	else if (g_flag.minus == 1 && g_flag.dot == 1 && g_flag.precision > 0)
	{
		i = g_flag.precision;
		while (--i > -1)
			ptr[i] = '0';
	}
}
