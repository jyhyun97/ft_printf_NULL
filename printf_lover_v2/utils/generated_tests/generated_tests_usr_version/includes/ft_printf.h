#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int g_count;

typedef struct _flag {
    int minus;
    int plus;
    int space;
    int zero;
    int dot;
    int width;
    int precision;
    int value;
    char *pvalue;
} Flag;

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *d, void const *s, size_t n);
size_t	ft_strlen(const char *src);

void    init_flag(Flag *flag);
int set_flag(char **res, char a, int if_con);
int    set_prev_dot_v(Flag *flag, char **res, va_list ap);
int    set_after_dot_v(char **res, char type, va_list ap);
int    set_no_dot_v(Flag *flag, char **res, char type, va_list ap);
Flag    set_opt(va_list ap, char **res, char type);
void    set_d(va_list ap, char **res, int *count);
void print_c(va_list ap, char **res);
void print_s(va_list ap, char **res);
int set_res(va_list ap, char **res);
char    *set_dtarg(char *a, int *k);
int checker(va_list ap, const char *a);
void print_rst(va_list ap, const char *format);
int ft_printf(const char *format, ...);
#endif