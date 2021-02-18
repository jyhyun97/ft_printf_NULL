#include "ft_printf.h"

void    

int set_res(va_list ap, char **res)
{
    int count;

    count = 0;
    if (ft_strchr(*res, 'd'))
        
    else if (ft_strchr(*res, 'c'))
    else if (ft_strchr(*res, 'i'))
    return (count);
}
char    *set_dtarg(char *a, int *k)
{
    char    *pt_type;

    while (a[*k] != 'd' && a[*k] != 'c' && a[*k] != 'i')
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
    k += set_res(ap, &res);
    // do something for res... and return res...
    write(1, res, ft_strlen(res));
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
	ft_printf("asdfasdf%dasdf",1);
	return (0);
}