#include "ft_printf.h"

void print_all(va_list ap)
{
  if (g_flag.width < 0)
  {
    g_flag.minus = 1;
    g_flag.width *= -1;    
  }
  if (g_flag.type == 'c')
    print_c(ap);
  if (g_flag.type == 's')
    print_s(ap);
  if (g_flag.type == 'd' || g_flag.type == 'i')
    print_d(ap);
  if (g_flag.type == 'u')
    print_u(ap);
  if (g_flag.type == 'x' || g_flag.type == 'X')
    print_x(ap);
  if (g_flag.type == 'p')
    print_p(ap);
  if (g_flag.type == '%')
    print_percent();
}

void padding(int byte)
{
  char a;
  int i;

  a = ' ';
  i = 0;
  if (g_flag.zero == 1 && g_flag.type == '%' && g_flag.minus == 0)
    a = '0';
  while (i < g_flag.width - byte && (g_flag.width - byte > 0))
  {
    write(1, &a, 1);
    g_flag.count++;
    i++;
  }
}

void print_c(va_list ap)
{
  char a;

  a = va_arg(ap, int);
  if (g_flag.minus)
  {
	  write(1, &a, 1);
    g_flag.count++;
	  padding(1);
  }
  else
  {
	  padding(1);
	  write(1, &a, 1);
    g_flag.count++;
  }
}

void print_s(va_list ap)
{
	char *str;
  int len;

  str = va_arg(ap, char *);
	if (str == 0)
		str = "(null)";
	len = (int)ft_strlen(str);
	if (len > g_flag.precision && (0 <= g_flag.precision))
		len = g_flag.precision;
	if (g_flag.minus)
	{
		write(1, str, len);
		g_flag.count += len;
		padding(len);
	}
	else
	{
		padding(len);
		write(1, str, len);
		g_flag.count += len;
	}
}

void print_percent(void)
{
  if (g_flag.minus)
	{
		write(1, "%", 1);
		g_flag.count += 1;
		padding(1);
	}
	else
	{
		padding(1);
		write(1, "%", 1);
		g_flag.count += 1;
	}
}
