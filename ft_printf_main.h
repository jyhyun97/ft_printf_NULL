#ifndef FT_PRINTF_MAIN_H
# define FT_PRINTF_MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int		plus;
	int		minus;
	int		shap;
	int		space;
	int		zero;
}				t_flag;

typedef struct	s_size
{
	int		width;
	int		precision;
	int		length;
}				t_size;

int		ft_printf(const char *format, ...);

#endif
