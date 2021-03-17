/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:43:30 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/03/17 11:47:23 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(va_list ap)
{
	int	a;
	int	len;

	a = va_arg(ap, int);
	len = count_dtype(a);
	if (g_flag.minus)
	{
		make_dtype(a);
		padding(len);
	}
	else
	{
		padding(len);
		make_dtype(a);
	}
}

void	print_u(va_list ap)
{
	unsigned int	a;
	char			*base;
	int				len;

	a = va_arg(ap, unsigned int);
	base = "0123456789";
	len = count_uxtype(a, 10, base);
	if (g_flag.minus)
	{
		make_uxtype(a, 10, base);
		padding(len);
	}
	else
	{
		padding(len);
		make_uxtype(a, 10, base);
	}
}

void	print_x(va_list ap)
{
	unsigned int	a;
	char			*base;
	int				len;

	a = va_arg(ap, unsigned int);
	if (g_flag.type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = count_uxtype(a, 16, base);
	if (g_flag.minus)
	{
		make_uxtype(a, 16, base);
		padding(len);
	}
	else
	{
		padding(len);
		make_uxtype(a, 16, base);
	}
}

void	print_p(va_list ap)
{
	long long	a;
	char		*base;
	int			len;

	a = (long long)va_arg(ap, void *);
	base = "0123456789abcdef";
	len = count_ptype(a, base);
	if (g_flag.minus)
	{
		make_ptype(a, base);
		padding(len);
	}
	else
	{
		padding(len);
		make_ptype(a, base);
	}
}
