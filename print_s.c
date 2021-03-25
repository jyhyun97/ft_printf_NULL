/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:52:50 by gilee             #+#    #+#             */
/*   Updated: 2021/03/25 17:55:47 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(va_list *ap, char *res)
{
	Flag	*flag;
	size_t	len;
	int		real_len;

	flag = (Flag *)ft_calloc(1, sizeof(Flag));
	set_flag(flag, ap, res, 's');
	flag->pvalue = va_arg(*ap, char *);
	if (!flag->pvalue)
		flag->pvalue = "(null)";
	len = ft_strlen(flag->pvalue);
	if (flag->dot && flag->precision >= 0 && ((int)len >= flag->precision))
		len = flag->precision;
	real_len = flag->width - (int)len;
	if (flag->minus)
	{
		write(1, flag->pvalue, len);
		g_count += len;
		while (real_len-- > 0)
			put_str(" ");
	}
	else
	{
		while (real_len-- > 0)
			put_str(" ");
		write(1, flag->pvalue, len);
		g_count += len;
	}
	free(flag);
}