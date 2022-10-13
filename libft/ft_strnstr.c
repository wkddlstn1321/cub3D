/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:02:05 by jeoan             #+#    #+#             */
/*   Updated: 2021/12/03 15:50:52 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*temp;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	temp = ft_strchr(haystack, *needle);
	while (temp)
	{
		if (temp > haystack + len - ft_strlen(needle))
			break ;
		if (!ft_strncmp(temp, needle, ft_strlen(needle)))
			return ((char *)temp);
		temp = ft_strchr(temp + 1, *needle);
	}
	return (NULL);
}
