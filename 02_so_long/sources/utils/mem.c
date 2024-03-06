#include "../../includes/so_long.h"

void    free_elements(t_map *c)
{
    free(c->map_buffer);
    free(c->line);
    free(c->prev_line);
}

void    mem_dup(t_map *c)
{
    int count;

    count = 0;
	if (c->current_line != 0)
		c->map[c->current_line - 1] = ft_strdup(c->prev_line);
	while (count < c->current_line)
	{
		c->map_buffer[count] = ft_strdup(c->map[count]);
		count++;
	}
}

void	mem_alloc(t_map *c)
{
    size_t	mem_size;

    mem_size = (c->len * c->current_line) * sizeof(char);
	c->map_buffer = (char **)malloc(mem_size);
    mem_dup(c);
	c->map = (char **)malloc(mem_size + (c->len * sizeof(char)));
	c->map = c->map_buffer;
	c->map[c->current_line] = ft_strdup(c->line);
}