#include "ft_printf.h"

void init_flag(void)
{
  g_flag.minus = 0;
  g_flag.zero = 0;
  g_flag.precision = -1;
  g_flag.width = 0;
  g_flag.type = 0;
}
char *check_flag(char *a)
{
  while (*a == '-' || *a == '0')
  {
    if (*a == '0')
      g_flag.zero = 1;
    else if (*a == '-')
      g_flag.minus = 1;
  a++;
  }
  return (a);
}

char *check_width(char *a, va_list ap)
{
  if (*a == '*' || (*a >= '0' && *a <= '9'))
  {
    if (*a == '*')
    {
      g_flag.width = va_arg(ap, int);
      a++;
    }
    else if(*a >= '0' && *a <= '9')
    {
      while (*a >= '0' && *a <= '9')
      {
        g_flag.width = (g_flag.width * 10) + (*a - '0');
        a++;
      }
    }
  }
  return (a);
}

char *check_precision(char *a, va_list ap)
{
  if (*a == '.')
  {
    a++;
    g_flag.precision = 0;
    if (*a == '*')
    {
      g_flag.precision = va_arg(ap, int);
      a++;
    }
    else if (*a >= '0' && *a <= '9')
    {
      while (*a >= '0' && *a <= '9')
      {
        g_flag.precision = (g_flag.precision * 10) + (*a - '0');
        a++;
      }
    }
  }
  return (a);
}

void check_type(char *a)
{
  if (*a == 'c' || *a == 's' || *a == 'p' || *a == 'd' || *a == 'i' || *a == 'u' || *a == 'x' || *a == 'X' || *a == '%')
    g_flag.type = *a;
}