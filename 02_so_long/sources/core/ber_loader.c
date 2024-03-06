#include "../../libft/includes/libft.h"
#include "../includes/so_long.h"

int	walls_and_components(t_map *c)
{
	if (c->line[c->len] == '\n')
			c->line[c->len] = '\0';
		if (c->len != ft_strlen(c->line))
			return (-1);
		if (c->line[c->current_col] != '1' || c->line[c->len - 1] != '1')
			return (-1);
		while (c->current_col < c->len)
		{
			if (c->line[c->current_col] == 'E')
				c->e_count++;
			if (c->line[c->current_col] == 'P')
				c->p_count++;
			if (c->line[c->current_col] == 'C')
				c->c_count++;
			c->current_col++;
		}
	return(0);
}

int	valid_map_format(t_map *c)
{
	if (c->line[0] == '\n')
		return (-1);
	if (c->current_line == 0)
	{
		c->len = ft_strlen(c->line) - 1;
		if (c->line[c->len] == '\n')
			c->line[c->len] = '\0';
		while (c->current_col < c->len)
		{
			if (c->line[c->current_col] != '1')
				return (-1);
			c->current_col++;
		}
	}
	else
		if (walls_and_components(c) != 0)
			return(-1);
	mem_alloc(c);
	c->current_line++;
	c->current_col = 0;
	c->prev_line = ft_strdup(c->line);
	return(0);
}

int	invalid_map(t_map *c)
{
	free (c->line);
	printf("Error\n");
	return (-1);
}

int	open_map(t_map *c, char *map_name)
{
	c->fd = open(map_name, O_RDONLY);
	if (c->fd == -1)
	{
		perror("Error opening file.\n");
		return (1);
	}
	while ((c->line = get_next_line(c->fd)) != NULL)
	{
		if (valid_map_format(c) != 0)
			invalid_map(c);
	}
	while (c->current_col < c->len)
	{
		if (c->prev_line[c->current_col] != '1')
			invalid_map(c);
		c->current_col++;
	}
	if (c->e_count != 1 || c->p_count != 1 || c->c_count < 1)
		invalid_map(c);
	// int	LMAO = 0;
	// while (LMAO < c->current_line)
	// {
	// 	ft_printf("%i: %s\n", LMAO, c->map[LMAO]);
	// 	LMAO++;
	// }
	return (c->fd);
}

static void	init_vars(t_map *var)
{
	var->e_count = 0;
	var->p_count = 0;
	var->c_count = 0;
	var->current_line = 0;
	var->current_col = 0;
	var->len = 0;
	var->fd = 0;
}

int	main(int argc, char *argv[])
{
	t_map c;

	init_vars(&c);
	if (argc != 2 || 
		ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
        printf("Invalid arguments\n");
        return (1);
    }
	else
	{
		open_map(&c, argv[1]);
		free_elements(&c);
	}
	close(c.fd);
	return (0);
}