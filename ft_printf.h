/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:17:14 by jawpark           #+#    #+#             */
/*   Updated: 2021/02/09 11:17:14 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
stdarg.h는 C의 C 표준 라이브러리의 헤더로 인자 수를 제한 없이 할 수 있도록 하는 함수를 허용할 수 있도록 한다
va_list, va_start, va_arg, va_end가 정의된 헤더 파일
*/
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef	struct	s_list
{
	int			flag;
	int			width;
	int			psc;
	int			len;
	int			size;
}				t_list;

//ft_printf_utils.c
void			ft_lstadd(void);
char			*ft_malloc_input(char *s, int len);

char			*ft_ptr_int(int value, char *ptr, char c);
char			*ft_strlcpy(char *s1, char *s2, char *s3);

#endif
