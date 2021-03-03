#include "ft_printf.h"

void init_flag(void)
{
  g_flag.minus = 0;//0은 오른쪽 정렬 1은 왼쪽 정렬
  g_flag.zero = 0;//패딩 0일 때 공백, 1일 때 0으로 패딩
  g_flag.precision = -1;//정밀도 있으면 기본 0, 뒤 숫자 width처럼 저장
  g_flag.width = 0;//너비 *으로 받아오기 or atoi 받아오기
  g_flag.type = 0;//csdiupxX% 담아놓기
  //g_flag->star;//굳이 필요 할까?
}

char *check_flag(char *a)
{
  int i = 0;
  while (a[i] != '\0' && (a[i] == '-' || a[i] == '0'))
  {
	printf("a");
    if (a[i] == '0')
      g_flag.zero = 1;
    else if (a[i] == '-')
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
    else if(a[i] >= '0' && a[i] <= '9')
    {
      while (a[i] >= '0' && a[i] <= '9')
      {
        printf("b");
        g_flag.width = (g_flag.width * 10) + (a[i] - '0');
        i++;
      }
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
    g_flag.precision = 0;   //"%*10.*10c", 10, 5, 'c'
    // if (a[i] != '\0' && (a[i] == '*' || (a[i] >= '0' && a[i] <= '9')))
    // {
	if (a[i] == '*')
	{
	g_flag.precision = va_arg(ap, int);
	i++;
	}
	else if (a[i] >= '0' && a[i] <= '9' && a[i] != '\0')
	{
	while (a[i] >= '0' && a[i] <= '9' && a[i] != '\0')
	{
    printf("c");
		g_flag.precision = (g_flag.precision * 10) + (a[i] - '0');
		i++;
	}
	}
    // }
  }
  return (a + i);
}

void check_type(char *a)  // " %-10.*c"
{
  int i = 0;
  if (a[i] == 'c' || a[i] == 's' || a[i] == 'p' || a[i] == 'd' || a[i] == 'i' || a[i] == 'u' || a[i] == 'x' || a[i] == 'X' || a[i] == '%')
    g_flag.type = a[i];
}
