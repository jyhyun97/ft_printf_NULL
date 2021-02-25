#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
// %[flag][width][.precision][type]

typedef struct t_flag
{
  int   minus;
  int   zero;
  int   precision;
  int   star;
  int   width;
	char	type; 
}				s_flag;

s_flag g_flag;

void init_flag()
{
  g_flag->minus = 0;//왼쪽정렬 껐켰
  g_flag->zero = 0;//0 패딩 공백 패딩 껐켰
  g_flag->precision = -1;//정밀도 옵션 껐켰 precision~
  g_flag->star = 0;//너비 가변 인자로 받아오는 거
  g_flag->width = 0;//너비 받아오는 건데 star옵션이랑 중복될 경우는? 어떤 게 우선
  g_flag->type = 0;//csdiupxX%같은 거 담아 놓기
}

void check_flag(char *a)
{
  int i = 0;
  while (a[i] != '\0' && a[i] == '-' && a[i] == '0')
  {
    if (a[i] == '0')
      g_flag->zero = 1;
    if (a[i] == '-')
      g_flag->minus = 1;
  }
}
void check_width(char *a, va_list ap)
{
  //*, 숫자인 동안 while

}
void check_precision()
{
  //.으로 시작해서 *, digit 체크

}
void check_type()
{
  //csduipxX% 체크
}
int print_all();//출력되는 글자 기억해놓기~~~

int checker(va_list ap, char *a)//한 글자씩? 한 서식 지정자 단위씩?
{
    int rst = 0;

    init_flag();//플래그를 초기화시킨다
    check_flag(&a));//플래그 나오는 동안 계속 안에서 돌려!!!! 예외사항도 고려를 해줘!
    check_width(&a, ap);//얜 어차피 하나 밖에 없으니까 괜찮다 다만 플래그에서 * 있을 경우 고려~
    check_precision(&a, ap);//점 나오면 0으로 지정하고 숫자 받기~!!
    check_type(&a, ap);//얘가 안 나온다? 서식 지정자가 아니다 print all만들 때 꼭 참고
    rst += print_all(ap);//서식지정자에 필요한 모든 정보가 모였으니 확인하고 처리 들어가기
    return (rst);
}

int print_rst(va_list ap, char *format)
{
int i = 0;//인덱스
int rst = 0; //반환되어야할 총 문자열 길이

while (*format != '\0')
{
    if (*format == '%')
      rst += checker(ap, &format + 1);//서식 지정자인지 확인
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
