/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:36:04 by jso               #+#    #+#             */
/*   Updated: 2021/03/05 12:25:12 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flag
{
	int			minus;
	int			zero;
	int			precision;
	int			width;
	char		type;
	int			count;
}				t_flag;

t_flag			g_flag;

/*
**	Func in the ft_utils.c file.
*/

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);

#endif
