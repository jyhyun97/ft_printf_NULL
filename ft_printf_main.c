#include <unistd.h>
#include <stdarg.h>
//bit flag
//struct flag

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

int print_rst(ap)
{

//while (format[i] != '\0')
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
*/
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

