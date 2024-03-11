#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE	16

// libft (includes ft_printf and gnl)
# include "../libft/includes/libft.h"

// mlx
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_map
{
	int	e_count;
	int p_count;
	int c_count;
	int	e_found;
	int	c_found;
	int	start_row;
	int	start_col;
	int current_line;
	int current_col;
	int	len;
	int	fd;
	int	width;
	int	height;
	char	*line;
	char	*prev_line;
	char	**map;
	char	**map_buffer;
	char	check;
} t_map;

typedef struct s_input
{
    int	key_up;
    int key_down;
    int key_left;
    int key_right;
	int	key_esc;
} t_input;

typedef struct s_player
{
    int x;
    int y;
    int direction;
	int	score;
	int	moves;
} t_player;

typedef struct s_enemy
{
    int x;
    int y;
    int direction;
} t_enemy;

typedef	struct s_texture
{
	void	*player[4];
	void	*enemy[4];
	void	*collect;
	void	*exit;
	void	*wall;
	void	*floor;
	int	*px_size;
	int	*px_height;
	int	*px_width;
} t_texture;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_input	*input;
	t_player	*player;
	t_texture	*texture;
	t_map	*map;
}	t_data;

// MiniLibX functions
void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

// Core functions

// create_map.c
void	render_xpm(t_data *data, t_texture *t);
void	draw_map(t_data *data, t_map *c, t_texture *t);
void	map_window(t_data *data, t_map *c, t_texture *t);
void	create_map(t_data *data, t_map *c, t_player *p, int argc, char **argv);

// Utils functions

// mem.c
int on_destroy(t_data *data);
void	mem_alloc(t_map *c);
void    mem_dup(t_map *c);
void    free_elements(t_map *c);

// open_map.c
int	walls_and_components(t_map *c);
int	valid_map_format(t_map *c);
void	read_map(t_map *c);
int	open_map(t_map *c, char *map_name, int ac, char **av);

// validate_path.c
void	invalid_format(t_map *c);
bool is_valid_path(t_map *c, int row, int col);
int	init_player_pos(t_map *c, t_player *p, int row, int col);
bool validate_path(t_map *c, t_player *p, int fd);

// utils.c
void	init_struct_pointers(t_data *data);
int on_keypress(int keysym, t_data *data);
void render_image(t_data *data, void *img_ptr, int x, int y);

#endif