#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (*s++ == (char)c)
			return ((char *)--s);
	}
	return (NULL);
}

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

void	*ft_memcpy(void *d, void const *s, size_t n)
{
	char			*pd;
	char const		*ps;

	pd = d;
	ps = s;
	if (n == 0)
		return (d);
	if ((ps == NULL) && (pd == NULL))
		return (NULL);
	if ((ps != NULL) || (pd != NULL))
	{
		while (n--)
			*pd++ = *ps++;
	}
	return (d);
}