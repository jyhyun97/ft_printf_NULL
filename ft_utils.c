/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:01:18 by jso               #+#    #+#             */
/*   Updated: 2021/03/02 16:29:43 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*str++)
		++i;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char			*str_2;
	unsigned int	i;

	if (str == '\0')
		return (0);
	str_2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str_2 == 0)
		return (0);
	i = 0;
	while (*str)
		*str_2++ = *str++;
	*str_2 = '\0';
	return (str_2);
}
