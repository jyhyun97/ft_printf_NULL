/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:30:20 by gilee             #+#    #+#             */
/*   Updated: 2021/03/27 21:30:56 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_getlen(long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = (long long)(n / 10);
		if (n < 0)
			n *= -1;
		count++;
	}
	return (count);
}

static int			ft_ndec(int len)
{
	int res;

	res = 1;
	len -= 1;
	while (len--)
	{
		res *= 10;
	}
	return (res);
}

static long long	ft_abs(long long num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

char				*ft_itoa(long long n)
{
	char	*res;
	int		flag;
	int		len;

	flag = 0;
	if (n < 0)
	{
		flag += 1;
	}
	len = ft_getlen(n);
	if (!(res = (char *)ft_calloc(len + flag + 1, sizeof(char))))
		return (NULL);
	if (flag != 0)
		res[0] = '-';
	while (len)
	{
		res[flag++] = '0' + ft_abs((n / ft_ndec(len)));
		n = ft_abs((n % ft_ndec(len)));
		len--;
	}
	return (res);
}
