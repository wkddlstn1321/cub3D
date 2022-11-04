
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	length;
	char	*dest;

	length = ft_strlen(str);
	if (length == 0)
		return (NULL);
	dest = malloc(length + 1);
	if (!dest)
		return (NULL);
	return (ft_memcpy(dest, str, length + 1));
}
