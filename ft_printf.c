/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:27:54 by gilee             #+#    #+#             */
/*   Updated: 2021/03/29 13:15:28 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_res(va_list *ap, char *res)
{
	char	type;
	int		is_err;

	is_err = DONE;
	type = *(res + (int)ft_strlen(res) - 1);
	if (type == 'd' || type == 'i')
		is_err = print_d(ap, res, type);
	else if (type == 'c')
		is_err = print_c(ap, res, type);
	else if (type == 's')
		is_err = print_s(ap, res, type);
	else if (type == '%')
		is_err = print_per(ap, res, type);
	else if (type == 'p')
		is_err = print_p(ap, res, type);
	else if (type == 'u')
		is_err = print_u(ap, res, type);
	else if (type == 'x' || type == 'X')
		is_err = print_x(ap, res, type);
	return (is_err);
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
		return (NULL);
	pt_type = (char *)ft_calloc(((*k) + 2), sizeof(char));
	if (pt_type)
		ft_memcpy(pt_type, a, (*k) + 1);
	return (pt_type);
}

int		checker(va_list *ap, const char *a)
{
	char	*res;
	int		k;
	int		is_err;

	res = set_dtarg((char *)a, &k);
	if (!res)
		return (ERR);
	is_err = set_res(ap, res);
	free(res);
	if (is_err == ERR)
		return (ERR);
	return (k + 1);
}

int		print_rst(va_list *ap, const char *format)
{
	int	i;
	int	is_err;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			is_err = checker(ap, &format[i + 1]);
			if (is_err == ERR)
				return (is_err);
			i += is_err;
		}
		else
		{
			write(1, &format[i], 1);
			g_count++;
		}
		i++;
	}
	return (DONE);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		is_err;

	g_count = 0;
	va_start(ap, format);
	is_err = print_rst(&ap, format);
	va_end(ap);
	if (is_err == ERR)
		return (ERR);
	return (g_count);
}
