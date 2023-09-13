#include "libft.h"

#include <string.h>

char	*ft_strnstr(const char *string, const char *find, size_t n)
{
	size_t	counter;
	size_t	match;

	counter = 0;
	match = 0;
	if (find[0] == '\0')
		return ((char *)string);
	while (string[counter] != '\0' && counter < n)
	{
		while (string[counter + match] == find[match] && counter + match < n)
		{
			if (find[match + 1] == '\0')
				return ((char *)(string + counter));
			match++;
		}
		match = 0;
		counter++;
	}
	return (NULL);
}

#include <stdio.h>

int	main (void)
{
	const char *haystack = "This is a sample string";
	const char *needle = "sample";
	size_t n = 20;

	char *result = ft_strnstr(haystack, needle, n);

	if (result != NULL)
		printf("Found \"%s\" in \"%s\"\n", needle, haystack);
	else
		printf("Substring not found\n");
	return (0);
}
