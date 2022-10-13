/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:29:24 by jeoan             #+#    #+#             */
/*   Updated: 2021/11/23 07:31:42 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	length;
	char	*dest;

	length = ft_strlen(str);
	dest = malloc(length + 1);
	if (!dest)
		return (NULL);
	return (ft_memcpy(dest, str, length + 1));
}
