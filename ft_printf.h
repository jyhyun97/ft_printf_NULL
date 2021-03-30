/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:24:55 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/30 23:26:20 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# define TYPE "cspdiuxX%fge"
# define FLAG "-0# +*.lh"
# define SUCCESS 1
# define WARN 0
# define ERR -1

typedef struct	s_list
{
	int			left;
	int			zero;
	int			width;
	int			has_prec;
	int			prec;
	int			minus;
}				t_list;

void			initialize_flag(t_list *flag);
int				collect_prec(t_list *flag, va_list ap, char *str,
				int first_digit);
int				set_precision(char *str, t_list *flag, va_list ap);
int				collect_width(t_list *flag, va_list ap, char *str,
				int first_digit);
int				set_flags(char *str, t_list *flag, va_list ap);
void			padding_non_prec(t_list *flag, int *zeros, int *spaces,
				int *len);
void			calculate_paddings(t_list *flag, int *zeros, int *spaces,
				int len);
void			print_p(t_list *flag, long long long_d, char *base_set);
void			print_x(t_list *flag, long long long_d, char *base_set);
void			aligined_print(t_list *flag, char *str, int zeros, int spaces);
void			print_u(t_list *flag, va_list ap);
void			print_d(t_list *flag, int d, char *d_str, int len);
int				print_c(t_list *flag, char type, char c);
void			print_s(char *str, t_list *flag);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strdup(const char *s);
int				ft_isdigit(char c);
char			*ft_strchr(const char *s, int c);
void			write_with_count(char *c, int n);
void			initialize_flag(t_list *flag);
int				digit_length(long long int n, int base);
char			*ft_itoa_base(long long int n, char *base_set);
void			padding(char c, int n);
void			print_format(char type, t_list *flag, va_list ap);
int				check_types(char *option, va_list ap);
int				ft_printf(const char *format, ...);
#endif
