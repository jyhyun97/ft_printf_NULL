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

void make_dtype(int a)
{
  char *abs;
  int abs_len;
  int i;
  int z;

  abs = ft_itoa_base((unsigned int)ft_abs(a), 10, "0123456789");
  abs_len = ft_strlen(abs);
  i = 0;
  if (a < 0)
  {
    write (1, "-", 1);
    g_flag.count++;
  }
  while (g_flag.precision - abs_len > i++)
  {
    write (1, "0", 1);
    g_flag.count++;
  }
  i = 0;
  z = g_flag.width - abs_len;
  if (a < 0)
    z -= 1;
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i++ < z)
  {
    write(1, "0", 1);
    g_flag.count++;
  }
  if(g_flag.precision != 0 || a != 0)
    write(1, abs, abs_len);
  else
    abs_len = 0;
  g_flag.count += abs_len;
  free(abs);
}

int count_dtype(int a)
{
  char *abs;
  int abs_len;
  int cnt;
  int i;
  int z;

  abs = ft_itoa_base((unsigned int)ft_abs(a), 10, "0123456789");
  abs_len = ft_strlen(abs);
  cnt = abs_len;
  if (a < 0)
    cnt++;
  while (g_flag.precision > abs_len++)
    cnt++;
  i = 0;
  z = g_flag.width - abs_len;
  if (a < 0)
    z -= 1;
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i++ < z)
    cnt++;
  if(g_flag.precision == 0 && a == 0)
    cnt--;
  free(abs);
  return (cnt);
}

void print_d(va_list ap)
{
  int a;
  int len;
  
  a = va_arg(ap, int);
  len = count_dtype(a);
  if (g_flag.minus)
	{
	  make_dtype(a);
    padding(len);
	}
	else
	{
	padding(len);
	make_dtype(a);
  }
}
/*
int count_utype(unsigned int a, char *base)
{
  char *rst;
  int len;
  int cnt;
  int i;
  int z;

  rst = ft_itoa_base(a, 10, base);
  len = ft_strlen(rst);
  //cnt = 0;
  cnt = len;
  while (g_flag.precision > len++)
    cnt++;
  i = 0;
  z = g_flag.width - len;
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i++ < z)
    cnt++;
  if(g_flag.precision == 0 && a == 0)
    cnt--;
  free(rst);
  return (cnt);
}

void make_utype(unsigned int a, char *base)
{
  char *rst;
  int len;
  int i;
  int z;

  rst = ft_itoa_base(a, 10, base);
  len = ft_strlen(rst);
  i = 0;
  while (g_flag.precision - len > i++)
  {
    write (1, "0", 1);
    g_flag.count++;
  }
  i = 0;
  z = g_flag.width - len;
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i++ < z)
  {
    write(1, "0", 1);
    g_flag.count++;
  }
  if(g_flag.precision != 0 || a != 0)
    write(1, rst, len);
  else
    len = 0;
  g_flag.count += len;
  free(rst);
}
*/

void print_u(va_list ap)
{
  unsigned int a;
  char *base;
  
  a = va_arg(ap, unsigned int);
  base = "0123456789";
  int len = count_uxtype(a, 10, base);
  if (g_flag.minus)
  {
    make_uxtype(a, 10, base);
    padding(len);
  }
  else
  {
    padding(len);
    make_uxtype(a, 10, base);
  }
}

int count_uxtype(unsigned int a, int base_num, char *base)
{
  char *rst;
  int len;
  int cnt;
  int i;
  int z;

  rst = ft_itoa_base(a, base_num, base);
  len = ft_strlen(rst);
  cnt = len;
  while (g_flag.precision > len++)
    cnt++;
  i = 0;
  z = g_flag.width - len;
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i++ < z)
    cnt++;
  if(g_flag.precision == 0 && a == 0)
    cnt--;
  free(rst);
  return (cnt);
}

void make_uxtype(unsigned int a, int base_num, char *base)
{
  char *rst;
  int len;
  int i;
  int z;

  rst = ft_itoa_base(a, base_num, base);
  len = ft_strlen(rst);
  i = 0;
  while (g_flag.precision - len > i++)
  {
    write (1, "0", 1);
    g_flag.count++;
  }
  i = 0;
  z = g_flag.width - len;
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i++ < z)
  {
    write(1, "0", 1);
    g_flag.count++;
  }
  if(g_flag.precision != 0 || a != 0)
    write(1, rst, len);
  else
    len = 0;
  g_flag.count += len;
  free(rst);
}

void print_x(va_list ap)
{
  unsigned int a;
  char *base;
  
  a = va_arg(ap, unsigned int);
  if (g_flag.type == 'X')
    base = "0123456789ABCDEF";
  else
    base = "0123456789abcdef";
  int len = count_uxtype(a, 16, base);
  
  if (g_flag.minus)
  {
    make_uxtype(a, 16, base);
    padding(len);
  }
  else
  {
    padding(len);
    make_uxtype(a, 16, base);    
  }
}


int count_ptype(long long a, char *base)
{
  char *rst;
  int len;
  int cnt;

  rst = ft_itoa_long(a, base);
  len = ft_strlen(rst);
  cnt = 2;
  cnt += len;
  if(g_flag.precision == 0 && a == 0)
    cnt--;
  free(rst);
  return (cnt);
}

void make_ptype(long long a, char *base)
{
  char *rst;
  int len;

  rst = ft_itoa_long(a, base);
  len = ft_strlen(rst);
  
  write(1, "0x", 2);
  g_flag.count += 2;
  if(g_flag.precision != 0 || a != 0)
    write(1, rst, len);
  else
    len = 0;
  g_flag.count += len;
  free(rst);
}


void print_p(va_list ap)
{
  long long a;
  char *base;
  
  a = (long long)va_arg(ap, void *);
  base = "0123456789abcdef";
  int len = count_ptype(a, base);
  
  if (g_flag.minus)
  {
    make_ptype(a, base);
    padding(len);
  }
  else
  {
    padding(len);
    make_ptype(a, base);    
  }
}