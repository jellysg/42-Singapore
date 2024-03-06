#include "../../includes/so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

void render_image(t_data *data, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x, y);
}

int main(void)
{
	t_data data;
	void *bob_ptr;
	int width = 16;
	int height = 16;
 
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "bob");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	bob_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/bob.xpm", &width, &height);
	render_image(&data, bob_ptr, 0, 0);

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
 
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
