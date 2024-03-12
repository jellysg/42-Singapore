#include "../../includes/so_long.h"

static void	init_vars(t_data *init)
{
	init->map->e_count = 0;
	init->map->p_count = 0;
	init->map->c_count = 0;
	init->map->e_found = 0;
	init->map->c_found = 0;
	init->map->current_line = 0;
	init->map->current_col = 0;
	init->map->len = 0;
	init->map->fd = 0;
	init->map->row = 0;
	init->map->col = 0;
	init->map->start_row = -1;
	init->map->start_col = -1;
	init->player->x = 0;
	init->player->y = 0;
	init->texture->frame = 0;
	init->player->facing = 'L';
}

void	draw_map(t_data *data, t_map *c, t_texture *t)
{
	c->row = 0;
    while (c->row < c->current_line)
    {
        c->col = 0;
        while (c->col < c->len)
        {
            if (c->map[c->row][c->col] == '1')
                render_image(data, t->wall, c);
			else if (c->map[c->row][c->col] == '0')
                render_image(data, t->floor, c);
			else if (c->map[c->row][c->col] == 'E')
				render_image(data, t->exit[0], c);
			else if (c->map[c->row][c->col] == 'C')
				render_image(data, t->collect[t->frame], c);
			else if (c->map[c->row][c->col] == 'P')
			{
				if (data->player->facing == 'L')
					render_image(data, t->playerL[t->frame], c);
				else if (data->player->facing == 'R')
					render_image(data, t->playerR[t->frame], c);
			}
            c->col++;
        }
        c->row++;
    }
}

void	map_window(t_data *data, t_map *c, t_texture *t)
{
	c->width = SIZE * (c->len);
	c->height = SIZE * (c->current_line);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, c->width, c->height, "so_long");
	render_xpm(data, t);
	draw_map(data, c, t);
	return;
}

void	create_map(t_data *data, t_map *c, t_player *p, int argc, char **argv)
{

	init_vars(data);
	if (open_ber(c, argv[1], argc, argv) != -1 && validate_path(c, p, c->fd) == true)
	{
		ft_printf("%c located at: ", c->map[p->y][p->x]);
		ft_printf("%i, %i\n", p->y, p->x);
		map_window(data, c, data->texture);
		so_long_loop(data);
		free(c->line);
    	free(c->prev_line);
	}
	close(c->fd);
}