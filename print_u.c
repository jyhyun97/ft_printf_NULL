/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:00:42 by gilee             #+#    #+#             */
/*   Updated: 2021/03/26 22:18:41 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_u_flag(Flag *flag)
{
	if (flag->value < 0)
		flag->pvalue = ft_itoa(4294967295 + flag->value + 1);
	else
		flag->pvalue = ft_itoa(flag->value);
	if (*(flag->pvalue) == '0' && flag->precision == 0 && flag->dot)
		flag->v_len = 0;
	else
		flag->v_len = ft_strlen(flag->pvalue);
	flag->p_len = flag->precision - flag->v_len;
	if (flag->precision < 0)
		flag->dot = 0;
}

void		print_u(va_list *ap, char *res, char type)
{
	Flag    *flag;

	make_flag(&flag);
	set_flag(flag, ap, res, type);
	set_u_flag(flag);
	if (flag->minus)
		print_in_order(flag, 0, print_value, print_width);
	else
	{
		if (flag->dot)
			print_in_order(flag, print_width, 0, print_value);
		else
		{
			if (flag->zero)
				print_in_order(flag, 0, print_width, print_value);
			else
				print_in_order(flag, print_width, 0, print_value);
		}
	}
	free(flag->pvalue);
	delete_flag(&flag);
}