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

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *d, void const *s, size_t n);
size_t	ft_strlen(const char *src);
#endif