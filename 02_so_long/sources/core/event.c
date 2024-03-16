#include "../../includes/so_long.h"

int refresh(t_data *data)
{
	if (data->player->score == data->map->c_count)
    {
        data->player->win = 1;
        ft_printf("Door is open\n");
    }
	draw_map(data, data->map, data->texture);
    data->texture->keyframe = (data->texture->keyframe + 1) % 4;
    if (data->texture->keyframe == 3)
    {
        data->texture->frame = (data->texture->frame + 1) % 4;
    }
	usleep(1000000 / FRAME_RATE);
    return (0);
}

void    key_event(int keysym, t_data *data)
{
    if (keysym == KEY_ESC)
        game_destroy(data);
    else if (keysym == KEY_W || keysym == KEY_UP)
        move_up(data);
    else if (keysym == KEY_S || keysym == KEY_DOWN)
        move_down(data);
    else if (keysym == KEY_A || keysym == KEY_LEFT)
        move_left(data);
    else if (keysym == KEY_D || keysym == KEY_RIGHT)
        move_right(data);
    else
        return;
}