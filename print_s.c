/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:52:50 by gilee             #+#    #+#             */
/*   Updated: 2021/03/29 13:36:12 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_s_flag(t_flag **flag, va_list *ap)
{
	(*flag)->pvalue = va_arg(*ap, char *);
	if (!(*flag)->pvalue)
		(*flag)->pvalue = "(null)";
	(*flag)->v_len = ft_strlen((*flag)->pvalue);
	if ((*flag)->dot && (*flag)->precision >= 0 \
	&& ((*flag)->v_len >= (*flag)->precision))
		(*flag)->v_len = (*flag)->precision;
}

static void	put_s_value(t_flag **flag)
{
	write(1, (*flag)->pvalue, (*flag)->v_len);
	g_count += (*flag)->v_len;
}

static void	put_s_width(t_flag **flag)
{
	int real_len;

	real_len = (*flag)->width - (*flag)->v_len;
	while (real_len-- > 0)
		put_str(" ");
}

int			print_s(va_list *ap, char *res, char type)
{
	t_flag	*flag;

	if (make_flag(&flag) == ERR)
		return (ERR);
	set_flag(&flag, ap, res, type);
	set_s_flag(&flag, ap);
	if (flag->minus)
		print_in_order(&flag, put_s_value, put_s_width, 0);
	else
		print_in_order(&flag, put_s_width, put_s_value, 0);
	delete_flag(&flag);
	return (DONE);
}
