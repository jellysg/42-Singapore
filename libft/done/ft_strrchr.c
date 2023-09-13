#include "libft.h"

char	*strrchr(const char *s, int c)
{
	unsigned char	*str;
	size_t	i;
	size_t	checkpoint;

	str = (unsigned char *)s;
	i = 0;
	checkpoint = 0;
	while (str[i] && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
	{
		if (str[i] == c)
			checkpoint = i;
		i++;
	}
	if (checkpoint > 0)
		return ((char *)(str + checkpoint));
	return (NULL);
}

#include <stdio.h>

int	main (void)
{
	char string[30] = "This is a string";
	int c = 's';
	printf("Finding last |%c| in |%s|:\n", c, string);
	printf("Return: |%s|\n", strrchr(string, c));
}
