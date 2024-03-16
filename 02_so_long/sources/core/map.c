#include "../../includes/so_long.h"

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
				render_image(data, t->exit[data->player->win], c);
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
	char	*msg;
	char	*moves;
	moves = ft_itoa(data->player->moves);
	msg = ft_strjoin("Moves: ", moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, c->width / 2, c->height - c->current_line, 11001101, msg);
	free(msg);
	free(moves);
}

void	map_window(t_data *data, t_map *c, t_texture *t)
{
	c->width = SIZE * (c->len);
	c->height = SIZE * c->current_line;
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
		map_window(data, c, data->texture);
		game_loop(data);
		free(c->line);
    	free(c->prev_line);
	}
	close(c->fd);
}