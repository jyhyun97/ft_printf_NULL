#include "ft_printf.h"

typedef struct _flag {
    int minus;
    int plus;
    int space;
    int zero;
    int dot;
    int aster;
    int prev_dot_v;
    int after_dot_v;
    int no_dot_v;
    int value;
} Flag;

void    init_flag_d(Flag *flag)
{
    flag->minus = 0;
    flag->plus = 0;
    flag->space = 0;
    flag->zero = 0;
    flag->dot = 0;
    flag->aster = 0;
    flag->prev_dot_v = 0;
    flag->after_dot_v = 0;
    flag->no_dot_v = 0;
    flag->value = 0;
}

int set_d_flag(char **res, char a, int if_con)
{
    if (ft_strchr(*res, a) && !if_con)
        return (1);
    return (0);
}

int    set_prev_dot_v(Flag *flag, char **res)
{
    char    *tmp;
    char    arr[1000];
    int     point;
    int     value;

    ft_memset(arr, 0, 1000);
    point = flag->space + flag->zero + flag->plus + flag->minus;
    //flag가 중복일때는 오류가날것... 수정해야함.. 
    tmp = *res + point;
    while(*tmp++ == '.')
        value++;
    ft_memcpy(arr, *res + point, value);
    if (!value)
        return (0);
    return (ft_atoi(arr));
}

int    set_after_dot_v(Flag *flag, char **res)
{
    char    *tmp;
    char    arr[1000];
    int     value;

    ft_memset(arr, 0, 1000);
    tmp = ft_strchr(*res, '.') + 1;
    while (*tmp == 'd')
        value++;
    ft_memcpy(arr, tmp, value);
    if (!value)
        return (0);
    return (ft_atoi(arr));
}

Flag    set_d_opt(va_list ap, char **res)
{
    Flag    flag;

    init_flag(&flag);
    flag.value = va_arg(ap, int);
    flag.space = set_d_flag(**res, ' ', 0);
    flag.dot = set_d_flag(**res, '.', 0);
    flag.zero = set_d_flag(**res, '0', flag.dot);
    flag.plus = set_d_flag(**res, '+', flag.space);
    flag.minus = set_d_flag(**res, '-', flag.zero);
    if (flag.dot)
    {
        flag.prev_dot_v = set_prev_dot_v(&flag, **res);
        flag.after_dot_v = set_after_dot_v(&flag, **res);
    }
    else
        flag.no_dot_v = 0;//do atoi...
    if (flag.value < 0 || (flag.value >= 0 && flag.plus))
        flag.space = 0;
    return (flag);
}

void    set_d(va_list ap, char **res, int *count)
{
    Flag    flag;

    flag = set_d_opt(ap, **res);
    free(*res); //여기서 flag처리해주는 함수.. 구현해야함..실질적으로 각각 파싱기능으로 들어가는 함수 구현하는부분 시작
    *res = ft_itoa(va_arg(ap, int));
    *count = ft_strlen(*res);
    write(1, *res, *count);
    free(*res);
}

int set_res(va_list ap, char **res)
{
    int count;

    count = 0;
    if (ft_strchr(*res, 'd'))
        set_d(ap, **res, &count);
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
    res = set_dtarg((char *)a, &k);
    set_res(ap, &res);
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
	ft_printf("asdfasd%%f %d as %d%c%s",1818181818,19191919,'%',"mom! i did it!!");
	return (0);
}