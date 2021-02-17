#include "ft_printf.h"

extern t_list	g_check;

static int	value_lne(int value, int sign)
{
	int		len;

	len = sign;
	while (1)
	{
		value = value / 10;
		++len;
		if (value == 0)
			break ;
	}
	g_check.size += len;
	return (len);
}

static int	div_input(char c)
{
	int		div;

	div = 10;
	if (c == 'x' || c == 'X')
		div = 16;
	else if (c == 'o')
		div = 8;
	return (div);
}

static char *change_itoa(int value, int len, char c)
{
	char	*tmp;
	char	*letter;
	int		div;

	div = div_input(c);
	tmp = ft_malloc_input(tmp, len);
	if (c == 'X')
		letter = "0123456789ABCDEF";
	else
		letter = "0123456789abcdef";
	while (--len > -1 && value != 0)
	{
		if (value < 0)
		{
			tmp[0] = '-';
			tmp[len] = letter[-(value % div)];
			value = -(value / div);
		}
		else
		{
			tmp[len] = letter[value % div];
			value = (value / div);
		}
	}
	return (tmp);
}

char	*ft_ptr_int(int value, char *ptr, char c)
{
	int		len;
	int		sign;
	char	*tmp;
	char	*cp_ptr;

	sign = 0;
	if (value < 0)
		sign = 1;
	len = value_len(value, sign);
	cp_ptr = ptr;
	ptr = ft_malloc_input(ptr, g_check.size);
	tmp = change_itoa(value, len, c);
	ptr = ft_strlcpy(ptr, cp_ptr, tmp);
}
