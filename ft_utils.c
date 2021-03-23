#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pb;
	unsigned char	pc;

	pb = b;
	pc = c;
	while (len-- > 0)
		*pb++ = pc;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void *rest;

	if (!(rest = (void *)malloc(count * size)))
		return (NULL);
	ft_memset(rest, 0, (count * size));
	return (rest);
}

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
	if (src)
	{
		while (*src++ != '\0')
		{
			count++;
		}
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