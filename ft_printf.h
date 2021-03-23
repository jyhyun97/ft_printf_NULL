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
    int v_len;
    int p_len;
    int sign;
    char *pvalue;
} Flag;

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *d, void const *s, size_t n);
size_t	ft_strlen(const char *src);
char	*ft_itoa_base(long long value, int base);

int ft_printf(const char *format, ...);
#endif