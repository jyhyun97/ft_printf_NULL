/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:24:55 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/26 02:25:08 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define TYPE "cspdiuxX%nfge"
# define FLAG "-# +*.lh"

typedef struct t_list
{
	int left;
	int zero;
	int has_width;
	int width;
	int has_prec;
	int prec;
	int minus;
} s_list;

void init_flag();
char *check_flag(char *a);
char *check_width(char *a, va_list ap);
char *check_precision(char *a, va_list ap);
void check_type(char *a);

void print_all(va_list ap);
int print_c(va_list ap);
int print_s(va_list ap);
int print_d(va_list ap);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int ft_printf(const char *format, ...);
#endif
