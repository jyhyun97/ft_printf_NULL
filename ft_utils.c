#include "ft_printf.h"

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