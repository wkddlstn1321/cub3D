
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	t_byte	*dest;

	dest = dst;
	while (len-- > 0)
		*dest++ = *(*(t_byte **)&src)++;
	return (dst);
}
