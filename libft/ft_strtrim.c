
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed_str;
	size_t	len;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, *(s1 + len - 1)))
		len--;
	trimmed_str = malloc((len + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1, len + 1);
	return (trimmed_str);
}
