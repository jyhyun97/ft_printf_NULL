/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:27:23 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/26 02:34:49 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		write_with_count(char *c, int n)
{
		write(1, c, n);
		g_count += n;
}

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
	flag->minus = 0;
}

static int digit_length(long long int n, int base)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n /= base)
		len++;
	return (++len);
}

char	*ft_itoa_base(long long int n, char *base_set, int base)
{
	int		len;
	char	*p;

	len = digit_length(n, base);
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
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
		p[--len] = base_set[n % base];
		n /= base;
	}
	return (p);
}

void padding(char c, int n)
{
	while (n--)
	{
		write(1, &c, 1);
		g_count++;
	}
}

void calculate_paddings(s_list *flag, int *zeros, int *spaces, int len)
{
	*zeros = 0;
	*spaces = 0;

	if (flag->has_prec == 1)
	{
		if (flag->prec > len)
		{
			*zeros = flag->prec - (len - flag->minus);
			if (flag->width > flag->prec)
				*spaces = flag->width - (flag->prec + flag->minus);
		}
		else
		{
			if (flag->width > len)
				*spaces = flag->width - len;
		}
	}
	else if (flag->zero)
	{
		if (flag->width > len)
			*zeros = flag->width - len;
	}
	else
	{
		if (flag->width > len)
			*spaces = flag->width - len;
	}
}
