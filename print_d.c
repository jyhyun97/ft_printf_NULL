/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:18:37 by gilee             #+#    #+#             */
/*   Updated: 2021/03/26 22:17:38 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_d_sign(Flag *flag)
{
	if (flag->value <0)
		put_str("-");
}

static void	set_d_flag(Flag *flag)
{
	flag->sign = 1;
	if (flag->value < 0)
		flag->sign = -1;
	flag->pvalue = ft_itoa(flag->sign * flag->value);
	if (*(flag->pvalue) == '0' && flag->precision == 0 && flag->dot)
		flag->v_len = 0;
	else
		flag->v_len = ft_strlen(flag->pvalue);
	flag->p_len = flag->precision - flag->v_len;
	if (flag->precision < 0)
		flag->dot = 0;
}

void	    print_d(va_list *ap, char *res, char type)
{
	Flag	*flag;

	make_flag(&flag);
	set_flag(flag, ap, res, type);
	set_d_flag(flag);
	if (flag->minus)
		print_in_order(flag, print_d_sign, print_value, print_width);
	else
	{
		if (flag->dot)
			print_in_order(flag, print_width, print_d_sign, print_value);
		else
		{
			if (flag->zero)
				print_in_order(flag, print_d_sign, print_width, print_value);
			else
				print_in_order(flag, print_width, print_d_sign, print_value);
		}
	}
	free(flag->pvalue);
	delete_flag(&flag);
}