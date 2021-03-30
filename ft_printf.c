/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 01:52:15 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/30 21:37:24 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_count;

void	print_format(char type, t_list *flag, va_list ap)
{
	long long	d;
	char		*d_str;

	if (type == '%')
		print_c(flag, type, '%');
	else if (type == 'c')
		print_c(flag, type, (char)va_arg(ap, int));
	else if (type == 's')
		print_s(va_arg(ap, char *), flag);
	else if (type == 'd' || type == 'i')
	{
		d = va_arg(ap, int);
		d_str = ft_itoa_base((long long int)d, "0123456789");
		if (d < 0)
			flag->minus = 1;
		print_d(flag, d, d_str, ft_strlen(d_str));
	}
	else if (type == 'u')
		print_u(flag, ap);
	else if (type == 'x')
		print_x(flag, (long long)va_arg(ap, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		print_x(flag, (long long)va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (type == 'p')
		print_p(flag, (long long)va_arg(ap, void *), "0123456789abcdef");
}

int		check_types(char *option, va_list ap)
{
	int		i;
	char	*found_type;
	t_list	*flag;

	if (!(flag = (t_list *)malloc(sizeof(t_list) * 1)))
		return (ERR);
	initialize_flag(flag);
	i = 0;
	while (option[i])
	{
		if ((found_type = ft_strchr(TYPE, option[i])))
		{
			option[i] = '\0';
			if (option)
				if (!(set_flags(option, flag, ap)))
					write(1, "warning!\n", 9);
			break ;
		}
		i++;
	}
	print_format(found_type[0], flag, ap);
	free(flag);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*option;

	g_count = 0;
	i = 0;
	va_start(ap, format);
	if (!(option = (char *)ft_strdup(format)))
		return (ERR);
	while (option[i])
	{
		if (option[i] == '%' && option[++i])
			i += check_types(&option[i], ap);
		else
			write_with_count(&option[i], 1);
		i++;
	}
	va_end(ap);
	free(option);
	return (g_count);
}
