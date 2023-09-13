#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	if (size > 0)
	{
		count = 0;
		while (src[count] && count < size - 1)
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	while (src[count])
		count++;
	return (count);
}

#include <stdio.h>

int main()
{
	char dest[20];
	int size = 3;
	
	int result1 = ft_strlcpy(dest, "Hello", size);
	printf("Result 1: %s, Count: %d, Return: %d\n", dest, size, result1);

	int result2 = ft_strlcpy(dest, "World", size);
	printf("Result 1: %s, Count: %d, Return: %d\n", dest, size, result2);

	int result3 = ft_strlcpy(dest, "Goodbye", size);
	printf("Result 1: %s, Count: %d, Return: %d\n", dest, size, result3);

	return 0;
}

