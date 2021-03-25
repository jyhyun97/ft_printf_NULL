/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:02:41 by gilee             #+#    #+#             */
/*   Updated: 2021/03/25 18:08:25 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void     print_x(va_list *ap, char *res)
{
    Flag    *flag;

    flag = (Flag *)ft_calloc(1, sizeof(Flag));
    set_flag(flag, ap, res, 'x');
    set_x_flag(flag);
    if (flag->value < 0)
        put_str(ft_itoa_base(4294967295 + flag->value + 1, 16, 0));
    else
    {
        if (flag->minus)
            print_in_order(flag, 0, print_value, print_width);
        else
        {
            if (flag->dot)
                print_in_order(flag, print_width, 0, print_value);
            else
            {
                if (flag->zero)
                    print_in_order(flag, 0, print_width, print_value);
                else
                    print_in_order(flag, print_width, 0, print_value);
            }
        }
    }
    free(flag->pvalue);
    free(flag);
    flag = 0;
}