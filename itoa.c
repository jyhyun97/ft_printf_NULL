#include "ft_printf.h"
/*
char *fill_itoa(int n, int digit, char *rst)
{
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
	rst = fill_itoa(n, digit, rst);
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
*/
char *ft_itoa_base(unsigned int n, int base_num, char *base)//base = "0123456789abcdef"
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
        a /= base_num;
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
        rst[digit] = base[a % base_num];
        a /= base_num;
    }
    return (rst);
}

char *ft_itoa_long(long long n, char *base)
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