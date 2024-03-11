#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data data;
	init_struct_pointers(&data);
	create_map(&data, data.map, data.player, argc, argv);
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

