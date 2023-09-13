#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int	count;
	int	dup;

	count = 0;
	dup = 0;
	while (src[count] != '\0')
		count++;
	dest = (char *)malloc(count + 1);
	while (dup < count)
	{
		dest[dup] = src[dup];
		dup++;
	}
	dest[dup] = '\0';
	return (dest);
}

#include <stdio.h>

int	main (void)
{
	char	*original = "This is a string";
	char	duplicate[6];

	printf("\n");
	printf("Original: \"%s\"\n", original);
	printf("Target Memory Pointer: \"%s\"\n", duplicate);
	printf("\n");
	printf("After ft_strdup original to target memory...");
	char *result = ft_strdup(original);
	printf("\n");

	if (result != NULL)
	{
		printf("\n");
		printf("Original String: \"%s\"\n", original);
		printf("Duplicate Result: \"%s\"\n", result);
		printf("\n");
		free(result);
		
	}
	else
		printf("Memory allocation failed.\n");

	return 0;
}
