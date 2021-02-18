#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *d, void const *s, size_t n);
size_t	ft_strlen(const char *src);
#endif