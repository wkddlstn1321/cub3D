/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:10:01 by jeoan             #+#    #+#             */
/*   Updated: 2021/11/28 17:27:40 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
		str[len] = (*f)((unsigned int)len, s[len]);
	return (str);
}
