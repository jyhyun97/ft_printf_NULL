#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

char	*ft_hexadecimal(char c)
{
	if (c == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

int		ft_ux_len(unsigned int x, char c)
{
	int		ux_len;
	int		div;

	ux_len = 0;
	div = 10;
	if (c == 'x' || c == 'X')
	div = 16;
	while (1)
	{
		x = x / div;
		++ux_len;
		if (x == 0)
			break ;
	}
	return (ux_len);
}

int		ft_len(int len, unsigned long long p, char c)
{
	int		valuelen;

	valuelen = 0;
	if (len < 0)
		valuelen = 1;
	while (1)
	{
		if (c == 'p')
			p = p / 16 ;
		else
			len = len / 10;
		++valuelen;
		if (c == 'p' && p == 0)
			break ;
		else if (c != 'p' && len == 0)
			break ;
	}
	if (c == 'p')
		valuelen += 2;
	return (valuelen);
}

void	ft_x_frist(char *ptr, char c, int len, int cp_len)
{
	int		i;
	int		j;
	int		value;

	i = -1;
	value = len;
	if (g_flag.minus == 1)
		value = g_flag.precision + g_flag.shap;
	if (g_flag.dot == 1)
		while (--value > -1 && ++i != g_flag.precision + g_flag.shap)
			ptr[value] = '0';
	if (g_flag.shap == 2)
	{
		if (g_flag.zero == 1)
			j = 1;
		else
			j = len - cp_len - 1;
		ptr[j - 1] = '0';
		ptr[j] = 'x';
		if (c == 'X')
			ptr[j] = 'X';
	}
}
