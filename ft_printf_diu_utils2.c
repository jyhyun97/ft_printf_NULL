/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:39:15 by jawpark           #+#    #+#             */
/*   Updated: 2021/03/03 21:18:01 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

int		ft_di_len(int di)
{
	int		len;

	len = 0;
	if (di < 0)
		len = 1;
	while (1 && g_flag.precision != -1)
	{
		di = di / 10;
		++len;
		if (di == 0)
			break ;
	}
	return (len);
}

int		ft_wp_len(int len, int di, int cp_len)
{
	int		alpha;

	alpha = 0;
	if (di < 0 || g_flag.plus == 1)
		alpha = 1;
	if (di < 0 && alpha == 1 && g_flag.precision == len)
		len += 1;
	if (g_flag.width > len || g_flag.precision > len)
	{
		if (g_flag.width > g_flag.precision)
			len = g_flag.width;
		else
			len = g_flag.precision + alpha;
	}
	if (di > 0 && (cp_len == len || g_flag.precision > 0)
		&& len + g_flag.space + g_flag.plus > len)
		len = len + g_flag.space + g_flag.plus;
	return (len);
}
