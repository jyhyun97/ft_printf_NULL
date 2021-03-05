/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:42:06 by jawpark           #+#    #+#             */
/*   Updated: 2021/03/01 18:59:12 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

static char	*pf_x_itoa(unsigned int x, int len, char c, int cp_len)
{
	char	*ptr;
	char	*hex;

	ptr = ft_calloc(len);
	hex = ft_hexadecimal(c);
	ft_x_frist(ptr, len);
	if (x != 0)
		ft_x_shap(ptr, len, cp_len, c);
	cp_len = cp_len + g_flag.shap;
	if (g_flag.minus == 1 && g_flag.precision > cp_len)
		cp_len = g_flag.precision;
	while (1)
	{
		if (g_flag.minus == 0 && g_flag.precision >= 0)
			ptr[--len] = hex[x % 16];
		else if (g_flag.minus == 1 && g_flag.precision >= 0)
			ptr[--cp_len] = hex[x % 16];
		x = x / 16;
		if (x == 0)
			break ;
	}
	return (ptr);
}

void		pf_format_x(unsigned int x, char c)
{
	int					len;
	int					cp_len;
	char				*tmp;

	len = ft_ux_len(x, c);
	if (g_flag.dot == 1 && g_flag.precision == 0 && x == 0)
	{
		len = 0;
		g_flag.precision = -1;
	}
	cp_len = len;
	if (x != 0 || g_flag.precision != 0)
		len = len + g_flag.shap;
	if (g_flag.precision >= len && x != 0)
		len = g_flag.precision + g_flag.shap;
	else if (g_flag.precision > len)
		len = g_flag.precision + g_flag.shap;
	if (g_flag.width > len)
		len = g_flag.width;
	tmp = pf_x_itoa(x, len, c, cp_len);
	ft_putchr(tmp, len);
	ft_free_reset(tmp);
}

static int	p_dotnull(char *ptr, int value)
{
	if (g_flag.precision == -1)
	{
		ptr[value - 1] = 'x';
		ptr[value - 2] = '0';
		return (0);
	}
	return (1);
}

static char	*pf_p_itoa(unsigned long long cp, char c, int len, int cp_len)
{
	char				*ptr;
	char				*hex;
	int					value;

	ptr = ft_calloc(len);
	hex = ft_hexadecimal(c);
	if (g_flag.minus == 0)
		value = len;
	else
		value = cp_len;
	while (1 && p_dotnull(ptr, value) == 1)
	{
		ptr[--value] = hex[cp % 16];
		cp = (cp / 16);
		if (cp == 0)
		{
			ptr[value - 1] = 'x';
			ptr[value - 2] = '0';
			break ;
		}
	}
	return (ptr);
}

void		pf_format_p(void *p, char c)
{
	char				*tmp;
	int					len;
	int					cp_len;
	unsigned long long	cp;

	cp = (unsigned long long)p;
	if (!p)
	{
		cp = 0;
		if (g_flag.dot == 1 && g_flag.precision == 0)
			g_flag.precision = -1;
	}
	len = ft_p_len(cp);
	cp_len = len;
	if (g_flag.width > len)
		len = g_flag.width;
	tmp = pf_p_itoa(cp, c, len, cp_len);
	ft_putchr(tmp, len);
	ft_free_reset(tmp);
}
