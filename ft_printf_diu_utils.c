#include "ft_printf.h"

extern t_size	g_size;
extern t_flag	g_flag;

static char	sign_checker(int di)
{
	if (di < 0)
		return ('-');
	else if (di > 0)
		return ('+');
	return (' ');
}

static char	ptr_di_input(int di)
{
	char	*hex;

	hex = ft_hexadecimal('d');

	if (di < 0)
		return (hex[-(di % 10)]);
	return (hex[di % 10]);
}

static void	sign_input(char *ptr, int len, char sign)
{
	if ((ptr[0] != '+' && ptr[0] != '-') && g_flag.plus == 1)
		ptr[len] = sign;
	if ((ptr[0] != '+' && ptr[0] != '-') && sign == '-')
		ptr[len] = sign;
}

char		*pf_di_input(char *ptr, int di, int len, int cp_len)
{
	char	sign;

	sign = sign_checker(di);
	while (1)
	{
		if (g_flag.minus == 0)
			ptr[--len] = ptr_di_input(di);
		else
			ptr[--cp_len] = ptr_di_input(di);
		di = di / 10;
		if (di == 0)
			break ;
	}
	sign_input(ptr, --len, sign);
	return (ptr);
}

