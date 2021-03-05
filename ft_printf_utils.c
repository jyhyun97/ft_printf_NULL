/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:40:55 by jawpark           #+#    #+#             */
/*   Updated: 2021/03/03 20:34:46 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_size g_size;
extern t_flag g_flag;

void		ft_size_reset(void)
{
	g_size.all_size = 0;
}

void		ft_flag_reset(void)
{
	g_flag.minus = 0;
	g_flag.plus = 0;
	g_flag.shap = 0;
	g_flag.space = 0;
	g_flag.zero = 0;
	g_flag.dot = 0;
	g_flag.width = 0;
	g_flag.precision = 0;
}

void		ft_putchr(char *c, int len)
{
	write(1, c, len);
	g_size.all_size += len;
}

void		ft_free_reset(char *ptr)
{
	if (ptr)
		free(ptr);
	ptr = 0;
}

char		*ft_calloc(int len)
{
	char	*ptr;

	if (len == 0)
	{
		ptr = (char *)malloc(sizeof(char) * 1);
		return (0);
	}
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	while (--len > -1)
	{
		if (g_flag.zero == 1 && g_flag.minus != 1)
			ptr[len] = '0';
		else
			ptr[len] = ' ';
	}
	return (ptr);
}
