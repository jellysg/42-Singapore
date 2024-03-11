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
	init->map->start_row = -1;
	init->map->start_col = -1;
	init->player->x = 0;
	init->player->y = 0;
}

void render_xpm(t_data *data, t_texture *t)
{
	t->px_size = malloc(sizeof(int));
    *t->px_size = TILE_SIZE;
    t->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall.xpm", t->px_size, t->px_size);
	t->collect = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/collect/coin_anim_f0.xpm", t->px_size, t->px_size);
	t->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/exit/e_close.xpm", t->px_size, t->px_size);
	t->player[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/player/p_idle_r_f0.xpm", t->px_size, t->px_size);
	t->floor = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/floor.xpm", t->px_size, t->px_size);
}

void draw_map(t_data *data, t_map *c, t_texture *t)
{
    int row;
    int col;

    row = 0;
    render_xpm(data, t);
    while (row < c->current_line)
    {
        col = 0;
        while (col < c->len)
        {
            if (c->map[row][col] == '1')
                render_image(data, t->wall, col * TILE_SIZE, row * TILE_SIZE);
			else if (c->map[row][col] == 'C')
				render_image(data, t->collect, col * TILE_SIZE + (TILE_SIZE / 4), row * TILE_SIZE + (TILE_SIZE / 4));
			else if (c->map[row][col] == 'E')
				render_image(data, t->exit, col * TILE_SIZE, row * TILE_SIZE);
			else if (c->map[row][col] == 'P')
				render_image(data, t->player[0], col * TILE_SIZE, (row - 1) * TILE_SIZE);
            col++;
        }
        row++;
    }
}

void	map_window(t_data *data, t_map *c, t_texture *t)
{
	c->width = TILE_SIZE * (c->len);
	c->height = TILE_SIZE * (c->current_line);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, c->width, c->height, "so_long");
	draw_map(data, c, t);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, data);
	mlx_loop(data->mlx_ptr);
	return;
}

void	create_map(t_data *data, t_map *c, t_player *p, int argc, char **argv)
{

	init_vars(data);
	if (open_map(c, argv[1], argc, argv) != -1 && validate_path(c, p, c->fd) == true)
	{
		ft_printf("%c: ", c->map[p->x][p->y]);
		ft_printf("%i, %i\n", p->x, p->y);
		map_window(data, c, data->texture);
	}
	free_elements(c);
	close(c->fd);
}