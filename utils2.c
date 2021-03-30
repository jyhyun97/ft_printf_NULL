/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:27:23 by jumoon            #+#    #+#             */
/*   Updated: 2021/03/30 14:43:34 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *s)
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

char		*ft_strdup(const char *s)
{
	char			*p;
	unsigned int	i;

	if (!(p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char		*ft_strchr(const char *s, int c)
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

int			digit_length(long long int n, int base)
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

char		*ft_itoa_base(long long int n, char *base_set)
{
	int		len;
	char	*p;
	int		base;

	base = ft_strlen(base_set);
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
