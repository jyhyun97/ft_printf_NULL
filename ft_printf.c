#include "ft_printf.h"
#include <stdio.h>

t_list	g_check;

static char *frist_ptr(const char *s, char *ptr)
{
	int		i;

	i = 0;
	while (s[i] != '%')
		++i;
	if (i == 0)
	{
		ptr = (char *)malloc(sizeof(char) * 1);
		ptr = 0;
	}
	else
	{
		ptr = (char *)malloc(sizeof(char) * i);
		if (!ptr)
			return (NULL);
		g_check.size = i;
		ptr[i] = 0;
		while (--i > -1)
			ptr[i] = s[i];
	}
	return (ptr);
}

static char	*write_ptr(const char *s, char *ptr)
{
	int i;
	int cp_i;
	char *tmp;

	i = 0;
	while(s[i] != '%')
		i++;
	if (i == 0)
		return (ptr);
	if (ptr != 0)
		tmp = ptr;
	else
		tmp = 0;
	cp_i = i;
	ptr = (char *)malloc(sizeof(char) * g_check.size + i);
	free(tmp);
	tmp = 0;
	if (!ptr)
		ptr = 0;
	ptr[g_check.size + i] = 0;
	while (--i > -1)
		ptr[g_check.size + i] = s[i];
	g_check.size = g_check.size + cp_i;
	while (*ptr)
	{
		printf("%s\n", ptr);
		ptr++;
	}
	s = s + cp_i;
	return (ptr);
}

char *ft_format(const char *s, char *ptr)
{
	if(*s == 'd')
		++s;
	return ((char *)s);
}

int		ft_printf(const char *s, ...)
{
	va_list lt;
	char	*ptr;

	va_start(lt, s);
	ft_lstadd();
	ptr = frist_ptr(s, ptr);
	s = s + g_check.size;
	while (*s)
	{
		if (*s == '%')
		{
			s = ft_format(++s, ptr);
		}
		ptr = write_ptr(s, ptr);
		s++;
	}
	free(ptr);
	ptr = 0;
}

int		main(void)
{
	ft_printf("aaaaa %d, dddd %d, cccc %d\n", 123456, 1, 2);
	return (0);
}
