#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;
	s = (unsigned char *)str;
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

#include <stdio.h>

int	main (void)
{
	char	string[20] = "This is a test string";
	int	c = 'A';
	size_t	n = 6;

	printf("Original String: %s\n", string);

	memset(string, c, n);
	
	printf("After memset with size_t %zu of %d:\n%s\n", n, c, string);
}
