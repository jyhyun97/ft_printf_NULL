/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:00:54 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/03/17 11:00:58 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_dtype(int a)
{
	char	*abs;
	int		abs_len;
	int		cnt;
	int		i;
	int		z_lgth;

	abs = ft_itoa_base((unsigned int)ft_abs(a), 10, "0123456789");
	abs_len = ft_strlen(abs);
	cnt = abs_len;
	if (a < 0)
		cnt++;
	z_lgth = g_flag.width - cnt;
	while (g_flag.precision > abs_len++)
		cnt++;
	i = 0;
	while (g_flag.minus == 0 && g_flag.zero == 1
			&& g_flag.precision < 0 && i++ < z_lgth)
		cnt++;
	if (g_flag.precision == 0 && a == 0)
		cnt--;
	free(abs);
	return (cnt);
}

int	count_uxtype(unsigned int a, int base_num, char *base)
{
	char	*rst;
	int		len;
	int		cnt;
	int		i;
	int		z_lgth;

	rst = ft_itoa_base(a, base_num, base);
	len = ft_strlen(rst);
	cnt = len;
	while (g_flag.precision > len++)
		cnt++;
	i = 0;
	z_lgth = g_flag.width - cnt;
	while (g_flag.minus == 0 && g_flag.zero == 1
			&& g_flag.precision < 0 && i++ < z_lgth)
		cnt++;
	if (g_flag.precision == 0 && a == 0)
		cnt--;
	free(rst);
	return (cnt);
}

int	count_ptype(long long a, char *base)
{
	char	*rst;
	int		len;
	int		cnt;

	rst = ft_itoa_long(a, base);
	len = ft_strlen(rst);
	cnt = 2;
	cnt += len;
	if (g_flag.precision == 0 && a == 0)
		cnt--;
	free(rst);
	return (cnt);
}
