/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insjang <insjang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:29:24 by jeoan             #+#    #+#             */
/*   Updated: 2022/10/17 11:51:19 by insjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	length;
	char	*dest;

	length = ft_strlen(str);
	if (length == 0)
		return (NULL);
	dest = malloc(length + 1);
	if (!dest)
		return (NULL);
	return (ft_memcpy(dest, str, length + 1));
}
