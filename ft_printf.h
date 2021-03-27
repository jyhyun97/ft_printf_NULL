/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:48:17 by gilee             #+#    #+#             */
/*   Updated: 2021/03/27 21:00:54 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int				g_count;
typedef struct	s_flag {
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	int		value;
	int		v_len;
	int		p_len;
	int		sign;
	char	type;
	char	*pvalue;
}				t_flag;

void			print_per(va_list *ap, char *res, char type);
void			print_c(va_list *ap, char *res, char type);
void			print_s(va_list *ap, char *res, char type);
void			print_d(va_list *ap, char *res, char type);
void			print_p(va_list *ap, char *res, char type);
void			print_x(va_list *ap, char *res, char type);
void			print_u(va_list *ap, char *res, char type);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			*ft_itoa(long long n);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
void			*ft_memcpy(void *d, void const *s, size_t n);
size_t			ft_strlen(const char *src);
char			*ft_itoa_base(long long value, int base, int is_upper);

void			make_flag(t_flag **flag);
void			delete_flag(t_flag **flag);
void			set_flag(t_flag *flag, va_list *ap, char *res, char type);

void			put_str(char *a);
void			print_value(t_flag *flag);
void			print_width(t_flag *flag);
void			print_in_order(t_flag *flag, \
void (*a)(t_flag *), void (*b)(t_flag *), void (*c)(t_flag *));

void			set_res(va_list *ap, char *res);
char			*set_dtarg(char *a, int *k);
int				checker(va_list *ap, const char *a);
void			print_rst(va_list *ap, const char *format);
int				ft_printf(const char *format, ...);
#endif
