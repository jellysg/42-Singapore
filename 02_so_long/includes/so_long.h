#ifndef SO_LONG_H
# define SO_LONG_H

// Tile size (square)
# define SIZE	32

// Frame rate
# define FRAME_RATE	60

// Key input
# define KEY_UP	65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100
# define KEY_ESC	65307

// libft (includes ft_printf and gnl)
# include "../libft/includes/libft.h"

// mlx
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_map
{
	int	e_count;
	int p_count;
	int c_count;
	int	e_found;
	int	c_found;
	int	row;
	int	col;
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

typedef struct s_player
{
    int x;
    int y;
	int	score;
	int	moves;
	char	facing;
} t_player;

typedef	struct s_texture
{
	void	*playerL[4];
	void	*playerR[4];
	void	*collect[4];
	void	*exit[2];
	void	*wall;
	void	*floor;
	int	*px_size;
	int	*px_height;
	int	*px_width;
	int	frame;
} t_texture;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_player	*player;
	t_texture	*texture;
	t_map	*map;
}	t_data;

// MiniLibX functions
void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

// Core functions

// so_long.c
int so_long_loop(t_data *data);
int update(t_data *data);

// map.c
// static void	init_vars(t_data *init);
void	draw_map(t_data *data, t_map *c, t_texture *t);
void	map_window(t_data *data, t_map *c, t_texture *t);
void	create_map(t_data *data, t_map *c, t_player *p, int argc, char **argv);

// Utils functions

// mem.c
int game_destroy(t_data *data);
void	mem_alloc(t_map *c);
void    mem_dup(t_map *c);
void    free_elements(t_data *data);

// open_ber.c
int	walls_and_components(t_map *c);
int	valid_map_format(t_map *c);
void	read_ber(t_map *c);
int	open_ber(t_map *c, char *map_name, int ac, char **av);

// validate_path.c
void	invalid_format(t_map *c);
bool is_valid_path(t_map *c, int row, int col);
int	init_player_pos(t_map *c, t_player *p, int row, int col);
bool validate_path(t_map *c, t_player *p, int fd);

// utils.c
void	init_struct_pointers(t_data *data);
int on_keypress(int keysym, t_data *data);
void    *xpm_i(t_data *d, char *path, t_texture *t);
void	render_xpm(t_data *data, t_texture *t);
void    render_image(t_data *d, void *img_ptr, t_map *c);

#endif