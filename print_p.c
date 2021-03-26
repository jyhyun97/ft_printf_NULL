/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:05:09 by gilee             #+#    #+#             */
/*   Updated: 2021/03/26 22:39:36 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_p_flag(Flag *flag, va_list *ap)
{
	flag->pvalue = ft_itoa_base(va_arg(*ap, long long), 16, 0);
	flag->v_len = ft_strlen(flag->pvalue);
	if (*(flag->pvalue) == '0' && flag->dot)
		flag->v_len = 0;
}

static void	put_s_value(Flag *flag)
{
	put_str("0x");
	write(1, flag->pvalue, flag->v_len);
	g_count += flag->v_len;
}

static void put_s_width(Flag *flag)
{
	int real_len;

	real_len = flag->width - (flag->v_len + 2);
	while (real_len-- > 0)
		put_str(" ");
}

void	print_p(va_list *ap, char *res, char type)
{
	Flag	*flag;

	make_flag(&flag);
	set_flag(flag, ap, res, type);
	set_p_flag(flag, ap);
	if (flag->minus)
		print_in_order(flag, put_s_value, put_s_width, 0);
	else
		print_in_order(flag, put_s_width, put_s_value, 0);
	free(flag->pvalue);
	delete_flag(&flag);
}