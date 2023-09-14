#include <string.h>

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*s;
	s = (unsigned char *)str;
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

#include <stdio.h>

int	main (void)
{

	char	array[20] = "This is a test string";
	void	*result = array;
	size_t	n = 5;

	printf("Before ft_bzero: %s\n", result);

	ft_bzero(result, n);
	
	printf("After ft_bzero with size_t = %d: %s\n", n, result);
}
