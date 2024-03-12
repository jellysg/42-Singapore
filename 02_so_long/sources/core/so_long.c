#include "../../includes/so_long.h"

int i;

int refresh(t_data *data)
{
	draw_map(data, data->map, data->texture);
	system("clear");
	ft_printf("Frame: %i", i);
	i++;
	usleep(1000000 / FRAME_RATE);
    return (0);
}

int so_long_loop(t_data *data)
{
    while (1)
    {
        mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, data);
        mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &game_destroy, data);
        mlx_loop_hook(data->mlx_ptr, &refresh, data);
        mlx_loop(data->mlx_ptr);
    }
    return (0);
}

int	main(int argc, char **argv)
{
	i = 0;
	t_data	data;
	init_struct_pointers(&data);
	create_map(&data, data.map, data.player, argc, argv);
	free_elements(&data);
	return (0);
}

// int main(void)
// {
//     t_data data;
//     void *bob_ptr;

// 	int s = 32;
//     data.mlx_ptr = mlx_init();
//     if (!data.mlx_ptr)
//         return (1);

//     data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "bob");
//     if (!data.win_ptr)
//     {
//         free(data.mlx_ptr);
//         return (1);
//     }

//     bob_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "/assets/wall.xpm", &s, &s);
    
//     render_image(&data, bob_ptr, 0, 0);

//     // Register key release hook
//     mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

//     // Register destroy hook
//     mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

//     // Loop over the MLX pointer
//     mlx_loop(data.mlx_ptr);

//     return (0);
// }

