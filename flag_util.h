#ifndef FLAG_UTIL_H
# define FLAG_UTIL_H
#include "ft_printf.h"
int		set_flag_mem(char *res, char a, int if_con);
int		set_prev_dot_v(Flag *flag, char *res, va_list *ap);
int		set_after_dot_v(char *res, char type, va_list *ap);
int		set_no_dot_v(Flag *flag, char *res, char type, va_list *ap);
#endif