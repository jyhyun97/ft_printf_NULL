/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:38:45 by gilee             #+#    #+#             */
/*   Updated: 2021/03/28 16:49:08 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_UTIL_H
# define FLAG_UTIL_H
# include "ft_printf.h"

int		set_flag_mem(char *res, char a, int if_con);
int		set_prev_dot_v(t_flag **flag, char *res, va_list *ap);
int		set_after_dot_v(char *res, char type, va_list *ap);
int		set_no_dot_v(t_flag **flag, char *res, char type, va_list *ap);
#endif
