/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:34:27 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/03/17 11:41:44 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_precision(int len)
{
	int	i;

	i = 0;
	while (g_flag.precision - len > i++)
	{
		write(1, "0", 1);
		g_flag.count++;
	}
}

void	zero_padding(int z_lgth)
{
	int	i;

	i = 0;
	while (g_flag.minus == 0 && g_flag.zero == 1
			&& g_flag.precision < 0 && i++ < z_lgth)
	{
		write(1, "0", 1);
		g_flag.count++;
	}
}

void	make_dtype(int a)
{
	char	*abs;
	int		abs_len;
	int		z_lgth;

	abs = ft_itoa_base((unsigned int)ft_abs(a), 10, "0123456789");
	abs_len = ft_strlen(abs);
	if (a < 0)
	{
		write(1, "-", 1);
		g_flag.count++;
	}
	zero_precision(abs_len);
	z_lgth = g_flag.width - abs_len;
	if (a < 0)
		z_lgth -= 1;
	zero_padding(z_lgth);
	if (g_flag.precision != 0 || a != 0)
		write(1, abs, abs_len);
	else
		abs_len = 0;
	g_flag.count += abs_len;
	free(abs);
}

void	make_uxtype(unsigned int a, int base_num, char *base)
{
	char	*rst;
	int		len;
	int		z_lgth;

	rst = ft_itoa_base(a, base_num, base);
	len = ft_strlen(rst);
	zero_precision(len);
	z_lgth = g_flag.width - len;
	zero_padding(z_lgth);
	if (g_flag.precision != 0 || a != 0)
		write(1, rst, len);
	else
		len = 0;
	g_flag.count += len;
	free(rst);
}

void	make_ptype(long long a, char *base)
{
	char	*rst;
	int		len;

	rst = ft_itoa_long(a, base);
	len = ft_strlen(rst);
	write(1, "0x", 2);
	g_flag.count += 2;
	if (g_flag.precision != 0 || a != 0)
		write(1, rst, len);
	else
		len = 0;
	g_flag.count += len;
	free(rst);
}
