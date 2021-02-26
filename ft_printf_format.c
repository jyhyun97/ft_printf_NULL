#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

void		wpl_negative(void)
{
	if (g_flag.precision < 0)
	{
		g_flag.precision *= -1;
		g_flag.minus = 1;
	}
	if (g_flag.width < 0)
	{
		g_flag.width *= -1;
		g_flag.minus = 1;
	}
}

char		*change_wpl(int len)
{
	char	*ptr;

	if (g_flag.width > len)
		ptr = ft_calloc(g_flag.width);
	else
		ptr = ft_calloc(len);
	return (ptr);
}

void		pf_format_checker(va_list ap, char c)
{
	if (c == 's')
		pf_format_s(va_arg(ap, char*));
	else if (c == 'c')
		pf_format_c(va_arg(ap, int));
	else if (c == 'p')
		pf_format_p(va_arg(ap, void*), c);
	else if (c == 'x' || c == 'X')
		pf_format_x(va_arg(ap, unsigned int), c);
	else if (c == 'u')
		pf_format_u(va_arg(ap, unsigned int), c);
	else if (c == 'd' || c == 'i')
		pf_format_di(va_arg(ap, int), c);
	else if (c == '%')
		pf_format_pc(c);
}
