/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:27:54 by gilee             #+#    #+#             */
/*   Updated: 2021/03/27 21:28:55 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_res(va_list *ap, char *res)
{
	char	type;

	type = *(res + (int)ft_strlen(res) - 1);
	if (type == 'd' || type == 'i')
		print_d(ap, res, type);
	else if (type == 'c')
		print_c(ap, res, type);
	else if (type == 's')
		print_s(ap, res, type);
	else if (type == '%')
		print_per(ap, res, type);
	else if (type == 'p')
		print_p(ap, res, type);
	else if (type == 'u')
		print_u(ap, res, type);
	else if (type == 'x' || type == 'X')
		print_x(ap, res, type);
}

char	*set_dtarg(char *a, int *k)
{
	char	*pt_type;

	*k = 0;
	while (a[*k] != 'd' && a[*k] != 'i' && a[*k] != 'c' \
	&& a[*k] != 's' && a[*k] != '%' && a[*k] != 'p' \
	&& a[*k] != 'u' && a[*k] != 'x' && a[*k] != 'X' && a[*k] != '\0')
		(*k)++;
	if (a[*k] == '\0')
		return (0);
	pt_type = (char *)ft_calloc(((*k) + 2), sizeof(char));
	if (pt_type)
		ft_memcpy(pt_type, a, (*k) + 1);
	return (pt_type);
}

int		checker(va_list *ap, const char *a)
{
	char	*res;
	int		k;

	res = set_dtarg((char *)a, &k);
	if (!res)
		return (0);
	set_res(ap, res);
	free(res);
	return (k + 1);
}

void	print_rst(va_list *ap, const char *format)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += checker(ap, &format[i + 1]);
		else
		{
			write(1, &format[i], 1);
			g_count++;
		}
		i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list ap;

	g_count = 0;
	va_start(ap, format);
	print_rst(&ap, format);
	va_end(ap);
	return (g_count);
}
