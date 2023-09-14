#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

#include <stdio.h>

int	main (void)
{
	const char	*string = "Hello, World!";
	char	character = 'r';
	size_t	n = 10;

	printf("Searching first %ld bytes for '%c' in '%s':\n", n, character, string);
	
	void *result = ft_memchr(string, character, n);
	if (result)
		printf("%c is found: %s\n", character, (char *)result);
	else
		printf("%c is not found\n", character);
	return (0);
}
