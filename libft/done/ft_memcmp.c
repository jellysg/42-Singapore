#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	buffer1 = (unsigned char *)s1;
	buffer2 = (unsigned char *)s2;
	count = 0;
	if (n == 0)
		return (0);
	while ((buffer1[count] == buffer2[count]) && count < n - 1)
		count++;
	return (buffer1[count] - buffer2[count]);
}
