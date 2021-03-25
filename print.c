/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:08:06 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/26 02:28:39 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_count;

int print_p(s_list *flag, va_list ap, char type)
{
	int len;
	long long int longer_d;
	int n_zeros;
	int n_spaces;
	char *d_str;
	char *base_set;

	if (type == 'x' || type == 'p')
		base_set = "0123456789abcdef";
	else
		base_set = "0123456789ABCDEF";
	longer_d = (long long int)va_arg(ap, void *);
	d_str = ft_itoa_base(longer_d, base_set, 16);
	len = ft_strlen(d_str) + 2;
	calculate_paddings(flag, &n_zeros, &n_spaces, len);
	if (flag->left)
	{
	//	if (flag->minus)
		//	write_with_count("-", 1);
		write_with_count("0x" , 2);
		padding('0', n_zeros);
		write_with_count(d_str , len);
		padding(' ', n_spaces);
	}
	else
	{
		padding(' ', n_spaces);
	//	if (flag->minus)
		//	write_with_count("-", 1);
		write_with_count("0x" , 2);
		padding('0', n_zeros);
		write_with_count(d_str, len);
	}
	free(d_str);
	return (1);
}

int print_x(s_list *flag, va_list ap, char type)
{
	int len;
	unsigned int unsigned_d;
	int n_zeros;
	int n_spaces;
	char *d_str;
	char *base_set;

	if (type == 'x' || type == 'p')
		base_set = "0123456789abcdef";
	else
		base_set = "0123456789ABCDEF";
	unsigned_d = (unsigned int)va_arg(ap, unsigned int);
	d_str = ft_itoa_base((long long int)unsigned_d, base_set, 16);
	len = ft_strlen(d_str);
	if (unsigned_d < 0)
		flag->minus = 1;
	calculate_paddings(flag, &n_zeros, &n_spaces, len);
	if (unsigned_d == 0 && flag->has_prec && flag->prec == 0)
	{
		padding(' ', flag->width);
		free(d_str);
		return (flag->width);
	}
	if (flag->left)
	{
		if (flag->minus)
			write_with_count("-", 1);
		padding('0', n_zeros);
		write_with_count(d_str , len);
		padding(' ', n_spaces);
	}
	else
	{
		padding(' ', n_spaces);
		if (flag->minus)
			write_with_count("-", 1);
		padding('0', n_zeros);
		write_with_count(d_str, len);
	}
	free(d_str);
	return (1);
}

int print_u(s_list *flag, va_list ap)
{
	int len;
	unsigned int unsigned_d;
	int n_zeros;
	int n_spaces;
	char *d_str;

	unsigned_d = (unsigned int)va_arg(ap, unsigned int);
	d_str = ft_itoa_base((long long int)unsigned_d, "0123456789", 10);
	len = ft_strlen(d_str);
	if (unsigned_d < 0)
		flag->minus = 1;
	calculate_paddings(flag, &n_zeros, &n_spaces, len);
	if (unsigned_d == 0 && flag->has_prec && flag->prec == 0)
	{
		padding(' ', flag->width);
		free(d_str);
		return (flag->width);
	}
	if (flag->left)
	{
		if (flag->minus)
			write(1, "-", 1);
		padding('0', n_zeros);
		write_with_count(d_str , len);
		padding(' ', n_spaces);
	}
	else
	{
		padding(' ', n_spaces);
		if (flag->minus)
			write(1, "-", 1);
		padding('0', n_zeros);
		write_with_count(d_str, len);
	}
	free(d_str);
	return (1);
}

int print_d(s_list *flag, va_list ap)
{
	int len;
	int d;
	int n_zeros;
	int n_spaces;
	char *d_str;

	d = va_arg(ap, int);
	d_str = ft_itoa((long long int)d);
	len = ft_strlen(d_str);
	if (d < 0)
		flag->minus = 1;
	calculate_paddings(flag, &n_zeros, &n_spaces, len);
	if (d == 0 && flag->has_prec && flag->prec == 0)
	{
		padding(' ', flag->width);
		free(d_str);
		return (flag->width);
	}
	if (flag->left)
	{
		if (flag->minus)
			write(1, "-", 1);
		padding('0', n_zeros);
		write(1, d_str + flag->minus, len - flag->minus);
		padding(' ', n_spaces);
	}
	else
	{
		padding(' ', n_spaces);
		if (flag->minus)
			write(1, "-", 1);
		padding('0', n_zeros);
		write(1, d_str + flag->minus, len - flag->minus);
	}
	free(d_str);
	return (1);
}

int print_c(s_list *flag, char type, char c)
{
	if (flag->left)
	{
		write_with_count(&c, 1);
		if (flag->width > 1)
			padding(' ', flag->width - 1);
	}
	else if (flag->zero && c == '%')
	{
		if (flag->width > 1)
			padding('0', flag->width - 1);
		write_with_count(&c, 1);
	}
	else
	{
		if (flag->width > 1)
			padding(' ', flag->width - 1);
		write_with_count(&c, 1);
	}
	if (type == 'c' && flag->has_prec == 1)
		return (0);
	return (1);
}

void print_s(char *str, s_list *flag)
{
	int len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (flag->has_prec && flag->prec < len && flag->prec >= 0)
		len = flag->prec;
	if (flag->left)
	{
		write_with_count(str, len);
		if (flag->width > len)
			padding(' ', flag->width - len);
	}
