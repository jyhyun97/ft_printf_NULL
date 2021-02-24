#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

static int	ft_strlen(char *ptr)
{
	int		i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
		i++;
	return (i);
}

void		pf_format_s(char *ptr)
{
	char	*tmp;
	int		len;
	int		cp_len;
	int		i;

	i = -1;
	len = ft_strlen(ptr);
	tmp = change_wpl(len);
	if (g_flag.dot == 1 && g_flag.precision < len)
		len = g_flag.precision;
	while (g_flag.minus == 1 && ++i < len)
		tmp[i] = ptr[i];
	i = len;
	if (g_flag.width > len)
		i = g_flag.width;
	cp_len = len;
	while (g_flag.minus == 0 && --i > -1 && --cp_len > -1)
		tmp[i] = ptr[cp_len];
	if (g_flag.width > len)
		len = g_flag.width;
	ft_putchr(tmp, len);
	ft_free_reset(tmp);
}


void		pf_format_c(int value)
{
	char	*tmp;
	int		len;

	len = 1;
	tmp = change_wpl(len);
	if (g_flag.width > len)
		len = g_flag.width;
	if (g_flag.minus == 1)
		tmp[0] = (char)value;
	else
		tmp[len - 1] = (char)value;
	ft_putchr(tmp, len);
	ft_free_reset(tmp);
}
