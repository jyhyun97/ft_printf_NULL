#include "ft_printf.h"

static int		ft_abs(long long nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(long long value, int base)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;
	long long		tmp;

	flag = 0;
	size = 0;
	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % (long long)base)];
		size--;
		value /= (long long)base;
	}
	return (str);
}