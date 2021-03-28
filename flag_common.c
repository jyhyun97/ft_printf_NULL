/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:26:33 by gilee             #+#    #+#             */
/*   Updated: 2021/03/28 21:16:33 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_util.h"

void	make_flag(t_flag **flag)
{
	*flag = (t_flag *)ft_calloc(1, sizeof(t_flag));
}

void	delete_flag(t_flag **flag)
{
	free(*flag);
	*flag = 0;
}

void	set_flag(t_flag **flag, va_list *ap, char *res, char type)
{
	(*flag)->type = type;
	(*flag)->space = set_flag_mem(res, ' ', 0);
	(*flag)->dot = set_flag_mem(res, '.', 0);
	(*flag)->zero = set_flag_mem(res, '0', 0);
	(*flag)->plus = set_flag_mem(res, '+', (*flag)->space);
	(*flag)->minus = set_flag_mem(res, '-', 0);
	if ((*flag)->dot)
	{
		(*flag)->width = set_prev_dot_v(flag, res, ap);
		(*flag)->precision = set_after_dot_v(res, type, ap);
	}
	else
		(*flag)->width = set_no_dot_v(flag, res, type, ap);
	if ((*flag)->value < 0 || ((*flag)->value >= 0 && (*flag)->plus))
		(*flag)->space = 0;
	if ((*flag)->type == 'c' || (*flag)->type == 'd' || (*flag)->type == 'i')
		(*flag)->value = (long long)va_arg(*ap, int);
	else if ((*flag)->type == 'u')
		(*flag)->value = (long long)va_arg(*ap, int);
	else if ((*flag)->type == 'x' || (*flag)->type == 'X')
		(*flag)->value = (long long)va_arg(*ap, int);
}
