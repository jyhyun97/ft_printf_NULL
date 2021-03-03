// %[flag][width][.precision][type]
#include "ft_printf.h"

void checker(va_list ap, char **a)
{
    init_flag();//check.c  구조체 초기화
    *a = check_flag(*a);//check.c 	=> '-'또는 '0' 확인 
    *a = check_width(*a, ap);//check.c
    *a = check_precision(*a, ap);//check.c
    check_type(*a);//check.c
    print_all(ap);//예외처리, 출력 등 print.c
}

void print_rst(va_list ap, char *format)
{
//int i = 0;//인덱스
// int rst = 0; //반환되어야할 총 문자열 길이 => g_flag로 대체했어요.

while (*format != '\0')
{
    if (*format == '%')
    {  
      format++;
      checker(ap, &format);//서식 지정자인지 확인
    }
    else
    {
      write(1, format, 1);//
      g_flag.count++;
    //   rst++;   // g_flag로 대체했어요
    }
  format++;
}
}

int ft_printf(const char *format, ...)
{
	//int rst;
	char *a = ft_strdup(format); // 복제 필요성 유무 고민 중. 
	g_flag.count = 0;
	va_list ap;
	va_start(ap, format);
	print_rst(ap, a);
	va_end(ap);
	free (a);
	return ((int)g_flag.count);
}
/*
int main(void)
{
	//printf("\n원본 \naaa%-5.*saaa%0-*.*daaa\n", 2, "!@#$", 3, 4, 9999);
	ft_printf("%10c\n",'a');
	ft_printf("%-10c\n",'a');
  ft_printf("1234567890\n");
	return (0);
}
*/