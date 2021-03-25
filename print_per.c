/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:56:39 by gilee             #+#    #+#             */
/*   Updated: 2021/03/25 18:05:59 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_per(va_list *ap, char *res)
{
	Flag	*flag;
	size_t	len;
	int		real_len;
	char	*pad;

	flag = (Flag *)ft_calloc(1, sizeof(Flag));
	set_flag(flag, ap, res, '%');
	if (!flag->zero || (flag->zero && flag->minus))
		pad = " ";
	else
		pad = "0";
	len = 1;
	real_len = flag->width - (int)len;
	if (flag->minus)
	{
		write(1, "%", len);
		g_count += len;
		while (real_len-- > 0)
			put_str(pad);
	}
	else
	{
		while (real_len-- > 0)
			put_str(pad);
		write(1, "%", len);
		g_count += len;
	}
	free(flag);
}