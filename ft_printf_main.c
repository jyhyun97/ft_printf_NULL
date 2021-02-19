#include "ft_printf.h"


int set_res(va_list ap, char **res)
{
    int count;

    count = 0;
    if (ft_strchr(*res, 'd'))
    {
        free(*res); //여기서 flag처리해주는 함수.. 구현해야함..실질적으로 각각 파싱기능으로 들어가는 함수 구현하는부분 시작
        *res = ft_itoa(va_arg(ap, int));
        count = ft_strlen(*res);
        write(1, *res, count);
        free(*res);
    }
    else if (ft_strchr(*res, 'c'))
    {
        free(*res);
        **res = va_arg(ap, int);
        count = sizeof(char);
        write(1, *res, 1);
    }
    else if (ft_strchr(*res, 's'))
    {
        free(*res);
        *res = va_arg(ap, char *);
        count = ft_strlen(*res);
        write(1, *res, count);
    }
    return (count);
}
char    *set_dtarg(char *a, int *k)
{
    char    *pt_type;

    while (a[*k] != 'd' && a[*k] != 'c' && a[*k] != 's')
        (*k)++;
    pt_type = (char *)malloc(((*k) + 2) * sizeof(char));
    if (pt_type)
        ft_memcpy(pt_type, a, (*k) + 1);
    return (pt_type);
}

int checker(va_list ap, const char *a)
{
    char *res;
    int k;

    k = 0;
    //printf("%d",va_arg(ap, int));
    res = set_dtarg((char *)a, &k);
    set_res(ap, &res);
    // do something for res... and return res...
    //write(1, res, ft_strlen(res));
    return (k + 1);
}

int print_rst(va_list ap, const char *format)
{
    int i;

    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
            i += checker(ap, &format[i + 1]);
        else
            write(1, &format[i], 1);
        i++;
    }
    return (i);
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

int main(void)
{
	ft_printf("asdfasd%%f %d as %d df %c %s",1818181818,19191919,'%',"mom! i did it!!");
	return (0);
}