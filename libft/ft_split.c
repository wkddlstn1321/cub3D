/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daskim <daskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:55:35 by jeoan             #+#    #+#             */
/*   Updated: 2022/09/30 16:41:09 by daskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_field(const char *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			n++;
			s = ft_strchr(s, c);
			if (!s || !*s)
				break ;
		}
		s++;
	}
	return (n);
}

static void	ft_free_str_arr(char **array)
{
	while (*array)
		free(*array++);
	free(array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	field;
	size_t	i;

	field = ft_count_field(s, c);
	array = ft_calloc(field + 1, sizeof(char *));
	i = 0;
	while (array && i < field)
	{
		if (*s != c)
		{
			if (ft_strchr(s, c))
			{
				array[i] = ft_substr(s, 0, ft_strchr(s, c) - s);
				s = ft_strchr(s, c);
			}
			else
				array[i] = ft_strdup(s);
			if (!array[i++])
				return (ft_free_str_arr(array), NULL);
		}
		s++;
	}
	return (array);
}
