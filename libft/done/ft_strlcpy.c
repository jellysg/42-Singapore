#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size != 0)
	{
		while (src [count] != '\0' && count < (size - 1))
		{
			dest[count] = src[count];
			count++;
		}
		dest[count] = '\0';
	}
	return (ft_strlen(src));
}
