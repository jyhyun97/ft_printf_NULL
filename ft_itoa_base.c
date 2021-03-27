/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:24:48 by gilee             #+#    #+#             */
/*   Updated: 2021/03/27 21:31:14 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_abs(long long nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static char		*set_tab(int is_upper)
{
	if (is_upper)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

static int		itoa_set_flag(long long value, int base)
{
	if (value < 0 && base == 10)
		return (1);
	else
		return (0);
}

static int		set_size(long long tmp, int base)
{
	int	size;

	size = 0;
	while (tmp / base)
	{
		tmp /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base(long long value, int base, int is_upper)
{
	char		*str;
	int			size;
	char		*tab;
	int			flag;

	if (base < 2 || base > 16)
		return (0);
	flag = itoa_set_flag(value, base);
	tab = set_tab(is_upper);
	size = set_size(value, base) + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % (long long)base)];
		size--;
		value /= (long long)base;
	}
	return (str);
}
