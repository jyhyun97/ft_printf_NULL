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
  if (g_flag.type == 'd')
    print_d(ap);
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
  //011.10d 
  while (g_flag.precision - abs_len > i++)//4 - 3 
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
    write(1, abs, abs_len);
  else//숫자가 출력되지 않아야 할 경우(.0d && d == 0 || .d && d == 0)
    abs_len = 0;
  g_flag.count += abs_len;
  free(abs);
}

int count_dtype(int a)
{
  char *abs;
  int abs_len;
  int cnt;

  abs = ft_itoa(ft_abs(a));
  abs_len = ft_strlen(abs);
  cnt = 0;
  if (a < 0)
  {
    cnt++;
  }
  cnt += abs_len;
  while (g_flag.precision > abs_len)
  {
    abs_len++;
    cnt++;
  }
  int i = 0;
  int z = g_flag.width - abs_len;
  if (a < 0)
    z -= 1;
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i < z)
  {
    i++;
    cnt++;
  }
  if(g_flag.precision == 0 && a == 0)// 
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


//
//strjoin, strdup, itoa(절대값만 나오게 개조)
//char *s = [-][정밀도][절대값] 새로운 문자열 만들기
//[-] : va_arg가 음수면 -, 양수면 X
//[정밀도] : precision이 절대값 len보다 크면 그 차이만큼 0으로 채우기
//[절대값] : va_arg 절대값(양수) (0도 포함)
//char *s만든 후, 나머지는 print_s 동작 그대로 카피(정밀도가 0인 경우라면 아예 출력이 안됨)



// https://github.com/charMstr/printf_lover_v2
