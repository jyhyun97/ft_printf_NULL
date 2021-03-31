/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:56:39 by gilee             #+#    #+#             */
/*   Updated: 2021/03/29 13:36:20 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_per_flag(t_flag **flag)
{
	(*flag)->pvalue = "%";
	(*flag)->v_len = 1;
}

static void	put_per_value(t_flag **flag)
{
	write(1, (*flag)->pvalue, (*flag)->v_len);
	g_count += (*flag)->v_len;
}

static void	put_per_width(t_flag **flag)
{
	char	*pad;
	int		real_len;

	real_len = (*flag)->width - (*flag)->v_len;
	if (!(*flag)->zero || ((*flag)->zero && (*flag)->minus))
		pad = " ";
	else
		pad = "0";
	while (real_len-- > 0)
		put_str(pad);
}

int			print_per(va_list *ap, char *res, char type)
{
	t_flag	*flag;

	if (make_flag(&flag) == ERR)
		return (ERR);
	set_flag(&flag, ap, res, type);
	set_per_flag(&flag);
	if (flag->minus)
		print_in_order(&flag, put_per_value, put_per_width, 0);
	else
		print_in_order(&flag, put_per_width, put_per_value, 0);
	delete_flag(&flag);
	return (DONE);
}
