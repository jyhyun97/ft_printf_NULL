/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:08:06 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/30 21:00:43 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_list *flag, long long long_d, char *base_set)
{
	int		len;
	char	*d_str;

	d_str = ft_itoa_base(long_d, base_set);
	len = ft_strlen(d_str);
	if (flag->has_prec == -1 && long_d == 0)
		len--;
	if (flag->left)
	{
		write_with_count("0x", 2);
		write_with_count(d_str, len);
		if (flag->width > len + 2)
			padding(' ', flag->width - (len + 2));
	}
	else
	{
		if (flag->width > len + 2)
			padding(' ', flag->width - (len + 2));
		write_with_count("0x", 2);
		write_with_count(d_str, len);
	}
	free(d_str);
}

void	print_x(t_list *flag, long long long_d, char *base_set)
{
	int		len;
	int		n_zeros;
	int		n_spaces;
	char	*d_str;

	d_str = ft_itoa_base(long_d, base_set);
	len = ft_strlen(d_str);
	calculate_paddings(flag, &n_zeros, &n_spaces, len);
	if (long_d == 0 && flag->has_prec && flag->prec == 0)
	{
		padding(' ', flag->width);
		free(d_str);
		return ;
	}
	if (flag->left)
	{
		padding('0', n_zeros);
		write_with_count(d_str, len);
		padding(' ', n_spaces);
		return ;
	}
	padding(' ', n_spaces);
	padding('0', n_zeros);
	write_with_count(d_str, len);
	free(d_str);
}

int		print_c(t_list *flag, char type, char c)
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
		return (WARN);
	return (SUCCESS);
}

void	print_s(char *str, t_list *flag)
{
	int		len;

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
	else
	{
		if (flag->width > len)
			padding(' ', flag->width - len);
		write_with_count(str, len);
	}
}
