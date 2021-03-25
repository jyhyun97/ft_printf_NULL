/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:51:49 by gilee             #+#    #+#             */
/*   Updated: 2021/03/25 17:55:42 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list *ap, char *res)
{
	Flag	*flag;

	flag = (Flag *)ft_calloc(1, sizeof(Flag));
	set_flag(flag, ap, res, 'c');
	if (flag->minus)
	{
		write(1, &(flag->value), 1);
		g_count++;
		while (--flag->width > 0)
			put_str(" ");
	}
	else
	{
		while (--flag->width > 0)
			put_str(" ");
		write(1, &(flag->value), 1);
		g_count++;
	}
	free(flag);
}