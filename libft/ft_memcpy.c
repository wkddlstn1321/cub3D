/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insjang <insjang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:09:08 by jeoan             #+#    #+#             */
/*   Updated: 2022/10/17 11:50:09 by insjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	t_byte	*dest;

	dest = dst;
	while (len-- > 0)
		*dest++ = *(*(t_byte **)&src)++;
	return (dst);
}
