/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:45:50 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/03/17 11:47:48 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char				*a;
	unsigned int		i;

	a = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (a == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

int		ft_abs(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

char	*ft_itoa_base(unsigned int n, int base_num, char *base)
{
	char			*rst;
	unsigned int	digit;
	unsigned int	a;

	a = n;
	digit = 0;
	if (a == 0)
		digit++;
	while (a > 0)
	{
		a /= base_num;
		digit++;
	}
	rst = (char *)malloc(digit + 1);
	if (rst == 0)
		return (0);
	a = n;
	rst[digit] = '\0';
	while (digit > 0)
	{
		digit--;
		rst[digit] = base[a % base_num];
		a /= base_num;
	}
	return (rst);
}

char	*ft_itoa_long(long long n, char *base)
{
	char			*rst;
	unsigned int	digit;
	long long		a;

	a = n;
	digit = 0;
	if (a == 0)
		digit++;
	while (a > 0)
	{
		a /= 16;
		digit++;
	}
	rst = (char *)malloc(digit + 1);
	if (rst == 0)
		return (0);
	a = n;
	rst[digit] = '\0';
	while (digit > 0)
	{
		digit--;
		rst[digit] = base[a % 16];
		a /= 16;
	}
	return (rst);
}
