
#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	unsigned long	num;
	int				sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if ((*str == '+' || *str == '-') && *str + 1 != '\0')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (ft_strlen(str) > 10)
		return (-1);
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - '0');
	if (*str != '\0')
		return (-1);
	if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
		return (-1);
	return ((signed long)num * sign);
}
