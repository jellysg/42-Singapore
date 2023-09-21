#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;
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

#include <stdio.h>

int	main (void)
{
	char str1[] = "Hello, World!";
	char str2[] = "Hello, World!";
	int result = ft_memcmp(str1, str2, sizeof(str1));
	printf("%s\n%s\nmemcmp same memory block result: %d\n", str1, str2, result);
	printf("\n");

    return 0;
}
