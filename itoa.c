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

char		*ft_itoa(int n)
{
	char	*rst;
	int		digit;
  int   a;

  a = n;
	digit = 0;
  if (a == 0)
    digit++;
  while (a != 0)
  {
    a /= 10;
    digit++;
  }
	rst = (char *)malloc(sizeof(char) * digit + 1);
	if (rst == 0)
		return (0);
	if (n == -2147483648)
		ft_strlcpy(rst, "2147483648", 11);
	else
	{
    if (n < 0)
      n *= -1;
  	rst[digit] = '\0';
    while (digit > 0)
    {
      digit--;
      rst[digit] = (n % 10) + '0';
      n /= 10;
    }
  }
	return (rst);
}

char *ft_itoa_u(unsigned int n)
{
  char *rst;
  unsigned int digit;
  unsigned int a;

  a = n;
  digit = 0;
  if (a == 0)
    digit++;
  while (a > 0)
  {
    a /= 10;
    digit++;
  }
  rst = (char *)malloc(digit + 1);
  if (rst == 0)
    return (0);
  a = n;
  rst[digit] = '\0';
  while (digit > 0)
  {
    digit--;
    rst[digit] = (a % 10) + '0';
    a /= 10;
  }
  return (rst);
}

char *ft_itoa_16(unsigned int n, char *base)//base = "0123456789abcdef"
{
    char *rst;
    unsigned int digit;
    unsigned int a;
    
    a = n;
    digit = 0;
    if (a == 0)
        digit++;
    while (a > 0)
    {
        a /= 16;
        digit++;
    }
    rst = (char *)malloc(digit + 1);
    if (rst == 0)
        return (0);
    a = n;
    rst[digit] = '\0';
    while (digit > 0)
    {
        digit--;
        rst[digit] = base[a % 16];
        a /= 16;
    }
    return (rst);
}

char *ft_itoa_x(long long n, char *base)//base = "0123456789abcdef"
{
    char *rst;
    unsigned int digit;
    long long a;
    
    a = n;
    digit = 0;
    if (a == 0)
        digit++;
    while (a > 0)
    {
        a /= 16;
        digit++;
    }
    rst = (char *)malloc(digit + 1);
    if (rst == 0)
        return (0);
    a = n;
    rst[digit] = '\0';
    while (digit > 0)
    {
        digit--;
        rst[digit] = base[a % 16];
        a /= 16;
    }
    return (rst);
}