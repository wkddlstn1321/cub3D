
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
