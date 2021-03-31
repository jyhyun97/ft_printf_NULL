/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:05:09 by gilee             #+#    #+#             */
/*   Updated: 2021/03/29 13:48:56 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_p_flag(t_flag **flag, va_list *ap)
{
	(*flag)->pvalue = ft_itoa_base(va_arg(*ap, long long), 16, 0);
	if (!(*flag)->pvalue)
		return (ERR);
	(*flag)->v_len = ft_strlen((*flag)->pvalue);
	if (*((*flag)->pvalue) == '0' && (*flag)->dot && (*flag)->precision >= 0)
		(*flag)->v_len = 0;
	return (DONE);
}

static void	put_p_value(t_flag **flag)
{
	put_str("0x");
	write(1, (*flag)->pvalue, (*flag)->v_len);
	g_count += (*flag)->v_len;
}

static void	put_p_width(t_flag **flag)
{
	int real_len;

	real_len = (*flag)->width - ((*flag)->v_len + 2);
	while (real_len-- > 0)
		put_str(" ");
}

int			print_p(va_list *ap, char *res, char type)
{
	t_flag	*flag;

	if (make_flag(&flag) == ERR)
		return (ERR);
	set_flag(&flag, ap, res, type);
	if (set_p_flag(&flag, ap) == ERR)
		return (free_n_err(&flag));
	if (flag->minus)
		print_in_order(&flag, put_p_value, put_p_width, 0);
	else
		print_in_order(&flag, put_p_width, put_p_value, 0);
	free(flag->pvalue);
	delete_flag(&flag);
	return (DONE);
}
