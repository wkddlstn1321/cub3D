/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:59:45 by jeoan             #+#    #+#             */
/*   Updated: 2021/12/03 15:57:51 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	if (start < ft_strlen(s))
		ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
