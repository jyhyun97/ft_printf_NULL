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
    flag->v_len = 0;
    flag->p_len = 0;
    flag->sign = 0;
    //flag->pvalue = 0;
}
// static void ft_free(void *ptr)
// {
//     free(ptr);
//     ptr = 0;
// }
static  int set_flag(char *res, char a, int if_con)
{
    int count;
    char *tmp;

    count = 0;
    tmp = res;
    if (ft_strchr(tmp, a) && !if_con)
    {
        if (a == '.')
            return (1);
        while ((*tmp == '+' || *tmp == '-' || *tmp == '0' || *tmp == ' ') && *tmp != '\0')
        {
            if (*tmp == a)
                count++;
            tmp++;
        }
    }
    return (count);
}

static  int    set_prev_dot_v(Flag *flag, char *res, va_list *ap)
{
    char    *tmp;
    char    arr[20];
    int     point;
    int     count;

    count = 0;
    ft_memset(arr, 0, sizeof(arr));
    point = flag->space + flag->zero + flag->plus + flag->minus;
    tmp = res + point;
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
    ft_memcpy(arr, res + point, count);
    return (ft_atoi(arr));
}

static  int    set_after_dot_v(char *res, char type, va_list *ap)
{
    char    *tmp;
    char    arr[20];
    int     value;
    int     count;

    value = 0;
    count = 0;
    ft_memset(arr, 0, sizeof(arr));
    tmp = ft_strchr(res, '.') + 1;
    if (*tmp == '*')
    {
        count = va_arg(*ap, int);
        return (count);
    }
    while (*tmp++ != type)
        value++;
    if (!value)
        return (0);
    ft_memcpy(arr, ft_strchr(res, '.') + 1, value);
    return (ft_atoi(arr));
}

static  int    set_no_dot_v(Flag *flag, char *res, char type, va_list *ap)
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
    tmp = res + point;
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
    ft_memcpy(arr, res + point, value);
    return (ft_atoi(arr));
}

static  void    set_opt(Flag *flag, va_list *ap, char *res, char type)
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
    if (type == 'c' || type == 'd' || type == 'i')
        flag->value = va_arg(*ap, int);
    else if (type == 'u')
        flag->value = va_arg(*ap, unsigned int);
    else if (type == 'x')
        flag->value = va_arg(*ap, long long);
}

static  void put_str(char *a)
{
    int n;

    n = ft_strlen(a);
    write (1, a, n);
    g_count += n;
}

static  void print_c(va_list *ap, char *res)
{
    Flag    *flag;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, 'c');
    if (flag->minus)
    {
        write(1, &(flag->value), 1);
        g_count++;
        while (--flag->width > 0)
            put_str(" ");
    }
    else
    {
        while (--flag->width > 0)
            put_str(" ");
        write(1, &(flag->value), 1);
        g_count++;
    }
    free(flag);
}

static  void print_s(va_list *ap, char *res)
{
    Flag    *flag;
    //char    *pvalue;
    size_t  len;
    int     real_len;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, 's');
    flag->pvalue = va_arg(*ap, char *);
    if (!flag->pvalue)
        flag->pvalue = "(null)";
    len = ft_strlen(flag->pvalue);
    if (flag->dot && flag->precision >= 0 && ((int)len >= flag->precision))
        len = flag->precision;
    real_len = flag->width - (int)len;
    if (flag->minus)
    {
        write(1, flag->pvalue, len);
        g_count += len;
        while (real_len-- > 0)
            put_str(" ");
    }
    else
    {
        while (real_len-- > 0)
            put_str(" ");
        write(1, flag->pvalue, len);
        g_count += len;
    }
    free(flag);
}

static  void print_per(va_list *ap, char *res)
{
    Flag    *flag;
    size_t  len;
    int     real_len;
    char    *pad;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, '%');
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
            put_str(pad);
    }
    else
    {
        while (real_len-- > 0)
            put_str(pad);
        write(1, "%", len);
        g_count += len;
    }
    free(flag);
}

static void print_value(Flag *flag)
{
    int p_len;

    p_len = flag->p_len;
    while (--p_len >= 0)
        put_str("0");
    write(1, flag->pvalue, flag->v_len);
    g_count += flag->v_len;
}

static void print_width(Flag *flag)
{
    char    *pad;
    int     real_len;
    int     sign;

    sign = 0;
    if (flag->value < 0)
        sign = 1;
    if (flag->zero && !flag->dot && !flag->minus)
        pad = "0";
    else
        pad = " ";
    if (flag->p_len >= 0)
        real_len = flag->width - (flag->v_len + flag->p_len) - sign;
    else
        real_len = flag->width - flag->v_len - sign;
    while (--real_len >= 0)
        put_str(pad);
}

void    print_d_sign(Flag *flag)
{
    if (flag->value <0)
        put_str("-");
}

void    print_in_order(Flag *flag, void (*a)(Flag *),void (*b)(Flag *), void (*c)(Flag *))
{
    a(flag);
    b(flag);
    c(flag);
}

static void    set_d_flag(Flag *flag)
{
    flag->sign = 1;
    if (flag->value < 0)
        flag->sign = -1;
    flag->pvalue = ft_itoa(flag->sign * flag->value);
    if (*(flag->pvalue) == '0' && flag->precision == 0 && flag->dot)
        flag->v_len = 0;
    else
        flag->v_len = ft_strlen(flag->pvalue);
    flag->p_len = flag->precision - flag->v_len;
    if (flag->precision < 0)
        flag->dot = 0;
}

static void     print_d(va_list *ap, char *res)
{
    Flag    *flag;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, 'd');
    set_d_flag(flag);
    if (flag->minus)
        print_in_order(flag, print_d_sign, print_value, print_width);
    else
    {
        if (flag->dot)
            print_in_order(flag, print_width, print_d_sign, print_value);
        else
        {
            if (flag->zero)
                print_in_order(flag, print_d_sign, print_width, print_value);
            else
                print_in_order(flag, print_width, print_d_sign, print_value);
        }
    }
    // ft_free(flag->pvalue);
    // ft_free(flag);
    free(flag->pvalue);
    flag->pvalue = 0;
    free(flag);
    flag = 0;
    
}

static  void print_p(va_list *ap, char *res)
{
    Flag    *flag;
    size_t  len;
    int     real_len;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, 'p');
    flag->pvalue = ft_itoa_base(va_arg(*ap, long long), 16, 0);
    len = ft_strlen(flag->pvalue);
    if (*(flag->pvalue) == '0' && flag->dot)
        len = 0;
    real_len = flag->width - ((int)len + 2);
    if (flag->minus)
    {
        put_str("0x");
        write(1, flag->pvalue, len);
        g_count += len;
        while (real_len-- > 0)
            put_str(" ");
    }
    else
    {
        while (real_len-- > 0)
            put_str(" ");
        put_str("0x");
        write(1, flag->pvalue, len);
        g_count += len;
    }
    free(flag->pvalue);
    free(flag);
}

static void     print_u(va_list *ap, char *res)
{
    Flag    *flag;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, 'u');
    set_d_flag(flag);
    if (flag->value < 0)
        put_str(ft_itoa(4294967295 + flag->value + 1));
    else
    {
        if (flag->minus)
            print_in_order(flag, print_d_sign, print_value, print_width);
        else
        {
            if (flag->dot)
                print_in_order(flag, print_width, print_d_sign, print_value);
            else
            {
                if (flag->zero)
                    print_in_order(flag, print_d_sign, print_width, print_value);
                else
                    print_in_order(flag, print_width, print_d_sign, print_value);
            }
        }
    }
    free(flag->pvalue);
    free(flag);
}

static void    set_x_flag(Flag *flag)
{
    flag->sign = 1;
    if (flag->value < 0)
        flag->sign = -1;
    flag->pvalue = ft_itoa_base(flag->sign * flag->value, 16, 0);
    if (*(flag->pvalue) == '0' && flag->precision == 0 && flag->dot)
        flag->v_len = 0;
    else
        flag->v_len = ft_strlen(flag->pvalue);
    flag->p_len = flag->precision - flag->v_len;
    if (flag->precision < 0)
        flag->dot = 0;
}

static void     print_x(va_list *ap, char *res)
{
    Flag    *flag;

    flag = (Flag *)malloc(sizeof(Flag));
    set_opt(flag, ap, res, 'x');
    set_x_flag(flag);
    if (flag->value < 0)
        put_str(ft_itoa_base(4294967295 + flag->value + 1, 16, 0));
    else
    {
        if (flag->minus)
            print_in_order(flag, print_d_sign, print_value, print_width);
        else
        {
            if (flag->dot)
                print_in_order(flag, print_width, print_d_sign, print_value);
            else
            {
                if (flag->zero)
                    print_in_order(flag, print_d_sign, print_width, print_value);
                else
                    print_in_order(flag, print_width, print_d_sign, print_value);
            }
        }
    }
    free(flag->pvalue);
    free(flag);
}

static  void set_res(va_list *ap, char *res)
{
    char type;

    type = *(res + (int)ft_strlen(res) -1);
    if (type == 'd' || type == 'i')
        print_d(ap, res);
    else if (type == 'c')
        print_c(ap, res);
    else if (type == 's')
        print_s(ap, res);
    else if (type == '%')
        print_per(ap, res);
    else if (type == 'p')
        print_p(ap, res);
    else if (type == 'u')
        print_u(ap, res);
    else if (type == 'x')
        print_x(ap, res);
}
static  char    *set_dtarg(char *a, int *k)
{
    char    *pt_type;

    *k = 0;
    while (a[*k] != 'd' && a[*k] != 'c' && a[*k] != 's' && a[*k] != '%' && a[*k] != 'p' && a[*k] != 'u' && a[*k] != 'x' && a[*k] != '\0')
        (*k)++;
    if (a[*k] == '0')
        return (0);
    pt_type = (char *)ft_calloc(((*k) + 2) ,sizeof(char));
    if (pt_type)
        ft_memcpy(pt_type, a, (*k) +1);
    return (pt_type);
}

static  int checker(va_list *ap, const char *a)
{
    char *res;
    int k;

    //k = 0;
    res = set_dtarg((char *)a, &k);
    if (!res)
        return (0);
    //printf("%p\n",&res);
    set_res(ap, res);
    //printf("%p\n",&res);
    free(res);
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