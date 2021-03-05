/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:36:29 by jawpark           #+#    #+#             */
/*   Updated: 2021/03/04 17:33:44 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int		plus;
	int		minus;
	int		shap;
	int		zero;
	int		space;
	int		dot;
	int		width;
	int		precision;
}				t_flag;

typedef struct	s_size
{
	int		all_size;
}				t_size;

int				ft_printf(const char *s, ...);
void			ft_free_reset(char *ptr);
void			ft_size_reset(void);
void			ft_putchr(char *c, int len);
void			ft_flag_reset(void);
char			*ft_calloc(int len);
int				flag_save(char c);
int				wpl_check(char c, va_list ap);
int				flag_format_checker(const char *c);
void			pf_format_checker(va_list ap, char c);
void			flag_save_checker(int i, char c);
char			*change_wpl(int len);
int				wpl_negative(char c);
void			pf_format_s(char *ptr);
void			pf_format_c(int value);
void			pf_format_pc(void);
void			pf_format_p(void *p, char c);
void			pf_format_x(unsigned int x, char c);
char			*ft_hexadecimal(char c);
void			ft_x_frist(char *ptr, int len);
int				ft_ux_len(unsigned int x, char c);
int				ft_p_len(unsigned long long p);
void			ft_x_shap(char *ptr, int len, int cp_len, char c);
void			pf_format_u(unsigned int x, char c);
void			pf_format_di(int di);
char			*pf_di_input(char *ptr, int di, int len, int cp_len);
void			u_dot_input(char *ptr, int len);
int				ft_di_len(int di);
int				ft_wp_len(int len, int di, int cp_len);

#endif
