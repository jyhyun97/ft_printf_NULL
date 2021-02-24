#include "ft_printf.h"

t_size	g_size;
t_flag	g_flag;

int			pf_flag_checker(va_list ap, const char *s)
{
	int		i;
	int		result;

	i = -1;
	result = 1;
	while (result == 1 && s[++i])
		result = flag_save(s[i]);
	while (result == 0 && s[i])
		result = wpl_check(s[i++], ap);
	return	(--i);
}

static int	pf_checker(va_list ap, const char *s)
{
	int		i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '%')
		{
			ft_flag_reset();
			++i;
			i += pf_flag_checker(ap, &s[i]);
			if (flag_format_checker(&s[i]))
				return (g_size.all_size);
			pf_format_checker(ap, s[i]);
		}
		else
			ft_putchr((char *)&s[i], 1);
		++i;
	}
	return (g_size.all_size);
}

int			ft_printf(const char *s, ...)
{
	va_list	ap;
	int		rst;

	rst = 0;
	va_start(ap, s);
	ft_size_reset();
	rst = pf_checker(ap, s);
	va_end(ap);
	return (rst);
}

int			main(void)
{
	// char *l = "test";
	// char c = 'A';
	// char c1 = 'S';
	// int	a = 16;
	// int b = 15;
	int d = 9675;
	int e = 2214;

	printf("ft u ----------------------------------\n");
	ft_printf("%-7u ft\n", e);
	ft_printf("%-7.2u ft\n", d);
	ft_printf("%-5.*u ft\n", 7, e);
	printf("print ---------------------------------\n");
	printf("%-7u ft\n", e);
	printf("%-7.2u ft\n", d);
	printf("%-5.*u ft\n", 7, e);
	printf("ft ----------------------------------\n");
	ft_printf("%07u ft\n", d);;
	printf("print ---------------------------------\n");
	printf("%07u ft\n", d);;
	printf("ft ----------------------------------\n");
	ft_printf("%.*u ft\n", 7, e);
	ft_printf("%*u ft\n", 7, d);
	printf("print ---------------------------------\n");
	printf("%.*u ft\n", 7, e);
	printf("%*u ft\n", 7, d);
	printf("end -----------------------------------\n");
	printf("\n");
	printf("\n");
	printf("ft xX----------------------------------\n");
	ft_printf("%-x ft\n", e);
	ft_printf("%-#x ft\n", e);
	ft_printf("%-*x ft\n", 10, e);
	ft_printf("%-.9x ft\n", e);
	ft_printf("%-*.*x ft\n", 10, 7, e);
	printf("print ----------------------------------\n");
	printf("%-x ft\n", e);
	printf("%-#x ft\n", e);
	printf("%-*x ft\n", 10, e);
	printf("%-.9x ft\n", e);
	printf("%-*.*x ft\n", 10, 7, e);
	printf("ft -----------------------------------\n");
	ft_printf("%010X ft\n", e);
	ft_printf("%0#7X ft\n", e);
	ft_printf("%0*X ft\n", 11, e);
	ft_printf("%02X ft\n", e);
	printf("print ----------------------------------\n");
	printf("%010X ft\n", e);
	printf("%0#7X ft\n", e);
	printf("%0*X ft\n", 11, e);
	printf("%02X ft\n", e);
	printf("ft -----------------------------------\n");
	ft_printf("%10.2x ft\n", e);
	ft_printf("%#10.2x ft\n", e);
	ft_printf("%10.*x ft\n", 11, e);
	printf("print ----------------------------------\n");
	printf("%10.2x ft\n", e);
	printf("%#10.2x ft\n", e);
	printf("%10.*x ft\n", 11, e);
	printf("end -----------------------------------\n");

	// printf("P -----------------------------------\n");
	// ft_printf("%-20p ft\n", &a);
	// ft_printf("%20p %5p ft\n", &a, &b);
	// ft_printf("%*p ft\n", 20, &a);
	// printf("-----------------------------------\n");
	// printf("%-20p ft\n", &a);
	// printf("%20p %5p ft\n", &a, &b);
	// printf("%*p ft\n", 20, &a);
	// printf("end ---------------------------------\n");

	// printf("c ----------------------------------\n");
	// ft_printf("%-9c ft\n", c);
	// ft_printf("%6c %5c ft\n", c, c1);
	// ft_printf("%*c ft\n", 10, c);
	// printf("-----------------------------------\n");
	// printf("%-9c ft\n", c);
	// printf("%6c %5c ft\n", c, c1);
	// printf("%*c ft\n", 10, c);
	// printf("end -----------------------------------\n");

	// printf("s ----------------------------------\n");
	// ft_printf("%-9s ft\n", l);
	// ft_printf("%6s %5s ft\n", l, l);
	// ft_printf("%7.3s ft\n", l);
	// ft_printf("%.*s ft\n", 0, l);
	// printf("-----------------------------------\n");
	// printf("%-9s ft\n", l);
	// printf("%6s %5s ft\n", l, l);
	// printf("%7.3s ft\n", l);
	// printf("%.*s ft\n", 0, l);
	// printf("end ----------------------------------\n");
	return (0);
}
