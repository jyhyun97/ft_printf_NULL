/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_common_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:30:27 by gilee             #+#    #+#             */
/*   Updated: 2021/03/25 16:39:36 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_util.h"

int	set_flag_mem(char *res, char a, int if_con)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = res;
	if (ft_strchr(tmp, a) && !if_con)
	{
		if (a == '.')
			return (1);
		while ((*tmp == '+' || *tmp == '-' || *tmp == '0' || *tmp == ' ') && *tmp != '\0')
		{
			if (*tmp == a)
				count++;
			tmp++;
		}
	}
	return (count);
}

int	set_prev_dot_v(Flag *flag, char *res, va_list *ap)
{
	char	*tmp;
	char	arr[20];
	int		point;
	int		count;

	count = 0;
	ft_memset(arr, 0, sizeof(arr));
	point = flag->space + flag->zero + flag->plus + flag->minus;
	tmp = res + point;
	if (*tmp == '*')
	{
		count = va_arg(*ap, int);
		if (count > -1)
			return (count);
		flag->minus = 1;
		return (-count);
	}
	while(*tmp != '.')
	{
		count = count + 1;
		tmp++;
	}
	if (!count)
		return (0);
	ft_memcpy(arr, res + point, count);
	return (ft_atoi(arr));
}

int	set_after_dot_v(char *res, char type, va_list *ap)
{
	char	*tmp;
	char	arr[20];
	int		value;
	int		count;

	value = 0;
	count = 0;
	ft_memset(arr, 0, sizeof(arr));
	tmp = ft_strchr(res, '.') + 1;
	if (*tmp == '*')
	{
		count = va_arg(*ap, int);
		return (count);
	}
	while (*tmp++ != type)
		value++;
	if (!value)
		return (0);
	ft_memcpy(arr, ft_strchr(res, '.') + 1, value);
	return (ft_atoi(arr));
}

int	set_no_dot_v(Flag *flag, char *res, char type, va_list *ap)
{
	char	*tmp;
	char	arr[20];
	int		point;
	int		value;
	int		count;

	point = 0;
	value = 0;
	ft_memset(arr, 0, 20);
	point = flag->space + flag->zero + flag->plus + flag->minus;
	tmp = res + point;
	if (*tmp == '*')
	{
		count = va_arg(*ap, int);
		if (count > -1)
			return (count);
		flag->minus = 1;
		return (-count);
	}
	while(*tmp++ != type)
		value++;
	if (!value)
		return (0);
	ft_memcpy(arr, res + point, value);
	return (ft_atoi(arr));
}