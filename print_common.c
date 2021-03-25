/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:22:06 by gilee             #+#    #+#             */
/*   Updated: 2021/03/25 17:36:57 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_str(char *a)
{
	int	n;

	n = ft_strlen(a);
	write (1, a, n);
	g_count += n;
}

void	print_value(Flag *flag)
{
    int	p_len;

    p_len = flag->p_len;
    while (--p_len >= 0)
        put_str("0");
    write(1, flag->pvalue, flag->v_len);
    g_count += flag->v_len;
}

void	print_width(Flag *flag)
{
	char	*pad;
	int		real_len;
	int		sign;

	sign = 0;
	if (flag->value < 0)
		sign = 1;
	if (flag->zero && !flag->dot && !flag->minus)
		pad = "0";
	else
		pad = " ";
	if (flag->p_len >= 0)
		real_len = flag->width - (flag->v_len + flag->p_len) - sign;
	else
		real_len = flag->width - flag->v_len - sign;
	while (--real_len >= 0)
		put_str(pad);
}

void    print_in_order(Flag *flag, void (*a)(Flag *),void (*b)(Flag *), void (*c)(Flag *))
{
	if (a != 0)
		a(flag);
	if (b != 0)
		b(flag);
	if (c != 0)
		c(flag);
}