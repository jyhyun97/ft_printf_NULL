#include "ft_printf.h"

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
