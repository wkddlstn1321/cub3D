/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:29:35 by jeoan             #+#    #+#             */
/*   Updated: 2021/11/23 02:29:32 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static long	ft_minimal_strtol(const char *str)
{
	signed long		sign;
	unsigned long	num;
	unsigned long	temp;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		temp = num;
		num = num * 10 + (*str++ - '0');
		if (sign == 1 && (num >= LONG_MAX || num / 10 != temp))
			return (LONG_MAX);
		if (sign == -1 && (num >= -(unsigned long)LONG_MIN || num / 10 != temp))
			return (LONG_MIN);
	}
	return (sign * (signed long)num);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_minimal_strtol(str));
}
