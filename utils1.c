/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:27:23 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/30 23:18:32 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_count;

void		write_with_count(char *c, int n)
{
	write(1, c, n);
	g_count = g_count + n;
}

void		padding(char c, int n)
{
	while (n--)
	{
		write(1, &c, 1);
		g_count++;
	}
}

int			ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void		padding_non_prec(t_list *flag, int *zeros, int *spaces, int *len)
{
	if (flag->zero)
	{
		if (flag->width >= *len)
			*zeros = flag->width - *len;
	}
	else
	{
		if (flag->width >= *len)
			*spaces = flag->width - *len;
	}
}

void		calculate_paddings(t_list *flag, int *zeros, int *spaces, int len)
{
	*zeros = 0;
	*spaces = 0;
	if (flag->prec < 0)
		flag->has_prec = 0;
	if (flag->has_prec)
	{
		if (flag->prec >= len)
		{
			*zeros = flag->prec - (len - flag->minus);
			if (flag->width > flag->prec)
				*spaces = flag->width - (flag->prec + flag->minus);
		}
		else
		{
			if (flag->width >= len)
				*spaces = flag->width - len;
		}
	}
	if (!flag->has_prec)
		padding_non_prec(flag, zeros, spaces, &len);
}
