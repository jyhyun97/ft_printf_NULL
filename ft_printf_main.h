#ifndef FT_PRINTF_MAIN_H
# define FT_PRINTF_MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int		plus;
	int		minus;
	int		shap;
	int		space;
	int		zero;
	int		width;
	int		precision;
	int		length;
}				t_flag;

typedef struct	s_size
{
	int		all_size;
}				t_size;

int			ft_printf(const char *format, ...);
int			format_checker(const char *format, va_list ap);
void		ft_putchr(char *format, int i);
void		ft_free(char *ptr);
char 		*ft_calloc(int len);
void    	flag_size_reset(void);
void		change_int(int value, char c);
void		change_string(char * s);

#endif
