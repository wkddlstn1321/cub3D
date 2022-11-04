
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	ft_strlcpy(dst + i, src, dstsize - i);
	return (i + ft_strlen(src));
}
