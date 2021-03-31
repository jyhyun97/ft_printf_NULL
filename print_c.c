/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:51:49 by gilee             #+#    #+#             */
/*   Updated: 2021/03/29 13:52:01 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_c_value(t_flag **flag)
{
	write(1, &((*flag)->value), 1);
	g_count++;
}

static void	put_c_width(t_flag **flag)
{
	while (--(*flag)->width > 0)
		put_str(" ");
}

int			print_c(va_list *ap, char *res, char type)
{
	t_flag	*flag;

	if (make_flag(&flag) == ERR)
		return (ERR);
	set_flag(&flag, ap, res, type);
	if (flag->minus)
		print_in_order(&flag, put_c_value, put_c_width, 0);
	else
		print_in_order(&flag, put_c_width, put_c_value, 0);
	delete_flag(&flag);
	return (DONE);
}