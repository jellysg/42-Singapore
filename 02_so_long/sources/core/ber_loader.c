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

void	invalid_format(t_map *c)
{
	free (c->line);
	printf("Error: Invalid map format.\n");
	c->fd = -1;
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
			invalid_format(c);
	}
	while (c->current_col < c->len)
	{
		if (c->prev_line[c->current_col] != '1')
			invalid_format(c);
		c->current_col++;
	}
	if (c->e_count != 1 || c->p_count != 1 || c->c_count < 1)
		invalid_format(c);
	return (c->fd);
}

static void	init_vars(t_map *var)
{
	var->e_count = 0;
	var->p_count = 0;
	var->c_count = 0;
	var->e_found = 0;
	var->c_found = 0;
	var->current_line = 0;
	var->current_col = 0;
	var->len = 0;
	var->fd = 0;
}

bool is_valid_path(t_map *c, int row, int col)
{
    if (row < 0 || row >= c->current_line || col < 0 || col >= c->len || 
	c->map_buffer[row][col] == '1' || c->map_buffer[row][col] == '-')
        return false;
    char original = c->map[row][col];
    if (original == 'E')
        c->e_found++;
    else if (original == 'C')
        c->c_found++;
    c->map_buffer[row][col] = '-';
	system("clear");
	ft_printf("\nPathing to exit and all collectibles...\n");
	int i;

	i = 0;
    while (i < c->current_line)
	{
		ft_printf("%s\n", c->map_buffer[i]);
		i++;
	}
	ft_printf("\nExits found = %i/%i\n", c->e_found, c->e_count);
	ft_printf("Collectibles found = %i/%i\n", c->c_found, c->c_count);
    usleep(5000);
    bool result = is_valid_path(c, row - 1, col) ||
                  is_valid_path(c, row + 1, col) ||
                  is_valid_path(c, row, col - 1) ||
                  is_valid_path(c, row, col + 1);
	if (c->e_found == c->e_count && c->c_found == c->c_count)
		return true;
    return result;
}

int check_valid_path(t_map *c, int fd)
{
	if (fd == -1)
		return -1;
    int start_row = -1, start_col = -1;
    for (int i = 0; i < c->current_line; i++)
    {
        for (int j = 0; j < c->len; j++)
        {
            if (c->map[i][j] == 'P')
            {
                start_row = i;
                start_col = j;
                break;
            }
        }
        if (start_row != -1)
            break;
    }
    if (start_row == -1)
        return -1;

    if (!is_valid_path(c, start_row, start_col))
    {
        ft_printf("\n\033[1;31mInvalid Path\033[0m\n\n");
        return -1;
    }
    ft_printf("\n\033[1;32mValid Path\033[0m\n\n");
    return 0;
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
		check_valid_path(&c, c.fd);
		free_elements(&c);
	}
	close(c.fd);
	return (0);
}