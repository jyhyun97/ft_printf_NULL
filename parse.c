/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:02:48 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/26 02:04:31 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void initialize_flag(s_list *flag)
{
	flag->left = 0;
	flag->zero = 0;
	flag->has_width = 0;
	flag->width = 0;
	flag->has_prec = 0;
	flag->prec = 0;
	flag->minus = 0;
}

int set_precision(char *str, s_list *flag, va_list ap)
{
	int first_digit;

	if (!*str)
	{
		flag->has_prec = -1;
		return (1);
	}
	first_digit = 1;
	while (*str)
	{
		if (*str == '*' || ft_isdigit(*str))
		{
			if ((flag->has_prec && *str == '*') ||
				(flag->has_prec && ft_isdigit(*str) && first_digit))
				return (0);
			if (!flag->has_prec)
				flag->has_prec = 1;
			if (*str == '*')
			{
				flag->prec = va_arg(ap, int);
				if (flag->prec < 0)
					flag->has_prec = -1;
			}
			else
			{
				flag->prec = flag->prec * 10 + (*str - '0');
				first_digit = 0;
			}
		}
		else
			return (0);
		str++;
	}
	return (1);
}

static int set_flags(char *str, s_list *flag, va_list ap)
{
	int first_digit;

	first_digit = 1;
	while (*str)
	{
		if (!(ft_strchr(FLAG, *str) || ft_isdigit(*str)))
			return (0);
		if (*str == '.')
			return (set_precision(str + 1, flag, ap));
		if (*str == '0' && flag->width == 0 && flag->left == 0)
			flag->zero = 1;
		if (*str == '-')
			flag->left = 1;
		if (*str == '*' || ft_isdigit(*str))
		{
			if ((flag->has_width && *str == '*') ||
				(flag->has_width && ft_isdigit(*str) && first_digit))
				return (0);
			if (*str == '*')
			{
				flag->width = va_arg(ap, int);
				if (flag->width < 0)
				{
					flag->width *= -1;
					flag->left = 1;
				}
			}
			else
			{
				flag->width = flag->width * 10 + (*str - '0');
				first_digit = 0;
			}
			if (!flag->has_width)
				flag->has_width = 1;
		}
		str++;
	}
	return (1);
}
