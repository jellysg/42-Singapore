void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

#include <stdio.h>

void	ft_capitalize_test(unsigned int index, char *character)
{
	printf("Index[%d]: %c\n", index, *character);
	if (*character >= 'a' && *character <= 'z')
		*character = *character - 32;
}

int	main(void)
{
	char input_string[] = "Hello, World!";

	printf("Original String: %s\n", input_string);
	ft_striteri(input_string, ft_capitalize_test);
	printf("Modified String: %s\n", input_string);
	return (0);
}

