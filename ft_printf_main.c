#include "ft_printf.h"

char    *set_dtarg(va_list ap, char *a, int *k)
{
    char    *pt_type;

    while (a[*k] != 'd' && a[*k] != 'c' && a[*k] != 'i')
        (*k)++;
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
    printf("%d",va_arg(ap, int));
    res = set_dtarg(ap, (char *)a, &k);
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

int main(void)
{
	ft_printf("asdfasdf%dasdf",1);
	return (0);
}