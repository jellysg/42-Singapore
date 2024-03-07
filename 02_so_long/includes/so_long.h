#ifndef SO_LONG_H
# define SO_LONG_H

// libft (includes ft_printf and gnl)
# include "../libft/includes/libft.h"

// mlx
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_map {
	int e_count;
	int p_count;
	int c_count;
	int	e_found;
	int	c_found;
	int current_line;
	int current_col;
	int	len;
	int	fd;
	char	*line;
	char	*prev_line;
	char	**map;
	char	**map_buffer;
} t_map;

typedef struct s_input {
    int key_up;
    int key_down;
    int key_left;
    int key_right;
} t_input;

typedef struct s_player {
    int x;
    int y;
    int direction;
	int	score;
} t_player;

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;

void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
void	mem_alloc(t_map *c);
void    free_elements(t_map *c);

#endif