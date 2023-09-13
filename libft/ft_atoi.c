int	ft_atoi(const char *str)
{
	int	i;
	unsigned int	result;
	int	negative;

	i = 0;
	result = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(result * negative));
}

#include <stdio.h>

int	main (void)
{
	const char *str = "12345";
	int result = ft_atoi(str);
	printf("Result: %d\n", result);
	return 0;
}
