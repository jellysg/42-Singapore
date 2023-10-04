#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*line;
	int	i = 0;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf(" (Line %d) %s\n", ++i, line);
		free(line);
	}
	printf("\n===================================================\n");
	printf("\n|                  Test Complete                  |\n");
	printf("\n===================================================\n");
	printf("\n            Tested on: BUFFER_SIZE = %d\n          \n", BUFFER_SIZE);
	printf("\n             Scroll up to check results            \n\n\n");
	close(fd);
	return (0);
}
