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
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d:\n%s\n", ++i, line);
		free(line);
	}
	close(fd);
	return (0);
}
