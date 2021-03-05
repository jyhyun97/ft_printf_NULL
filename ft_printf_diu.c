/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:38:15 by jawpark           #+#    #+#             */
/*   Updated: 2021/03/04 12:49:06 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

static char	*pf_u_itoa(unsigned int x, char c, int len, int cp_len)
{
	char	*ptr;
	char	*hex;

	ptr = ft_calloc(len);
	hex = ft_hexadecimal(c);
	u_dot_input(ptr, len);
	if (g_flag.minus == 1 && g_flag.precision > cp_len)
		cp_len = g_flag.precision;
	while (1 && ptr)
	{
		if (g_flag.minus == 0 && g_flag.precision >= 0)
			ptr[--len] = hex[x % 10];
		else if (g_flag.minus == 1 && g_flag.precision >= 0)
			ptr[--cp_len] = hex[x % 10];
		x = x / 10;
		if (x == 0)
			break ;
	}
	return (ptr);
}

void		pf_format_u(unsigned int x, char c)
{
	char	*tmp;
	int		len;
	int		cp_len;

	len = ft_ux_len(x, c);
	if (g_flag.dot == 1 && g_flag.precision == 0 && x == 0)
	{
		g_flag.precision = -1;
		len = 0;
	}
	cp_len = len;
	if (g_flag.width > len)
		len = g_flag.width;
	if (g_flag.precision > len)
		len = g_flag.precision;
	tmp = pf_u_itoa(x, c, len, cp_len);
	ft_putchr(tmp, len);
	ft_free_reset(tmp);
}

static void	pf_zss_input(char *ptr, int len)
{
	int		value;
	int		i;
	int		check;

	i = -1;
	if (g_flag.width > g_flag.precision && g_flag.minus == 0)
		i = g_flag.width - g_flag.precision - 1;
	check = g_flag.precision;
	if (g_flag.dot == 1 && g_flag.minus == 1)
		value = g_flag.precision;
	else if (g_flag.dot == 1 && g_flag.minus == 0)
		value = len;
	if (g_flag.dot == 1 && g_flag.precision > -1)
		while (++i < value && --check > -1)
			ptr[i] = '0';
	if (g_flag.space == 1)
		ptr[0] = ' ';
}

static char	*pf_di_itoa(int di, int len, int cp_len)
{
	char	*ptr;

	ptr = ft_calloc(len);
	pf_zss_input(ptr, len);
	if (g_flag.minus == 1 && g_flag.precision > cp_len)
		cp_len = g_flag.precision;
	ptr = pf_di_input(ptr, di, len, cp_len);
	return (ptr);
}

void		pf_format_di(int di)
{
	char	*tmp;
	int		len;
	int		cp_len;
	int		alpha;

	alpha = 0;
	if (di < 0 || g_flag.plus == 1)
		alpha = 1;
	len = ft_di_len(di);
	cp_len = len;
	if (g_flag.dot == 1 && g_flag.precision == 0 && di == 0)
	{
		g_flag.precision = -1;
		len = 0;
	}
	len = ft_wp_len(len, di, cp_len);
	if (di > 0 && cp_len + g_flag.space + g_flag.plus > cp_len)
		cp_len = cp_len + g_flag.space + g_flag.plus;
	else if (g_flag.precision > cp_len)
		cp_len = g_flag.precision + alpha;
	tmp = pf_di_itoa(di, len, cp_len);
	ft_putchr(tmp, len);
	ft_free_reset(tmp);
}
