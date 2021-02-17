#include "ft_printf.h"
#include <stdio.h>

t_list	g_check;

static char	*printf_ptr(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] != '%')
		++i;
	g_check.size += i;
	ptr = ft_malloc_input(ptr, g_check.size);
	if (ptr != NULL)
	{
		ptr[i] = 0;
		while (--i > -1)
			ptr[i] = s[i];
	}
	return (ptr);
}

static char	*printf_format(const char *s, char *ptr, va_list lt)
{
	if(*s == 'd' || *s == 'i')
		ptr = ft_ptr_int(va_arg(lt, int), ptr, *s);
}

int			ft_printf(const char *s, ...)
{
	va_list lt;
	char	*ptr;

	va_start(lt, s);
	ft_lstadd();
	ptr = printf_ptr(s);
	s = s + g_check.size;
	while (*s)
	{
		if (*s == '%')
		{
			++s;
			// printf_flags(s, ptr);
			printf_format(s, ptr, lt);
		}
	}
}

int		main(void)
{
	ft_printf("sssss : %d, dddd %d, cccc %d\n", 123456, 1, 2);
	return (0);
}
