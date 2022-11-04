
#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	t_byte	*dest;

	dest = b;
	while (len-- > 0)
		*dest++ = (t_byte)c;
	return (b);
}
