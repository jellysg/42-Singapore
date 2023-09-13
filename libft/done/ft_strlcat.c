#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (dst[i] && i < size)
		i++;
	while (src[count] && i + count < size - 1)
	{
		dst[i + count] = src[count];
		count++;
	}
	if (i < size - 1)
		dst[i + count] = '\0';
	while (src[count])
		count++;
	return (i + count);
}

#include <stdio.h>

int	main (void)
{
	char dest[20] = "Hello, ";
	
	int result = ft_strlcat(dest, "World", 3);
	printf("Result: %s\nReturn: %d\n", dest, result);
	
	return 0;
}
