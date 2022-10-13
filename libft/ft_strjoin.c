/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:30:52 by jeoan             #+#    #+#             */
/*   Updated: 2021/11/26 12:32:04 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, len + 1);
	ft_strlcat(new_str, s2, len + 1);
	return (new_str);
}
