#include "libft.h"

static int	ft_countdigits(int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while ((unsigned int)n > 0)
	{
		res++;
		n = (unsigned int)n / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		num_digits;

	num_digits = ft_countdigits(n);
	res = malloc((num_digits + 1) * sizeof(char));
	if (n == 0)
		res[0] = 48;
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[num_digits] = '\0';
	while ((num_digits - 1) >= 0 && (unsigned int)n > 0)
	{	
		res[num_digits - 1] = ((unsigned int)n % 10) + '0';
		n = (unsigned int)n / 10;
		num_digits--;
	}
	return (res);
}

#include <stdio.h>

int	main(void)
{
    int test[] = {12345, -6789, 0, -123, 987654321, -2147483648};
    int num_tests = sizeof(test) / sizeof(test[0]);

    for (int i = 0; i < num_tests; i++) {
        int input = test[i];
        char *result = ft_itoa(input);

        if (result == NULL) {
            printf("Error: Memory allocation failed.\n");
            return 1; // Exit with an error code
        }

        printf("Input: %d\n", input);
        printf("Result: %s\n\n", result);

        // Clean up allocated memory
        free(result);
    }

    return 0; // Exit successfully
}
