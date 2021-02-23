#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct t_flag
{
  int   minus;
  int   zero;
  int   dot;
  int   star;
  int   width;
  int   precision;
	char	type; 
}				s_flag;
// %[flag][width][.precision][type]

s_flag g_flag;

void init_flag()
{
  g_flag.minus = 0;
  g_flag.zero = 0;
  g_flag.dot = 0;
  g_flag.star = 0;
  g_flag.width = 0;
  g_flag.precision = 0;
  g_flag.type = 0;
}

void check_flag(char *a)
{
  if (*a == '0')
  {
    g_flag->zero = 1;
    a++;
  }
  if (*a == '.')
  {
    g_flag->dot = 1;
    a++;
  }
  if (*a == '-')
  {
    g_flag->minus = 1;
    a++;
  }
  if (*a == '*')
  {
    g_flag->star = 1;
    a++;
  }
}

void check_width(char *a, va_list ap)
{

}

int checker(va_list ap, char *a)
{
    int rst = 0;

    a++;
    init_flag();
    check_flag(&a));//
    check_width(&a, ap);//
    check_precision(&a, ap);//
    check_type(&a, ap);//
    rst += print_all(ap);
    return (rst);
}

int print_rst(va_list ap, char *format)
{
int i = 0;//인덱스
int rst = 0; //반환되어야할 총 문자열 길이

while (*format != '\0')
{
    if (*format == '%')
	  {
      rst += checker(ap, &format);//서식 지정자인지 확인
	  }
    else
    {
        write(1, *format, 1);//
        rst++;
    }
  format++;
}
return (rst);
}


int ft_printf(const char *format, ...)
{
  int rst;
  va_list ap;
  va_start(ap, format);
  rst = print_rst(ap, format);
	va_end(ap);
  return (rst);
}

int main(void)
{
	ft_printf("aaa%caaa%daaa", 'a', 20);
	return (0);
}
