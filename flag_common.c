/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:26:33 by gilee             #+#    #+#             */
/*   Updated: 2021/03/25 16:40:53 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_util.h"

void	set_flag(Flag *flag, va_list *ap, char *res, char type)
{
	flag->space = set_flag_mem(res, ' ', 0);
	flag->dot = set_flag_mem(res, '.', 0);
	flag->zero = set_flag_mem(res, '0', 0);
	flag->plus = set_flag_mem(res, '+', flag->space);
	flag->minus = set_flag_mem(res, '-', flag->zero);
	if (flag->dot)
	{
		flag->width = set_prev_dot_v(flag, res, ap);
		flag->precision = set_after_dot_v(res, type, ap);
	}
	else
		flag->width = set_no_dot_v(flag, res, type, ap);
	if (flag->value < 0 || (flag->value >= 0 && flag->plus))
		flag->space = 0;
	if (type == 'c' || type == 'd' || type == 'i')
		flag->value = va_arg(*ap, int);
	else if (type == 'u')
		flag->value = va_arg(*ap, unsigned int);
	else if (type == 'x')
		flag->value = va_arg(*ap, long long);
}