#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
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
*/
void	*ft_memcpy(void *d, void const *s, size_t n)
{
	char			*pd;
	char const		*ps;

	pd = d;
	ps = s;
	if (n == 0)
		return (d);
	if ((ps == NULL) && (pd == NULL))
		return (NULL);
	if ((ps != NULL) || (pd != NULL))
	{
		while (n--)
			*pd++ = *ps++;
	}
	return (d);
}

char    *set_dtarg(va_list ap, const char *a, int *k)
{
    char    *pt_type;

    while (a[*k] != 'd' || a[*k] != 'c' || a[*k] != 'i')
        (*k)++;
    //if (!k)
    //    return (NULL);
    pt_type = (char *)malloc(((*k) + 1) * sizeof(char));
    if (pt_type)
        ft_memcpy(pt_type, a, (*k));
    return (pt_type);
}

int checker(va_list ap, const char *a)
{
    char *res;
    int k;

    k = 0;
    //printf("%d",va_arg(ap, int));
    res = set_dtarg(ap, a, &k);
    return (k + 1);
    //a++;
    //%.....d
    //%이후부터 잘라서 이동해준다... 
	// 02-18 14시
// ---------------------------------------------
    //그 함수에서는 정보들을 조합해서 string을 하나 만들어준다.
   
    //%0.0d 

}

int print_rst(va_list ap, const char *format)
{
    int i;

    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i += checker(ap, &format[i + 1]);//서식 지정자인지 확인
            //i += format();
        }
        else
            write(1, &format[i], 1); //출력;
        i++;
    }

    return (1);

}


int ft_printf(const char *format, ...)
{
    int rst;

    va_list ap;
    va_start(ap, format);
    print_rst(ap, format);
	va_end(ap);
    return (rst);
}

//"asdfsafdasdf%dsadfsafsdfdsfsaf%d"

//va_arg(ap, /*자료형*/);

int main(void)
{
	ft_printf("asdfasdf%dasdf",1);
	return (0);
}

