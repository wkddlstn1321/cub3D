
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s || !(char)c)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
