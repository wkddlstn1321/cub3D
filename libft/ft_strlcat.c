/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 00:36:15 by jeoan             #+#    #+#             */
/*   Updated: 2021/11/21 16:59:30 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	ft_strlcpy(dst + i, src, dstsize - i);
	return (i + ft_strlen(src));
}
