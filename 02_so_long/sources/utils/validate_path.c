#include "../../libft/includes/libft.h"
#include "../includes/so_long.h"

void	invalid_format(t_map *c)
{
	ft_printf("\033[1;31m");
	ft_printf("Error: Invalid map format.\n");
	if (c->fd == -1)
		ft_printf("Map needs to be rectangular, surrounded by Walls(1).\n");
	if (c->fd == -2)
		ft_printf("Unknown map component (%c) found in map.\n", c->check);
	if (c->c_count < 1)
		ft_printf("At least one Collectible(C) required.\n");
	if (c->p_count != 1)
		ft_printf("Only one Player(P) is required.\n");
	if (c->e_count != 1)
		ft_printf("Only one Exit(E) is required.\n");
	ft_printf("\033[0m");
	c->fd = -1;
}

bool is_valid_path(t_map *c, int row, int col)
{
	// int	i;

	// i = 0;
    if (row < 0 || row >= c->current_line || col < 0 || col >= c->len || 
	c->map_buffer[row][col] == '1' || c->map_buffer[row][col] == '-' || 
    c->map_buffer[row][col] == 'N')
        return (false);
    if (c->map[row][col] == 'E')
        c->e_found++;
    else if (c->map[row][col] == 'C')
        c->c_found++;
    c->map_buffer[row][col] = '-';
	// system("clear");
	// ft_printf("\nExits found : %i/%i\n", c->e_found, c->e_count);
	// ft_printf("Collectibles found : %i/%i\n", c->c_found, c->c_count);
    // while (i < c->current_line)
	// {
	// 	ft_printf("%s\n", c->map_buffer[i]);
	// 	i++;
	// }
    // usleep(5000);
    bool result = is_valid_path(c, row - 1, col) ||
                  is_valid_path(c, row + 1, col) ||
                  is_valid_path(c, row, col - 1) ||
                  is_valid_path(c, row, col + 1);
	if (c->e_found == c->e_count && c->c_found == c->c_count)
		return (true);
    return (result);
}

int	init_player_pos(t_map *c, t_player *p, int row, int col)
{
    while (row < c->current_line)
    {
		col = 0;
        while (col < c->len)
        {
            if (c->map[row][col] == 'P')
            {
                p->x = row;
                p->y = col;
                c->start_row = row;
                c->start_col = col;
                return (1);
            }
			col++;
        }
        if (c->start_row != -1)
            break;
		row++;
    }
    if (c->start_row == -1)
	{
        return (0);
	}
	return (1);
}

bool validate_path(t_map *c, t_player *p, int fd)
{
	if (fd == -1)
		return (-1);
	if (!init_player_pos(c, p, 0, 0))
		return (0);
	if (!is_valid_path(c, c->start_row, c->start_col))
	{
		ft_printf("\n\033[1;31mInvalid Path\033[0m\n\n");
		return (false);
	}
    ft_printf("\n\033[1;32mValid Path\033[0m\n\n");
	return (true);
}