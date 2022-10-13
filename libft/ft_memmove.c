/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:37:00 by jeoan             #+#    #+#             */
/*   Updated: 2021/11/21 16:38:44 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_byte_forward(t_byte *dst, const t_byte *src, size_t len)
{
	while (len--)
		*dst++ = *src++;
}

static void	copy_byte_backward(t_byte *dst, const t_byte *src, size_t len)
{
	while (len--)
		*(dst + len) = *(src + len);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_byte			*dest;
	const t_byte	*source;

	dest = dst;
	source = src;
	if (dest >= source + len || dest < source)
		copy_byte_forward(dest, source, len);
	else
		copy_byte_backward(dest, source, len);
	return (dst);
}
