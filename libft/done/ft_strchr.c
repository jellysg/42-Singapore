#include "libft.h"

char	*strchr(const char *s, int c)
{
	unsigned char	*str;
	size_t	i;

	str = (unsigned char *)s;
	i = 0;
	while (str[i] && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
	{
		if (str[i] == c)
			return ((char *)(str+i));
		i++;
	}
	return (NULL);
}

#include <stdio.h>

int	main (void)
{
	char string[30] = "This is a string";
	int c = 's';
	printf("Finding first |%c| in |%s|:\n", c, string);
	printf("Return: |%s|\n", strchr(string, c));
}
