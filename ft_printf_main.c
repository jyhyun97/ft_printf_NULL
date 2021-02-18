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

int     checker(const char *format)
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
    return (i);
}

/*
        // width
        if (format[i] >= '1' && format[i] <= '9')

        // 정밀도 소수점 자리
        if (format[i] == '.')

        else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u' ||
                    format[i] == 'o' || format[i] == 'x' || format[i] == 'X' ||
                    format[i] == 'f' || format[i] == 'F' || format[i] == 'e' ||
                    format[i] == 'E' || format[i] == 'g' || format[i] == 'G' ||
                    format[i] == 'a' || format[i] == 'A' || format[i] == 'c' ||
                    format[i] == 's' || format[i] == 'p' || format[i] == 'n' ||
                    format[i] == '%' )
            return (i);
*/

void    flag_size_reset(void)
{
    // flag 초기화
    g_flag.minus = 0;
    g_flag.plus = 0;
    g_flag.shap = 0;
    g_flag.space = 0;
    g_flag.zero = 0;
    // 폭, 정밀도, 길이 초기화
    g_size.width = 0;
    g_size.precision = 0;
    g_size.length = 0;
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
            j = checker(&format[i]);
            if(j == -1)
                return (j);
            i += j;
        }
        else
            write(1, &format[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int     ft_printf(const char *format, ...)
{
    int     rst;

    va_list ap;
    va_start(ap, format);
    rst = printf_rst(ap, format);
    printf("minus : %d\n", g_flag.minus);
    printf("plus : %d\n", g_flag.plus);
    printf("shap : %d\n", g_flag.shap);
    printf("space : %d\n", g_flag.space);
    printf("zero : %d\n", g_flag.zero);
	va_end(ap);
    return (rst);
}

int main ()
{
	//int a = 3;
	//float b = 3.0;

	ft_printf("111 222 %0+d 333\n", -112);
	//printf("%f\n",3);
	//printf("%f\n",a);
	//printf("%d\n",b);
	return (0);
}


/*
typedef struct t_list
{
	int		flag;  // +, -
	int		space_zero; // " ", 0
	int		width; // .0000 소수점
	int		length; //
}				s_list

int checker(char *a)
{
    a++;
    //%.....d
    //%이후부터 잘라서 이동해준다...
	// 02-18 14시
// ---------------------------------------------
    //그 함수에서는 정보들을 조합해서 string을 하나 만들어준다.

    //%0.0d
    cspdiuxX%
}

int  format()
{
    //c, d 종류별 출력...
    //c, d 까지 지나간 숫자 리턴

	return (1);
}
*/
