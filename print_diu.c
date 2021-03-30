/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:08:06 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/30 21:37:31 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	aligined_print(t_list *flag, char *str, int zeros, int spaces)
{
	int		len;

	len = ft_strlen(str);
	if (flag->left)
	{
		if (flag->minus)
			write_with_count("-", 1);
		padding('0', zeros);
		write_with_count(str, len);
		padding(' ', spaces);
	}
	else
	{
		padding(' ', spaces);
		if (flag->minus)
			write_with_count("-", 1);
		padding('0', zeros);
		write_with_count(str, len);
	}
}

void	print_u(t_list *flag, va_list ap)
{
	int				len;
	unsigned int	unsigned_d;
	int				n_zeros;
	int				n_spaces;
	char			*d_str;

	unsigned_d = (unsigned int)va_arg(ap, unsigned int);
	d_str = ft_itoa_base((long long int)unsigned_d, "0123456789");
	len = ft_strlen(d_str);
	calculate_paddings(flag, &n_zeros, &n_spaces, len);
	if (unsigned_d == 0 && flag->has_prec && flag->prec == 0)
	{
		padding(' ', flag->width);
		free(d_str);
		return ;
	}
	if (flag->left)
		aligined_print(flag, d_str, n_zeros, n_spaces);
	else
		aligined_print(flag, d_str, n_zeros, n_spaces);
	free(d_str);
}

void	print_d(t_list *flag, int d, char *d_str, int len)
{
	int		n_zeros;
	int		n_spaces;

	calculate_paddings(flag, &n_zeros, &n_spaces, len);
	if (d == 0 && flag->has_prec && flag->prec == 0)
	{
		padding(' ', flag->width);
		free(d_str);
		return ;
	}
	if (flag->left)
		aligined_print(flag, d_str + flag->minus, n_zeros, n_spaces);
	else if (flag->zero)
	{
		padding(' ', n_spaces);
		if (flag->minus)
			write_with_count("-", 1);
		if (!(flag->has_prec && flag->prec <= 0))
			padding('0', n_zeros);
		write_with_count(d_str + flag->minus, len - flag->minus);
	}
	else
		aligined_print(flag, d_str + flag->minus, n_zeros, n_spaces);
	free(d_str);
}
