#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct t_flag
{
	char	type; 
}				s_flag;
// %[flag][width][.precision][type]

s_flag g_flag;

void init_flag()
{
  g_flag.type = 0;
}

int print_a(va_list ap, char *a)
{
  int rst = 0;
  if (g_flag.type == 'c')
    rst = printf("%c", va_arg(ap, int));
  else if (g_flag.type == 'd')
    rst = printf("%d", va_arg(ap, int));
  return rst; 
}

int checker(va_list ap, char *a)
{
    char *p = a;//원래 a 위치(서식지정자 판별 실패 시)
    int rst;//지정된 서식지정자로 출력되는 인수의 총 크기(실패 시 0)
    int i;

    a++;
    init_flag();
    while(a[i] != '\0')
    {
        if (a[i] == 'd' || a[i] == 'c') 
        {
            g_flag.type = a[i];//char
            i++;
        }
        if (g_flag.type != 0)
            rst = print_a(ap, a);
        else
            rst = 0;
        return (rst);
    }   
}


int print_rst(va_list ap, const char *format)
{
int i;//인덱스
int rst; //반환되어야할 총 문자열 길이

rst = 0;
i = 0;
while (format[i] != '\0')
{
    if (format[i] == '%')
	  {
      i += checker(ap, format[i]);//서식 지정자인지 확인
      rst++;
	  }
    else
    {
        write(1, &format[i], 1);//
        rst++;
    }
  i++;
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


