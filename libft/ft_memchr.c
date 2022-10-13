/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:10:22 by jeoan             #+#    #+#             */
/*   Updated: 2021/11/21 16:36:50 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const t_byte	*string;

	string = s;
	while (n--)
	{
		if (*string == (t_byte)c)
			return ((t_byte *)string);
		string++;
	}
	return (NULL);
}
