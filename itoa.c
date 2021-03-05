#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[i] != '\0')
		i++;
	while (src[j] != '\0' && j < dstsize - 1 && dstsize != 0)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize > 0)
		dst[j] = '\0';
	return (i);
}
int	cnt_digit(int n)
{
	int	digit;

	digit = 0;
	if (n <= 0)
	{
		n *= -1;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*fill_rst(char *rst, int n)
{
	int	i;
	int	digit;

	i = 0;
	digit = cnt_digit(n);
	if (n == 0)
		rst[i] = '0';
	else if (n < 0)
	{
		rst[i] = '-';
		n *= -1;
	}
	i++;
	while (n > 0)
	{
		rst[digit - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	rst[digit] = '\0';
	return (rst);
}

char		*ft_itoa(int n)
{
	char	*rst;
	int		digit;

	digit = cnt_digit(n);
	if (digit == 0)
		return (0);
	rst = (char *)malloc(sizeof(char) * digit + 1);
	if (rst == 0)
		return (0);
	if (n == -2147483648)
		ft_strlcpy(rst, "-2147483648", 12);
	else
		fill_rst(rst, n);
	return (rst);
}
