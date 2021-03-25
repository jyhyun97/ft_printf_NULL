/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:57:47 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/15 19:01:51 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define TYPE "cspdiuxX%nfge"
#define FLAG "-# +*.lh"
typedef struct t_list
{
	int left;
	int zero;
	int has_width;
	int width;
	int has_prec;
	int prec;
} s_list;

int g_count;

size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t s_len;

	if (!src || !dst)
		return (0);
	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	i = 0;
	while (src[i] && (i + 1) < size)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (s_len);
}

static int int_length(int n)
{
	int len;

	if (n == -2147483648)
		return (11);
	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n /= 10)
		len++;
	return (++len);
}

char *ft_itoa(int n)
{
	int len;
	char *p;

	len = int_length(n);
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == INT_MIN)
	{
		ft_strlcpy(p, "-2147483648", len + 1);
		return (p);
	}
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	if (n == 0)
		p[0] = '0';
	p[len] = '\0';
	while (n)
	{
		p[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (p);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d == s)
		return (dst);
	while (n--)
		*d++ = *s++;
	return ((void *)dst);
}

char *ft_strdup(const char *s)
{
	char *p;
	int len;

	len = ft_strlen(s);
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(p, s, len + 1);
	return (p);
}

int ft_atoi(const char *str)
{
	long ret;
	int sign;

	ret = 0;
	sign = 1;
	while ((*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' ') && *str)
		++str;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (('0' <= *str && *str <= '9') && *str)
	{
		ret *= 10;
		ret += sign * (*(str++) - '0');
		if (ret > INT_MAX)
			return (-1);
		if (ret < INT_MIN)
			return (0);
	}
	return ((int)ret);
}

int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}

void initialize_flag(s_list *flag)
{
	flag->left = 0;
	flag->zero = 0;
	flag->has_width = 0;
	flag->width = 0;
	flag->has_prec = 0;
	flag->prec = 0;
}

static int set_precision(char *str, s_list *flag, va_list ap)
{
	int first_digit;

	printf("in prec str: [%s]\n", str);
	if (!*str)
	{
		flag->has_prec = -1;
		return (1);
	}
	first_digit = 1;
	while (*str)
	{
		if (*str == '*' || ft_isdigit(*str))
		{
			if ((flag->has_prec && *str == '*') ||
				(flag->has_prec && ft_isdigit(*str) && first_digit))
				return (0);
			if (!flag->has_prec)
				flag->has_prec = 1;
			if (*str == '*')
			{
				flag->prec = va_arg(ap, int);
				if (flag->prec < 0)
					flag->has_prec = -1;
			}
			else
			{
				flag->prec = flag->prec * 10 + (*str - '0');
				first_digit = 0;
			}
		}
		else
			return (0);
		str++;
	}
	printf("In Prec ==> left: %d, zero: %d, has_wd: %d, width: %d, has_prec: %d, prec: %d\n",
		   flag->left, flag->zero, flag->has_width, flag->width, flag->has_prec, flag->prec);
	return (1);
}

static int set_flags(char *str, s_list *flag, va_list ap)
{
	int first_digit;

	first_digit = 1;
	while (*str)
	{
		if (!(ft_strchr(FLAG, *str) || ft_isdigit(*str)))
			return (0);
		if (*str == '.')
			return (set_precision(str + 1, flag, ap));
		if (*str == '0' && flag->width == 0 && flag->left == 0)
			flag->zero = 1;
		if (*str == '-')
			flag->left = 1;
		if (*str == '*' || ft_isdigit(*str))
		{
			if ((flag->has_width && *str == '*') ||
				(flag->has_width && ft_isdigit(*str) && first_digit))
				return (0);
			if (*str == '*')
			{
				flag->width = va_arg(ap, int);
				if (flag->width < 0)
				{
					flag->width *= -1;
					flag->left = 1;
				}
			}
			else
			{
				flag->width = flag->width * 10 + (*str - '0');
				first_digit = 0;
			}
			if (!flag->has_width)
				flag->has_width = 1;
		}
		printf("left: %d, zero: %d, has_wd: %d, width: %d, has_prec: %d, prec: %d\n",
			   flag->left, flag->zero, flag->has_width, flag->width, flag->has_prec, flag->prec);
		str++;
	}
	return (1);
}

void padding(char c, int n)
{
	while (n--)
	{
		write(1, &c, 1);
	}
}

int print_d(s_list *flag, va_list ap)
{
	int len;
	int d;

	write(1, "[", 1);
	d = va_arg(ap, int);
	len = int_length(d);
	if (flag->left)
	{
		if (flag->has_prec == 1)
		{
			if (flag->prec > len)
			{
				if (d < 0)
				{
					write(1, "-", 1);
					padding('0', flag->prec - len - 1);
					write(1, ft_itoa(d) + 1, len - 1);
				}
				else
				{
					padding('0', flag->prec - len - 1);
					write(1, ft_itoa(d), len);
				}
				if (flag->width > flag->prec)
					padding(' ', flag->width - flag->prec);
			}
			else
			{
				write(1, ft_itoa, len);
				if (flag->width > len)
					padding(' ', flag->width - len);
			}
		}
		else
		{
			if (flag->zero)
			{
				if (flag->width - len > 0)
				{
					if (d < 0)
					{
						write(1, "-", 1);
						padding('0', flag->width - len - 1);
						write(1, ft_itoa(d) + 1, len - 1);
					}
					else
					{
						padding('0', flag->width - len);
						write(1, ft_itoa(d), len);
					}
				}
			}
			else
			{
				if (d < 0)
				{
					write(1, "-", 1);
					write(1, ft_itoa(d) + 1, len - 1);
					padding(' ', flag->width - len);
				}
				else
				{
					write(1, ft_itoa(d), len);
					padding(' ', flag->width - len);
				}
			}
		}
	}
	else
	{
		if (flag->has_prec == 1)
		{
			if (flag->width > flag->prec)
				padding(' ', flag->width - flag->prec);
			if (flag->prec > len)
			{
				if (d < 0)
				{
					write(1, "-", 1);
					padding('0', flag->prec - len - 1);
					write(1, ft_itoa(d) + 1, len - 1);
				}
				else
				{
					padding('0', flag->prec - len);
					write(1, ft_itoa(d), len);
				}
				if (flag->width > flag->prec)
					padding(' ', flag->width - flag->prec);
			}
			else
			{
				if (flag->zero)
				{
					if (flag->width - len > 0)
					{
						if (d < 0)
						{
							write(1, "-", 1);
							if (flag->width > len)
								padding(' ', flag->width - len);
							write(1, ft_itoa(d), len);
						}
						write(1, "]", 1);

						printf("\n");
						puts("------------------------------------------------");
						printf("in print_d!! \n");
						puts("--------------- end of format ------------------");
						return (1);
					}

					int print_format(char type, s_list *flag, va_list ap)
					{
						if (type == 'd')
							print_d(flag, ap);

						printf("\n");
						puts("------------------------------------------------");
						printf("in format [type: %c] ==> Under Construction!!!\n", type);
						puts("--------------- end of format ------------------");
					}

					static int check_types(const char *format, va_list ap)
					{
						int i;
						int ret;
						char *found_type;
						char *option;
						s_list *flag;

						if (!(option = (char *)ft_strdup(format)))
							return (0);
						initialize_flag(flag);
						i = 0;
						while (option[i])
						{
							if ((found_type = ft_strchr(TYPE, option[i])))
							{
								option[i] = '\0';
								printf("\noption: %s\n", option);
								if (option)
									if (!(ret = set_flags(option, flag, ap)))
										write(1, "Error!\n", 7);
								break;
							}
							i++;
						}
						free(option);
						print_format(found_type[0], flag, ap);
						return (i);
					}

					int ft_printf(const char *format, ...)
					{
						va_list ap;
						int i;

						i = 0;
						printf("============ in ft_printf =================\n");
						printf("format: %s\n", format);
						va_start(ap, format);
						while (format[i])
						{
							if (format[i] == '%' && format[++i])
								i += check_types(&format[i], ap);
							else
							{
								write(1, &format[i], 1);
								g_count++;
							}
							i++;
						}
						va_end(ap);
						printf("============ end of ft_printf =================\n");
						return (g_count);
					}

					int main(void)
					{
						int ret;
						char *tmp = "Hello, world!";

						ret = ft_printf("10letters.%-*c%15c10sspacess%%10sspacess%10d10sspacess%d15This i s end.\n", 10, 'a', 'z', 7, 9);
						printf("ret: %d\n", ret);

						ret = ft_printf("|%d|", 12345);
						ret = printf("|%d|", 12345);
						ret = ft_printf("|%d|", -12345);
						ret = printf("|%d|", -12345);
						ret = ft_printf("|%3d|", 12345);
						ret = printf("|%3d|", 12345);
						ret = ft_printf("|%7d|", 12345);
						ret = printf("|%7d|", 12345);
						ret = ft_printf("|%-7d|", 12345);
						ret = printf("|%-7d|", 12345);
						ret = ft_printf("|%-d|", 12345);
						ret = printf("|%-d|", 12345);
						ret = ft_printf("|%*d|", 7, 12345);
						ret = printf("|%*d|", 7, 12345);
						ret = ft_printf("|%*d|", -7, 12345);
						ret = printf("|%*d|", -7, 12345);
						ret = ft_printf("|%.d|", 12345);
						ret = printf("|%.d|", 12345);
						ret = ft_printf("|%.0d|", 12345);
						ret = printf("|%.0d|", 12345);
						ft_printf("%d", 0);
						printf("%d", 0);
						ft_printf("%d", 0);
						printf("%d", 0);
						ft_printf("%3d", 0);
						printf("%3d", 0);
						ft_printf("%3.d", 0);
						printf("%3.d", 0);
						ft_printf("%03d", 0);
						printf("%03d", 0);
						return (0);
					}

	/*
printf("%d", 12345)
		result : |12345|
		return : 5
printf("%d", -12345)
		result : |-12345|
		return : 6
printf("%3d", 12345)
		result : |12345|
		return : 5
printf("%7d", 12345)
		result : |  12345|
		return : 7
printf("%-7d", 12345)
		result : |12345  |
		return : 7
printf("%-d", 12345)
		result : |12345|
		return : 5
printf("%*d", 7, 12345)
		result : |  12345|
		return : 7
printf("%*d", -7, 12345)
		result : |12345  |
		return : 7
printf("%.d", 12345)
		result : |12345|
		return : 5
printf("%.0d", 12345)
		result : |12345|
		return : 5
printf("%.3d", 12345)
		result : |12345|
		return : 5
printf("%.7d", 12345)
		result : |0012345|
		return : 7
printf("%-.7d", 12345)
		result : |0012345|
		return : 7
printf("%-9.7d", 12345)
		result : |0012345  |
		return : 9
printf("%9.7d", 12345)
		result : |  0012345|
		return : 9
printf("%-7.9d", 12345)
		result : |000012345|
		return : 9
printf("%-3.7d", 12345)
		result : |0012345|
		return : 7
printf("%-7.3d", 12345)
		result : |12345  |
		return : 7
printf("%.3d", -12345)
		result : |-12345|
		return : 6
printf("%.7d", -12345)
		result : |-0012345|
		return : 8
printf("%-.7d", -12345)
		result : |-0012345|
		return : 8
printf("%-9.7d", -12345)
		result : |-0012345 |
		return : 9
printf("%-7.9d", -12345)
		result : |-000012345|
		return : 10
printf("%-3.7d", -12345)
		result : |-0012345|
		return : 8
printf("%-7.3d", -12345)
		result : |-12345 |
		return : 7
printf("%0d", 12345)
		result : |12345|
		return : 5
printf("%07d", 12345)
		result : |0012345|
		return : 7
printf("%d", 0)
		result : |0|
		return : 1
printf("%3d", 0)
		result : |  0|
		return : 3
printf("%3.d", 0)
		result : |   |
		return : 3
printf("%03d", 0)
		result : |000|
		return : 3
printf("%09.0d", 12345)
		result : |    12345|
		return : 9
printf("%09.7d", 12345)
		result : |  0012345|
		return : 9
printf("%07.9d", 12345)
		result : |000012345|
		return : 9
printf("%.d", 0)
		result : ||
		return : 0
printf("%.3d", 0)
		result : |000|
		return : 3
printf("% d", 12345)
		result : | 12345|
		return : 6
printf("% d", -12345)
		result : |-12345|
		return : 6
printf("% -d", 12345)
		result : | 12345|
		return : 6
printf("% 3d", 12345)
		result : | 12345|
		return : 6
printf("% 7d", 12345)
		result : |  12345|
		return : 7
printf("%+d", 12345)
		result : |+12345|
		return : 6
printf("%+d", -12345)
		result : |-12345|
		return : 6
printf("%+-d", 12345)
		result : |+12345|
		return : 6
printf("%+-9d", 12345)
		result : |+12345   |
		return : 9
printf("%+9d", 12345)
		result : |   +12345|
		return : 9
printf("%+09d", 12345)
		result : |+00012345|
		return : 9
printf("%+09d", -12345)
		result : |-00012345|
		return : 9
printf("%-+09d", 12345)
		warning : flag '0' is ignored when flag '-' is present
printf("%+ 09d", 12345)
		warning : flag ' ' is ignored when flag '+' is present
printf("%+9.7d", 12345)
		result : | +0012345|
		return : 9
printf("%+09.7d", 12345)
		result : | +0012345|
		return : 9
printf("%+7.9d", 12345)
		result : |+000012345|
		return : 10
printf("%+07.9d", 12345)
		result : |+000012345|
		return : 10
printf("%+9.7d", -12345)
		result : | -0012345|
		return : 9
printf("%+09.7d", -12345)
		result : | -0012345|
		return : 9
printf("%+7.9d", -12345)
		result : |-000012345|
		return : 10
printf("%+07.9d", -12345)
		result : |-000012345|
		return : 10
printf("%#d", 0)
		undefined behavior warning: flag '#' with 'd'
*/