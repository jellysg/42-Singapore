#include "get_next_line.h"

void	clear_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buffer || NULL == clean_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->str_buffer[i] && last_node->str_buffer[i] != '\n')
		++i;
	while (last_node->str_buffer[i] && last_node->str_buffer[++i])
		buffer[k++] = last_node->str_buffer[i];
	buffer[k] = '\0';
	clean_node->str_buffer = buffer;
	clean_node->next = NULL;
	dealloc(list, clean_node, buffer);
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_string;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_string = malloc(str_len + 1);
	if (!next_string)
		return (NULL);
	copy_string(list, next_string);
	return (next_string);
}

void	append(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buffer = buffer;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;	
	char	*buffer;

	while (!found_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (NULL == buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		append(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	clear_list(&list);
	return (next_line);
}
