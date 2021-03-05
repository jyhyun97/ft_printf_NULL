/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:35:05 by jawpark           #+#    #+#             */
/*   Updated: 2021/03/04 17:34:04 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_size	g_size;
t_flag	g_flag;

int			pf_flag_checker(va_list ap, const char *s)
{
	int		i;
	int		result;

	i = -1;
	result = 1;
	while (result == 1 && s[++i])
		result = flag_save(s[i]);
	while (result == 0 && s[i])
		result = wpl_check(s[i++], ap);
	flag_save_checker(0, s[i - 1]);
	return (--i);
}

static int	pf_checker(va_list ap, const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_flag_reset();
			++i;
			i += pf_flag_checker(ap, &s[i]);
			if (flag_format_checker(&s[i]))
				return (g_size.all_size);
			pf_format_checker(ap, s[i]);
		}
		else
			ft_putchr((char *)&s[i], 1);
		++i;
	}
	return (g_size.all_size);
}

int			ft_printf(const char *s, ...)
{
	va_list	ap;
	int		rst;

	rst = 0;
	va_start(ap, s);
	ft_size_reset();
	rst = pf_checker(ap, s);
	va_end(ap);
	return (rst);
}
