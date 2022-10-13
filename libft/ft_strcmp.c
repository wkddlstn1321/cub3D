/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daskim <daskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:33:32 by daskim            #+#    #+#             */
/*   Updated: 2022/09/29 11:34:32 by daskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (*t1)
	{
		if (*t1 != *t2 || !*t1 || !*t2)
			return (*t1 - *t2);
		++t1;
		++t2;
	}
	return (*t1 - *t2);
}
