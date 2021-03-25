/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:05:09 by gilee             #+#    #+#             */
/*   Updated: 2021/03/25 16:44:19 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_p(va_list *ap, char *res)
{
    Flag    *flag;
    size_t  len;
    int     real_len;

    flag = (Flag *)ft_calloc(1, sizeof(Flag));
    set_flag(flag, ap, res, 'p');
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
    flag = 0;
}