#include "../../includes/so_long.h"

void	init_struct_pointers(t_data *data)
{
    t_input *i;
    t_map   *m;
    t_player    *p;
    t_texture   *t;

	i = malloc(sizeof(t_input));
    m = malloc(sizeof(t_map));
    p = malloc(sizeof(t_player));
    t = malloc(sizeof(t_texture));

	data->input = i;
	data->map = m;
    data->player = p;
    data->texture = t;
	return;
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

void render_image(t_data *data, void *img_ptr, int x, int y)
{
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x, y);
}
