/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:09:08 by jeoan             #+#    #+#             */
/*   Updated: 2022/10/14 11:50:14 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	t_byte	*dest;

	dest = dst;
	while (len-- > 0 && *(*(t_byte **)&src) != '\n')
		*dest++ = *(*(t_byte **)&src)++;
	return (dst);
}
