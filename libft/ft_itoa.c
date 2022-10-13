/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:34:59 by jeoan             #+#    #+#             */
/*   Updated: 2021/11/28 15:34:20 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_itoa_strlen(int n)
{
	size_t	length;

	length = 1;
	if (n < 0)
		length++;
	while (n / 10)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	length;

	length = ft_get_itoa_strlen(n);
	str = ft_calloc(length + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (!n)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n > 0)
			str[--length] = BASE10_CHAR[n % 10];
		else
			str[--length] = BASE10_CHAR[-(n % 10)];
		n /= 10;
	}
	return (str);
}
