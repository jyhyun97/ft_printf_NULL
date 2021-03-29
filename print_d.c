/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:18:37 by gilee             #+#    #+#             */
/*   Updated: 2021/03/29 13:48:56 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_d_sign(t_flag **flag)
{
	if ((*flag)->value < 0)
		put_str("-");
}

static int	set_d_flag(t_flag **flag)
{
	(*flag)->sign = 1;
	if ((*flag)->value < 0)
		(*flag)->sign = -1;
	(*flag)->pvalue = ft_itoa((*flag)->sign * (*flag)->value);
	if (!(*flag)->pvalue)
		return (ERR);
	if (*((*flag)->pvalue) == '0' && (*flag)->precision == 0 && (*flag)->dot)
		(*flag)->v_len = 0;
	else
		(*flag)->v_len = ft_strlen((*flag)->pvalue);
	(*flag)->p_len = (*flag)->precision - (*flag)->v_len;
	if ((*flag)->precision < 0)
		(*flag)->dot = 0;
	return (DONE);
}

int			print_d(va_list *ap, char *res, char type)
{
	t_flag	*flag;

	if (make_flag(&flag) == ERR)
		return (ERR);
	set_flag(&flag, ap, res, type);
	if (set_d_flag(&flag) == ERR)
		return (free_n_err(&flag));
	if (flag->minus)
		print_in_order(&flag, print_d_sign, print_value, print_width);
	else
	{
		if (flag->dot)
			print_in_order(&flag, print_width, print_d_sign, print_value);
		else
		{
			if (flag->zero)
				print_in_order(&flag, print_d_sign, print_width, print_value);
			else
				print_in_order(&flag, print_width, print_d_sign, print_value);
		}
	}
	free(flag->pvalue);
	delete_flag(&flag);
	return (DONE);
}
