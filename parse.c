/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:02:48 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/30 23:01:12 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_flag(t_list *flag)
{
	flag->left = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->has_prec = 0;
	flag->prec = 0;
	flag->minus = 0;
}

int		collect_prec(t_list *flag, va_list ap, char *str, int first_digit)
{
	if (*str == '*' || ft_isdigit(*str))
	{
		if ((flag->has_prec && *str == '*') ||
			(flag->has_prec && ft_isdigit(*str) && first_digit))
			return (ERR);
		if (!flag->has_prec)
			flag->has_prec = 1;
		if (*str == '*')
		{
			flag->prec = va_arg(ap, int);
			if (flag->prec < 0)
				flag->has_prec = 0;
		}
		else
		{
			flag->prec = flag->prec * 10 + (*str - '0');
			first_digit = 0;
		}
	}
	else
		return (ERR);
	return (first_digit);
}

int		set_precision(char *str, t_list *flag, va_list ap)
{
	int		first_digit;

	if (!*str)
	{
		flag->has_prec = -1;
		return (SUCCESS);
	}
	first_digit = 1;
	while (*str)
	{
		if ((first_digit = collect_prec(flag, ap, str, first_digit)) < 0)
			return (WARN);
		str++;
	}
	return (SUCCESS);
}

int		collect_width(t_list *flag, va_list ap, char *str, int first_digit)
{
	if (*str == '*' || ft_isdigit(*str))
	{
		if ((flag->width > 0 && *str == '*') ||
			(flag->width > 0 && ft_isdigit(*str) && first_digit))
			return (ERR);
		if (*str == '*')
		{
			flag->width = va_arg(ap, int);
			if (flag->width < 0)
			{
				flag->width *= -1;
				flag->left = 1;
				flag->zero = 0;
			}
		}
		else
		{
			flag->width = flag->width * 10 + (*str - '0');
			first_digit = 0;
		}
	}
	return (first_digit);
}

int		set_flags(char *str, t_list *flag, va_list ap)
{
	int		first_digit;

	first_digit = 1;
	while (*str)
	{
		if (!(ft_strchr(FLAG, *str) || ft_isdigit(*str)))
			return (WARN);
		if (*str == '.')
			return (set_precision(str + 1, flag, ap));
		if (*str == '0' && flag->width == 0 && flag->left == 0)
			flag->zero = 1;
		if (*str == '-')
			flag->left = 1;
		if ((first_digit = collect_width(flag, ap, str, first_digit)) < 0)
			return (WARN);
		str++;
	}
	return (SUCCESS);
}
