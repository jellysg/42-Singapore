#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*str_buffer;
	struct s_list	*next;
}				t_list;

int		found_newline(t_list *list);
int		len_to_newline(t_list *list);
char	*get_next_line(int fd);
char	*get_line(t_list *list);
void	copy_string(t_list *list, char *str);
void	clear_list(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buffer);
void	create_list(t_list **list, int fd);
t_list	*find_last_node(t_list *list);

#endif
