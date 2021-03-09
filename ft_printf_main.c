#include "ft_printf.h"

void    init_flag(Flag *flag)
{
    flag->minus = 0;
    flag->plus = 0;
    flag->space = 0;
    flag->zero = 0;
    flag->dot = 0;
    flag->aster = 0;
    flag->width = 0;
    flag->precision = 0;
    flag->value = 0;
}

int set_flag(char **res, char a, int if_con)
{
    int count;
    char *tmp;

    count = 0;
    tmp = *res;
    if (ft_strchr(*res, a) && !if_con)
    {
        if (a == '.')
            return (1);
        while (*tmp == '+' || *tmp == '-' || *tmp == '0' || *tmp == ' ')
        {
            if (*tmp == a)
                count++;
            tmp++;
        }
    }
    return (count);
}

int    set_prev_dot_v(Flag *flag, char **res)
{
    char    *tmp;
    char    arr[20];
    int     point;
    int     value;

    value = 0;
    ft_memset(arr, 0, 20);
    point = flag->space + flag->zero + flag->plus + flag->minus;
    tmp = *res + point;
    while(*tmp++ == '.')
        value++;
    ft_memcpy(arr, *res + point, value);
    if (!value)
        return (0);
    return (ft_atoi(arr));
}

int    set_after_dot_v(Flag *flag, char **res, char type)
{
    char    *tmp;
    char    arr[20];
    int     value;

    flag->aster = flag->aster;//컴파일에러방지..
    value = 0;
    ft_memset(arr, 0, 20);
    tmp = ft_strchr(*res, '.') + 1;
    while (*tmp == type)
        value++;
    ft_memcpy(arr, tmp, value);
    if (!value)
        return (0);
    return (ft_atoi(arr));
}

int    set_no_dot_v(Flag *flag, char **res, char type)
{
    char    *tmp;
    char    arr[20];
    int     point;
    int     value;

    point = 0;
    value = 0;
    ft_memset(arr, 0, 20);
    point = flag->space + flag->zero + flag->plus + flag->minus;
    tmp = *res + point;
    while(*tmp++ != type)
        value++;
    ft_memcpy(arr, *res + point, value);
    if (!value)
        return (0);
    return (ft_atoi(arr));
}

Flag    set_opt(va_list ap, char **res, char type)
{
    Flag    flag;

    init_flag(&flag);
    flag.value = va_arg(ap, int);
    flag.space = set_flag(res, ' ', 0);
    flag.dot = set_flag(res, '.', 0);
    flag.zero = set_flag(res, '0', flag.dot);
    flag.plus = set_flag(res, '+', flag.space);
    flag.minus = set_flag(res, '-', flag.zero);
    if (flag.dot)
    {
        flag.width = set_prev_dot_v(&flag, res);
        flag.precision = set_after_dot_v(&flag, res, type);
    }
    else
        flag.width = set_no_dot_v(&flag, res, type);
    if (flag.value < 0 || (flag.value >= 0 && flag.plus))
        flag.space = 0;
    return (flag);
}

void    set_d(va_list ap, char **res, int *count)
{
    Flag    flag;

    flag = set_opt(ap, res, 'd');
    free(*res); //여기서 flag처리해주는 함수.. 구현해야함..실질적으로 각각 파싱기능으로 들어가는 함수 구현하는부분 시작
    *res = ft_itoa(va_arg(ap, int));
    *count = ft_strlen(*res);
    write(1, *res, *count);
    free(*res);
}

void print_c(va_list ap, char **res)
{
    Flag    flag;

    flag = set_opt(ap, res, 'c');
    free(*res);
    if (flag.minus)
    {
        write(1, &(flag.value), 1);
        g_count++;
        while (--flag.width)
        {
            write(1, " ", 1);
            g_count++;
        }
    }
    else
    {
        while (--flag.width)
        {
            write(1, " ", 1);
            g_count++;
        }
        write(1, &(flag.value), 1);
        g_count++;
    }
}

int set_res(va_list ap, char **res)
{
    int     count;
    //char    type;

    count = 0;
    if (ft_strchr(*res, 'd'))
        set_d(ap, res, &count);
    else if (ft_strchr(*res, 'c'))
        print_c(ap, res);
    else if (ft_strchr(*res, 's'))
        print_c(ap, res);
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
    res = set_dtarg((char *)a, &k);
    set_res(ap, &res);
    return (k + 1);
}

void print_rst(va_list ap, const char *format)
{
    int i;

    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
            i += checker(ap, &format[i + 1]);
        else
        {
            write(1, &format[i], 1);
            g_count++;
        }
        i++;
    }
}

int ft_printf(const char *format, ...)
{
    g_count = 0;
    va_list ap;
    va_start(ap, format);
    print_rst(ap, format);
	va_end(ap);
    return (g_count);
}