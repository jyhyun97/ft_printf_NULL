/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 01:52:15 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/26 01:53:30 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_format(char type, s_list *flag, va_list ap)
{
	if (type == '%')
		print_c(flag, type, '%');
	else if (type == 'c')
		print_c(flag, type, va_arg(ap, int));
	else if (type == 's')
		print_s(va_arg(ap, char *), flag);
	else if (type == 'd' || type == 'i')
		print_d(flag, ap);
	else if (type == 'u')
		print_u(flag, ap);
	else if (type == 'x' || type == 'X')
		print_x(flag, ap, type);
	else if (type == 'p')
		print_p(flag, ap, type);
	return (1);
}

int check_types(char *option, va_list ap)
{
	int i;
	
	char *found_type;
	s_list *flag;

	if (!(flag = (s_list *)malloc(sizeof(s_list) * 1)))
		return (-1);
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
			break;
		}
		i++;
	}
	print_format(found_type[0], flag, ap);
	free(flag);
	return (i);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int i;
	char *option;

	g_count = 0;
	i = 0;
	va_start(ap, format);
	if (!(option = (char *)ft_strdup(format)))
		return (-1);
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
