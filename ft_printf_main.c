#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.c"
// %[flag][width][.precision][type]

typedef struct t_flag
{
  int   minus;
  int   zero;
  int   precision;
  int   width;
	char	type; 
  //int   star;
}				s_flag;

s_flag g_flag;

void init_flag()
{
  g_flag.minus = 0;//0은 오른쪽 정렬 1은 왼족 정렬
  g_flag.zero = 0;//0 패딩 0일 떄 공백 1일 때 0으로 패딩
  g_flag.precision = -1;//정밀도 있으면 기본 0, 뒤 숫자 width처럼 저장
  g_flag.width = 0;//너비 *으로 받아오기 or atio 받아오기
  g_flag.type = 0;//csdiupxX% 담아놓기
  //g_flag->star;//굳이 필요 할까?
}

char *check_flag(char *a)
{
  int i = 0;
  while (a[i] != '\0' && (a[i] == '-' || a[i] == '0'))
  {
    if (a[i] == '0')
      g_flag.zero = 1;
    if (a[i] == '-')
      g_flag.minus = 1;
  i++;
  }
  return (a + i);
  //i 반환? 일단은 void 해놨음
}

char *check_width(char *a, va_list ap)
{
  int i = 0;  
  if (a[i] != '\0' && (a[i] == '*' || (a[i] >= '0' && a[i] <= '9')))
  {
    if (a[i] == '*')
    {
      g_flag.width = va_arg(ap, int);
      i++;
    }
    while (a[i] >= '0' && a[i] <= '9' && a[i] != '\0')
    {
      g_flag.width = (g_flag.width * 10) + (a[i] - '0');
      i++;
    }
  }
  return (a + i);
}

char *check_precision(char *a, va_list ap)
{
  int i = 0;
  if (a[i] == '.' && a[i] != '\0')
  {
    i++;
    g_flag.precision = 0;
    if (a[i] != '\0' && (a[i] == '*' || (a[i] >= '0' && a[i] <= '9')))
    {
      if (a[i] == '*')
      {
        g_flag.precision = va_arg(ap, int);
        i++;
      }
      while (a[i] >= '0' && a[i] <= '9' && a[i] != '\0')
      {
        g_flag.precision = (g_flag.precision * 10) + (a[i] - '0');
        i++;
      }
    }
  }
  return (a + i);
}

char *check_type(char *a)
{
  int i = 0;
  if (a[i] == 'c' || a[i] == 's' || a[i] == 'p' || a[i] == 'd' || a[i] == 'i' || a[i] == 'u' || a[i] == 'x' || a[i] == 'X' || a[i] == '%')
    g_flag.type = a[i];
  i++;
  return (a + i);
}
int print_all(va_list ap)
{
  printf("서식지정자 출력 시작\n");
  printf("minus : %d\n", g_flag.minus);
  printf("zero : %d\n", g_flag.zero);
  printf("width : %d\n", g_flag.width);
  printf("prec : %d\n", g_flag.precision);
  printf("type : %c\n", g_flag.type);
  printf("출력 끝\n");
  return (1);
}

int checker(va_list ap, char *a)
{
    int rst = 0;

    init_flag();
    a = check_flag(a);
    a = check_width(a, ap);
    a = check_precision(a, ap);
    a = check_type(a);
    rst += print_all(ap);//예외처리, 출력 등
    return (rst);
}

int print_rst(va_list ap, char *format)
{
int i = 0;//인덱스
int rst = 0; //반환되어야할 총 문자열 길이

while (*format != '\0')
{
    if (*format == '%')
      rst += checker(ap, format + 1);//서식 지정자인지 확인
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
	ft_printf("aaa%-5.*caaa%0-*.*daaa", 2, 3, 4);
	return (0);
}
