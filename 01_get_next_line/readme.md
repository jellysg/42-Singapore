This assignment was particularly tricky, hence the need for main.c even with assistance from paco

Feel free to test it out using my main.c and test.txt




### BUFFER_SIZE Check (Optional)
Replace 'prepare_list_from_file' function in get_next_line.c with the following:
```
void	prepare_list_from_file(int fd, t_list **list)
{
	char	*buffer;
	int		num_bytes;

	num_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!found_newline(*list) && num_bytes != 0)
	{
		if (buffer == NULL)
			return ;
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if ((*list == NULL && num_bytes == 0) || num_bytes == -1)
		{
			free(buffer);
			if (num_bytes == -1)
				free_list(*list);
			*list = NULL;
			return ;
		}
		buffer[num_bytes] = '\0';
		append_buffer_to_list(list, buffer, num_bytes);
		static int i = 0;
		printf("\nCurrent Buffer iteration: %d|", ++i);
		usleep(10000);
	}
	free(buffer);
}
```

### Compile with the following to test, this main.c works with any GNL file
Do note that this is a very simple test, refer to Tripouille or fsoares for optimized tests
```
cc -Wall -Wextra -Werror *e.c *ls.c main.c
```

3. Run the test case
```
./a.out
```
