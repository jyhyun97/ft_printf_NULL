/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xp_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:42:24 by jawpark           #+#    #+#             */
/*   Updated: 2021/03/01 19:00:11 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

char	*ft_hexadecimal(char c)
{
	if (c == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

int		ft_ux_len(unsigned int x, char c)
{
	int		ux_len;
	int		div;

	ux_len = 0;
	div = 10;
	if (c == 'x' || c == 'X')
		div = 16;
	while (1)
	{
		x = x / div;
		++ux_len;
		if (x == 0)
			break ;
	}
	return (ux_len);
}

int		ft_p_len(unsigned long long p)
{
	int		valuelen;

	valuelen = 0;
	while (1 && g_flag.precision != -1)
	{
		p = p / 16;
		++valuelen;
		if (p == 0)
			break ;
	}
	valuelen += 2;
	return (valuelen);
}

void	ft_x_frist(char *ptr, int len)
{
	int		i;
	int		value;

	i = -1;
	value = len;
	if (g_flag.minus == 1)
		value = g_flag.precision + g_flag.shap;
	if (g_flag.dot == 1 && g_flag.precision >= 0)
		while (--value > -1 && ++i != g_flag.precision + g_flag.shap)
			ptr[value] = '0';
}

void	ft_x_shap(char *ptr, int len, int cp_len, char c)
{
	int		j;

	if (g_flag.shap == 2)
	{
		if (g_flag.zero == 1)
			j = 1;
		else if (g_flag.precision > 0 && g_flag.precision >= cp_len)
			j = len - g_flag.precision - 1;
		else
			j = len - cp_len - 1;
		ptr[j - 1] = '0';
		ptr[j] = 'x';
		if (c == 'X')
			ptr[j] = 'X';
	}
}
