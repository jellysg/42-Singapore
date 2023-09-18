#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

#include <stdio.h>

int	main(void)
{
	char myChar = 'A';
	ft_putchar_fd(myChar, 1);
	printf("\n");
	return (0);
}
