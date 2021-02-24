#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

static char	*pf_u_itoa(unsigned int x, char c, int len, int cp_len)
{
	char	*ptr;
	char	*hex;
	int		value;

	ptr = ft_calloc(len);
	hex = ft_hexadecimal(c);
	value = g_flag.precision;
	if (g_flag.dot == 1)
		while (--value > -1)
			ptr[value] = '0';
	if (g_flag.minus == 1 && g_flag.precision > cp_len)
		cp_len = g_flag.precision;
	while (1)
	{
		if (g_flag.minus == 0)
			ptr[--len] = hex[x % 10];
		else
			ptr[--cp_len] = hex[x % 10];
		x = x / 10;
		if (x == 0)
			break ;
	}
	return (ptr);
}

void		pf_format_u(unsigned int x, char c)
{
	char	*tmp;
	int		len;
	int		cp_len;

	len = ft_ux_len(x, c);
	cp_len = len;
	if (g_flag.width > len)
		len = g_flag.width;
	if (g_flag.precision > len)
		len = g_flag.precision;
	tmp = pf_u_itoa(x, c, len, cp_len);
	ft_putchr(tmp, len);
	ft_free_reset(tmp);
}
