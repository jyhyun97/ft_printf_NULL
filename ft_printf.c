#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *src)
{
	size_t count;

	count = 0;
	while (*src++ != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char		*rest;
	const char	*ps1;
	size_t		len;

	ps1 = s1;
	len = ft_strlen(s1);
	if (!(rest = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (len--)
	{
		*rest++ = *ps1++;
	}
	*rest = '\0';
	return (rest - ft_strlen(s1));
}

int	is_flag(char **conv)
{
		(*conv)++;
		if (**conv == 'c')
			return (1);
		else if (**conv == 's')
			return (1);
		else if (**conv == 'p')
			return (1);
		else if (**conv == 'd')
			return (1);
		else if (**conv == 'i')
			return (1);
		else if (**conv == 'u')
			return (1);
		else if (**conv == 'x')
			return (1);
		else if (**conv == 'X')
			return (1);
		else if (**conv == '%')
			return (0);
	return (0);
}

int	find_per(const char *conv_c, char buf[])
{
	char	*conv;
	int		k;

	k = 0;
	conv = ft_strdup(conv_c);
	while (*conv)
	{
		if (*conv == '%')
		{
			if (is_flag(&conv))
			{
				buf[k++] = *conv;
			}
		}
		conv++;
	}
	return (0);
}

int	ft_printf(const char *conv, ...)
{
	//va_list al;
	char	buf[10000];
	int		k;

	k = 0;
	find_per(conv, buf);
	while (buf[k])
		printf("%c\n",buf[k++]);
	return (0);
}

int main ()
{
	ft_printf("%d %% %c");
	return 0;
}
