/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:39:44 by jawpark           #+#    #+#             */
/*   Updated: 2021/03/01 18:52:16 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

static int	format_check(char c)
{
	int		i;
	char	*s;

	i = -1;
	s = "cspdiuxX%";
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

int			wpl_check(char c, va_list ap)
{
	if (wpl_negative(c) && format_check(c))
		return (1);
	if (g_flag.dot == 1 || c == '.')
	{
		g_flag.dot = 1;
		if (c != '.' && c != '*' && (c >= '0' && c <= '9'))
			g_flag.precision = g_flag.precision * 10 + (c - '0');
		else if (c == '*')
			g_flag.precision = va_arg(ap, int);
	}
	else
	{
		if (c != '*')
			g_flag.width = g_flag.width * 10 + (c - '0');
		else
			g_flag.width = va_arg(ap, int);
	}
	return (0);
}

static int	pf_error(void)
{
	return (1);
}

int			flag_format_checker(const char *c)
{
	if ((c[0] == 'c' || c[0] == 'p') && (g_flag.zero == 1 || g_flag.shap == 2
		|| g_flag.space == 1 || g_flag.plus == 1))
		return (pf_error());
	else if (c[0] == 's' && (g_flag.zero == 1 || g_flag.shap == 2
		|| g_flag.space == 1 || g_flag.plus == 1))
		return (pf_error());
	else if ((c[0] == 'd' || c[0] == 'i') && g_flag.shap == 2)
		return (pf_error());
	else if (c[0] == 'u' && (g_flag.shap == 2
		|| g_flag.space == 1 || g_flag.plus == 1))
		return (pf_error());
	else if ((c[0] == 'x' || c[0] == 'X')
		&& (g_flag.space == 1 || g_flag.plus == 1))
		return (pf_error());
	else
		return (0);
}

int			flag_save(char c)
{
	if (c == '+')
		g_flag.plus = 1;
	else if (c == '-')
		g_flag.minus = 1;
	else if (c == '#')
		g_flag.shap = 2;
	else if (c == ' ')
		g_flag.space = 1;
	else if (c == '0' && g_flag.dot != 1)
		g_flag.zero = 1;
	else if (c == '.')
		g_flag.dot = 1;
	else
		return (0);
	return (1);
}
