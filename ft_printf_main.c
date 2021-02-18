#include <unistd.h>
#include <stdarg.h>

typedef struct t_flag
{
	int		plus;  // +, - 
	int		minus; //
    int     zero; // " ", 0
    int     shap;
	int		space; 
}				s_flag;
// %[flag][width][.precision][type]

s_flag g_flag;

char *set_flag(char *a, int *k)
{
    char *res;

    while (a[*k] != 'd' || a[*k])
    {
        (*k)++;
    }
    res = (char *)malloc(*k + 2)
    ft_memcpy(res, a, *k);

    return (res);
}

int checker1(char *a)
{
    char *p = a;//원래 a 위치(서식지정자 판별 실패 시)
    int rst;//지정된 서식지정자로 출력되는 인수의 총 크기(실패 시 0)
    int i;

    a++;
    while(a[i] != '\0')
    {
        if a[i] == 플래그(-0.*)
        {
            g_struct.flag = a[i];//char
            i++;
        }
        if (a[i] == 폭)
        {
            g_struct.width = a[i];
            i++;
        }

        //a[i] 정밀도
        //a[i] 길이
        ...
        //if a[i] == 서식지정자
        {
            g_struct.type = a[i];
            i++;
        }
        if (g_struct.type == true)
            rst = 함수;
        else
            rst = 0;
        return (rst);
    }
    
}

int checker(char *a)
{
    int i;

    i = 0;
    while (a[i] != 0)
    {
        if (a[i] == '+')
            g_flag.plus = 1;
        else if (a[i] == '-')
            g_flag.plus = 1;
        else if (a[i] == '0')
            g_flag.plus = 1;
        else if (a[i] == ' ')
            g_flag.plus = 1;
        else if (a[i] == '#')
            g_flag.plus = 1;
        else
            break ;
        i++;
    } 
    checker1(&a[i]);
    // char *res;
    // int count; 
    a++;
	// 02-18 14시
    // d가 나올때까지 순회하는 기능이 필요
    // res = set_flag(a, &count);
    char *type_str = "uidcxX"
    char *found;

    while (a[i])
    {
        if (found = ft_strchr(type_str, a[i])
        //parse  &a[i], found[0], i)
        i++;
    }

void parse (*str, type, len)
{
    if type == c
        set flag ,w,, write
    else if type == d
        set flag ,w , write;
}


    return (count);
    
}

// ---------------------------------------------
    //그 함수에서는 정보들을 조합해서 string을 하나 만들어준다.
   
    //%0.0d 
  //  cspdiuxX%
}

int  format()
{
    //c, d 종류별 출력...
    //c, d 까지 지나간 숫자 리턴 

	return (1);
}

int print_rst(va_list ap, char *foramt)
{
// ft_printf("abc%4d", 1);  -> abc   1        rst = 7
// i는 abc%4d
// ft_printf의 값이 : 7 = rst 
int i;
int rst;

rst = 0;
i = 0;
while (format[i] != '\0')
{
    if (format[i] == '%')
	{

        i += checker(&format[i]);//서식 지정자인지 확인
		i += format();
	}
    else
        write(1, &format[i], 1); 출력;
    i++;
}

}


int ft_printf(const char *format, ...)
{
    int rst;
    va_list ap;
    va_start(ap, format);
    //rst = 1111();
	va_end(ap);
    return (rst);
}

//"asdfsafdasdf%dsadfsafsdfdsfsaf%d"

va_arg(ap, /*자료형*/);

int main(void)
{
	ft_printf("asdfsafdasdf%dsadfsafsdfdsfsaf%d", 10, 20);
	return (0);
}


