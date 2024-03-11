#include "../../includes/so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void free_elements(t_map *c)
{
	int	i;

	i = 0;
    while (i < c->current_line)
    {
        free(c->map[i]);
		i++;
    }
    free(c->map);
    free(c->line);
    free(c->prev_line);
}

void    mem_dup(t_map *c)
{
    int count;

    count = 0;
	if (c->current_line != 0)
		c->map[c->current_line - 1] = ft_strdup(c->prev_line);
	if (!c->map_buffer)
		return;
	while (count < c->current_line)
	{
		c->map_buffer[count] = ft_strdup(c->map[count]);
		count++;
	}
}

void mem_alloc(t_map *c)
{
	int i;

	i = 0;
	c->map_buffer = (char **)malloc((c->current_line + 1) * sizeof(char *));
    mem_dup(c);
    c->map = (char **)malloc((c->current_line + 1) * sizeof(char *));
    while (i < c->current_line)
    {
        c->map[i] = ft_strdup(c->map_buffer[i]);
		i++;
    }
    c->map[c->current_line] = ft_strdup(c->line);
    c->map_buffer[c->current_line] = ft_strdup(c->line);
}