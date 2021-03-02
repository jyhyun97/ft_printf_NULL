// %[flag][width][.precision][type]
#include "ft_printf.h"

int checker(va_list ap, char **a)
{
    int rst = 0;

    init_flag(g_flag);//check.c
    *a = check_flag(*a);//check.c
    *a = check_width(*a, ap);//check.c
    *a = check_precision(*a, ap);//check.c
    check_type(*a);//check.c
    rst += print_all(ap);//예외처리, 출력 등 print.c
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
      format++;
      rst += checker(ap, &format);//서식 지정자인지 확인
    }
    else
    {
      write(1, format, 1);//
      rst++;
    }
  format++;
}
return (rst);
}

int ft_printf(const char *format, ...)
{
  int rst;
  char *a = ft_strdup(format);
  va_list ap;
  va_start(ap, format);
  rst = print_rst(ap, a);
	va_end(ap);
  free (a);
  return (rst);
}

int main(void)
{
	//printf("\n원본 \naaa%-5.*saaa%0-*.*daaa\n", 2, "!@#$", 3, 4, 9999);
	ft_printf("%10c\n",'a');
	ft_printf("%-10c\n",'a');
  ft_printf("1234567890\n");
	return (0);
}