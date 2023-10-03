#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 

#  include <fcntl.h>
#  include <stdlib.h>
#  include <unistd.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;

# endif
#endif
/*	first endif is for GET_NEXT_LINE_H
	second endif is for BUFFER_SIZE
*/
