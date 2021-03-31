/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:02:41 by gilee             #+#    #+#             */
/*   Updated: 2021/03/29 13:48:56 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_x_flag(t_flag **flag)
{
	int	is_upper;

	is_upper = 0;
	if ((*flag)->type == 'X')
		is_upper = 1;
	if ((*flag)->value < 0)
		(*flag)->pvalue = \
		ft_itoa_base(4294967295 + (*flag)->value + 1, 16, is_upper);
	else
		(*flag)->pvalue = ft_itoa_base((*flag)->value, 16, is_upper);
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

int			print_x(va_list *ap, char *res, char type)
{
	t_flag	*flag;

	if (make_flag(&flag) == ERR)
		return (ERR);
	set_flag(&flag, ap, res, type);
	if (set_x_flag(&flag) == ERR)
		return (free_n_err(&flag));
	if (flag->minus)
		print_in_order(&flag, 0, print_value, print_width);
	else
	{
		if (flag->dot)
			print_in_order(&flag, print_width, 0, print_value);
		else
		{
			if (flag->zero)
				print_in_order(&flag, 0, print_width, print_value);
			else
				print_in_order(&flag, print_width, 0, print_value);
		}
	}
	free(flag->pvalue);
	delete_flag(&flag);
	return (DONE);
}