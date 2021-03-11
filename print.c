#include "ft_printf.h"

void except(void)
{
  if (g_flag.width < 0)
  {
    g_flag.minus = 1;
    g_flag.width *= -1;    
  }
}

void print_all(va_list ap)
{
  except();
  if (g_flag.type == 'c')
    print_c(ap);
  if (g_flag.type == 's')
    print_s(ap);
  if (g_flag.type == 'd' || g_flag.type == 'i')
    print_d(ap);
  if (g_flag.type == 'u')
    print_u(ap);
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

  abs = ft_itoa(ft_abs(a));
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
  int z = g_flag.width - abs_len;
  if (a < 0)
    z -= 1;
  
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i++ < z)
  {
    write(1, "0", 1);
    g_flag.count++;
  }

  if(g_flag.precision != 0 || a != 0)//숫자가 출력 되어야 할 경우
    write(1, abs, abs_len);//12345
  else//숫자가 출력되지 않아야 할 경우(.0d && d == 0 || .d && d == 0)
    abs_len = 0;
  g_flag.count += abs_len;//-000012345
  free(abs);
}

int count_dtype(int a)
{
  char *abs;
  int abs_len;
  int cnt;

  abs = ft_itoa(ft_abs(a));//12345
  abs_len = ft_strlen(abs);//5
  cnt = 0;
  if (a < 0)
    cnt++;//1
  cnt += abs_len;//6
  while (g_flag.precision > abs_len)//9 > 6
  {
    abs_len++;//9
    cnt++;//9
  }
  int i = 0; //-7.9d -12345
  int z = g_flag.width - abs_len;//5
  if (a < 0)//
    z -= 1;//-3
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i < z)//08d 123
  {
    i++;
    cnt++; //00000123
  }
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
    padding(len);//
	}
	else
	{
	padding(len);
	make_dtype(a);
  }
}

int count_utype(unsigned int a)
{
  char *rst;
  int len;
  int cnt;

  rst = ft_itoa_u(a);
  len = ft_strlen(rst);
  cnt = 0;
  cnt += len;
  while (g_flag.precision > len)//9 > 6
  {
    len++;//9
    cnt++;//9
  }
  int i = 0; //-7.9d -12345
  int z = g_flag.width - len;//5
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i < z)//08d 123
  {
    i++;
    cnt++; //00000123
  }
  if(g_flag.precision == 0 && a == 0)
    cnt--;
  free(rst);
  return (cnt);
}
void make_utype(unsigned int a)
{
  char *rst;
  int len;
  int i = 0;

  rst = ft_itoa_u(a);
  len = ft_strlen(rst);
  
  while (g_flag.precision - len > i++)
  {
    write (1, "0", 1);
    g_flag.count++;
  }
  i = 0;
  int z = g_flag.width - len;
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i++ < z)
  {
    write(1, "0", 1);
    g_flag.count++;
  }
  if(g_flag.precision != 0 || a != 0)
    write(1, rst, len);
  else
    len = 0;
  g_flag.count += len;//-000012345
  free(rst);
}

void print_u(va_list ap)
{
  unsigned int a;
  
  a = va_arg(ap, unsigned int);
  int len = count_utype(a);
  if (g_flag.minus)
  {
    make_utype(a);
    padding(len);
  }
  else
  {
    padding(len);
    make_utype(a);    
  }
}
//[precision 0패딩][rst]
//단순히 d플래그에서 음수 부분만 없앴다고 생각해도 될까?