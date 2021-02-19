#include "ft_printf_main.h"

t_flag  g_flag;
t_size  g_size;

int     error_checker(int i)
{
    // +, ' ' 안됨 -1
    if (g_flag.plus == 1 && g_flag.space == 1)
        return (-1);
    // -, '0' 안된 -1
    else if(g_flag.minus == 1 && g_flag.zero == 1)
        return (-1);
    return (i);
}

int     flag_checker(const char *format, va_list ap)
{
    int     i;

    i = 0;
    // flag check 플래그를 겹쳐서 사용 가능
    while (format[i] != 0)
    {
        // + : +, - 부호 붙이기
        if (format[i] == '+')
            g_flag.plus = 1;
        // 왼쪽 정렬 ' '' '123을 -> 123' '' ' 이렇게 정렬
        else if (format[i] == '-')
            g_flag.minus = 1;
        // ' '는 +는 공백 - 는 -출력
        else if (format[i] == ' ')
            g_flag.space = 1;
        // "-"랑 같이 사용 안됨
        else if (format[i] == '0')
            g_flag.zero = 1;
        // o, x, X = 0, 0x, 0X,가 붙음
        else if (format[i] == '#')
            g_flag.shap = 1;
        else
            break ;
        i++;
    }
    // 잘못된 플래그 끼리 연결 되어 있을 경우 함수로 만들어서 진행??
    error_checker(i);
    // i += checker2(&format[i]);
    i += format_checker(&format[i], ap);
    return (i);
}

int     printf_rst(va_list ap, const char *format)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            ++i;
            flag_size_reset();
            i += flag_checker(&format[i], ap);
        }
        else
            ft_putchr((char *)&format[i], 1);
        i++;
    }
    return (g_size.all_size);
}

int     ft_printf(const char *format, ...)
{
    int     rst;

    rst = 0;
    va_list ap;
    va_start(ap, format);
    g_size.all_size = 0;
    rst = printf_rst(ap, format);
	va_end(ap);
    return (rst);
}

int main ()
{
    int rst;

	rst = ft_printf("11%c1 222%s %0+d 333\n", 'S', "test string", -112);
    printf("%d\n", rst);
	return (0);
}
