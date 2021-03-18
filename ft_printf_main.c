#include "ft_printf.h"

static  void    init_flag(Flag *flag)
{
    flag->minus = 0;
    flag->plus = 0;
    flag->space = 0;
    flag->zero = 0;
    flag->dot = 0;
    flag->width = 0;
    flag->precision = 0;
    flag->value = 0;
    flag->pvalue = 0;
}

static  int set_flag(char **res, char a, int if_con)
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

static  int    set_prev_dot_v(Flag *flag, char **res, va_list *ap)
{
    char    *tmp;
    char    arr[20];
    int     point;
    int     count;

    count = 0;
    ft_memset(arr, 0, 20);
    point = flag->space + flag->zero + flag->plus + flag->minus;
    tmp = *res + point;
    if (*tmp == '*')
    {
        count = va_arg(*ap, int);
        if (count > -1)
            return (count);
        flag->minus = 1;
        return (-count);
    }
    while(*tmp != '.')
    {
        count = count + 1;
        tmp++;
    }
    if (!count)
        return (0);
    ft_memcpy(arr, *res + point, count);
    return (ft_atoi(arr));
}

static  int    set_after_dot_v(char **res, char type, va_list *ap)
{
    char    *tmp;
    char    arr[20];
    int     value;
    int     count;

    value = 0;
    count = 0;
    ft_memset(arr, 0, 20);
    tmp = ft_strchr(*res, '.') + 1;
    if (*tmp == '*')
    {
        count = va_arg(*ap, int);
        return (count);
    }
    while (*tmp++ != type)
        value++;
    if (!value)
        return (0);
    ft_memcpy(arr, ft_strchr(*res, '.') + 1, value);
    return (ft_atoi(arr));
}

static  int    set_no_dot_v(Flag *flag, char **res, char type, va_list *ap)
{
    char    *tmp;
    char    arr[20];
    int     point;
    int     value;
    int     count;

    point = 0;
    value = 0;
    ft_memset(arr, 0, 20);
    point = flag->space + flag->zero + flag->plus + flag->minus;
    tmp = *res + point;
    if (*tmp == '*')
    {
        count = va_arg(*ap, int);
        if (count > -1)
            return (count);
        flag->minus = 1;
        return (-count);
    }
    while(*tmp++ != type)
        value++;
    if (!value)
        return (0);
    ft_memcpy(arr, *res + point, value);
    return (ft_atoi(arr));
}

static  void    set_opt(Flag *flag, va_list *ap, char **res, char type)
{
    init_flag(flag);
    flag->space = set_flag(res, ' ', 0);
    flag->dot = set_flag(res, '.', 0);
    //flag->zero = set_flag(res, '0', flag->dot);
    flag->zero = set_flag(res, '0', 0);
    flag->plus = set_flag(res, '+', flag->space);
    flag->minus = set_flag(res, '-', flag->zero);
    if (flag->dot)
    {
        flag->width = set_prev_dot_v(flag, res, ap);
        flag->precision = set_after_dot_v(res, type, ap);
    }
    else
        flag->width = set_no_dot_v(flag, res, type, ap);
    if (flag->value < 0 || (flag->value >= 0 && flag->plus))
        flag->space = 0;
    if (type == 'c' || type == 'd')
        flag->value = va_arg(*ap, int);
}

static  void print_padding(char *a)
{
    write (1, a, 1);
    g_count++;
}

static  void print_c(va_list *ap, char **res)
{
    Flag    *flag;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, 'c');
    free(*res);
    if (flag->minus)
    {
        write(1, &(flag->value), 1);
        g_count++;
        while (--flag->width > 0)
            print_padding(" ");
    }
    else
    {
        while (--flag->width > 0)
            print_padding(" ");
        write(1, &(flag->value), 1);
        g_count++;
    }
    free(flag);
}

static  void print_s(va_list *ap, char **res)
{
    Flag    *flag;
    char    *pvalue;
    size_t  len;
    int     real_len;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, 's');
    free(*res);
    *res = 0;
    pvalue = va_arg(*ap, char *);
    if (!pvalue)
        pvalue = "(null)";
    len = ft_strlen(pvalue);
    if (flag->dot && flag->precision >= 0 && ((int)len >= flag->precision))
        len = flag->precision;
    real_len = flag->width - (int)len;
    if (flag->minus)
    {
        write(1, pvalue, len);
        g_count += len;
        while (real_len-- > 0)
            print_padding(" ");
    }
    else
    {
        while (real_len-- > 0)
            print_padding(" ");
        write(1, pvalue, len);
        g_count += len;
    }
    free(flag);
}

static  void print_per(va_list *ap, char **res)
{
    Flag    *flag;
    size_t  len;
    int     real_len;
    char    *pad;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, '%');
    free(*res);
    *res = 0;
    if (!flag->zero || (flag->zero && flag->minus))
        pad = " ";
    else
        pad = "0";
    len = 1;
    real_len = flag->width - (int)len;
    if (flag->minus)
    {
        write(1, "%", len);
        g_count += len;
        while (real_len-- > 0)
            print_padding(pad);
    }
    else
    {
        while (real_len-- > 0)
            print_padding(pad);
        write(1, "%", len);
        g_count += len;
    }
    free(flag);
}

static  void print_d(va_list *ap, char **res)
{
    Flag    *flag;
    size_t  len;
    char    *pvalue;
    int     real_len;
    char    *pad;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, 'd');
    free(*res);
    *res = 0;
    if (!flag->zero || (flag->zero && flag->minus))
        pad = " ";
    else
        pad = "0";
    pvalue = ft_itoa(flag->value);
    len = ft_strlen(pvalue);
    real_len = flag->width - (int)len;
    if (flag->minus)
    {
        write(1, pvalue, len);
        g_count += len;
        while (real_len-- > 0)
            print_padding(pad);
    }
    else
    {
        while (real_len-- > 0)
            print_padding(pad);
        write(1, pvalue, len);
        g_count += len;
    }
    free(flag);
}

static  void set_res(va_list *ap, char **res)
{
    if (ft_strchr(*res, 'd'))
        print_d(ap, res);
    else if (ft_strchr(*res, 'c'))
        print_c(ap, res);
    else if (ft_strchr(*res, 's'))
        print_s(ap, res);
    else if (ft_strchr(*res, '%'))
        print_per(ap, res);
}
static  char    *set_dtarg(char *a, int *k)
{
    char    *pt_type;

    while (a[*k] != 'd' && a[*k] != 'c' && a[*k] != 's' && a[*k] != '%')
        (*k)++;
    pt_type = (char *)malloc(((*k) + 2) * sizeof(char));
    if (pt_type)
        ft_memcpy(pt_type, a, (*k) + 1);
    return (pt_type);
}

static  int checker(va_list *ap, const char *a)
{
    char *res;
    int k;

    k = 0;
    res = set_dtarg((char *)a, &k);
    set_res(ap, &res);
    return (k + 1);
}

static  void print_rst(va_list *ap, const char *format)
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
    print_rst(&ap, format);
	va_end(ap);
    return (g_count);
}