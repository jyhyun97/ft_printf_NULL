#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
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

//ft_printf_utils.c
void			ft_free_reset(char *ptr);
void			ft_size_reset(void);
void			ft_putchr(char *c, int len);
void			ft_flag_reset(void);
char			*ft_calloc(int len);
//ft_printf_flag.c
int				flag_save(char c);
int				wpl_check(char c, va_list ap);
int				flag_format_checker(const char *c);
//ft_printf_format.c
void			pf_format_checker(va_list ap, char c);
char			*change_wpl(int len);
void			wpl_negative(void);
//ft_printf_string.c
void			pf_format_s(char *ptr);
void			pf_format_c(int value);
void			pf_format_pc(char c);
//ft_printf_xp.c
void			pf_format_p(void *p, char c);
void			pf_format_x(unsigned int x, char c);
//ft_printf_xp_utils.c
char			*ft_hexadecimal(char c);
void			ft_x_frist(char *ptr, char c, int len, int cp_len);
int				ft_ux_len(unsigned int x, char c);
int				ft_len(int len, unsigned long long p, char c);
//ft_printf_diu.c
void			pf_format_u(unsigned int x, char c);
void			pf_format_di(int di, char c);
//ft_printf_diu_utils.c
char			*pf_di_input(char *ptr, int di, int len, int cp_len);

#endif
