/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:44:41 by jso               #+#    #+#             */
/*   Updated: 2021/03/05 23:39:08 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(void)
{
	g_flag.minus = 0;
	g_flag.zero = 0;
	g_flag.precision = -1;
	g_flag.width = 0;
	g_flag.type = 0;
}

char	*check_flag(char *fmt)
{
	int i = 0;
	while (a[i] != '\0' && 
