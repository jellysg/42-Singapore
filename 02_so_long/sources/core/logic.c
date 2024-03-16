#include "../../includes/so_long.h"

void    check_collect(t_data *data)
{
    if (data->map->map[data->player->y][data->player->x] == 'C')
    {
        data->player->score++;
        ft_printf("%i/%i found\n", data->player->score, data->map->c_count);
    }
    return;
}

void    check_up(t_data *data)
{
    if (data->map->map[data->player->y - 1][data->player->x] == '1')
        return;
    else if (data->map->map[data->player->y - 1][data->player->x] == 'E')
    {
        if (data->player->win == 1)
        {
            ft_printf("Moves: %i\n", data->player->moves++);
            ft_printf("You won!\n");
            game_destroy(data);
        }
        return;
    }
    else
    {
        data->player->y--;
        ft_printf("Moves: %i\n", data->player->moves++);
        check_collect(data);
    }
    return;
}

void    check_down(t_data *data)
{
    if (data->map->map[data->player->y + 1][data->player->x] == '1')
        return;
    else if (data->map->map[data->player->y + 1][data->player->x] == 'E')
    {
        if (data->player->win == 1)
        {
            ft_printf("Moves: %i\n", data->player->moves++);
            ft_printf("You won!\n");
            game_destroy(data);
        }
        return;
    }
    else
    {
        data->player->y++;
        ft_printf("Moves: %i\n", data->player->moves++);
        check_collect(data);
    }
    return;
}

void    check_left(t_data *data)
{
    data->player->facing = 'L';
    if (data->map->map[data->player->y][data->player->x - 1] == '1')
        return;
    else if (data->map->map[data->player->y][data->player->x - 1] == 'E')
    {
        if (data->player->win == 1)
        {
            ft_printf("Moves: %i\n", data->player->moves++);
            ft_printf("You won!\n");
            game_destroy(data);
        }
        return;
    }
    else
    {
        data->player->x--;
        ft_printf("Moves: %i\n", data->player->moves++);
        check_collect(data);
    }
    return;
}

void    check_right(t_data *data)
{
    data->player->facing = 'R';
    if (data->map->map[data->player->y][data->player->x + 1] == '1')
        return;
    else if (data->map->map[data->player->y][data->player->x + 1] == 'E')
    {
        if (data->player->win == 1)
        {
            ft_printf("Moves: %i\n", data->player->moves++);
            ft_printf("You won!\n");
            game_destroy(data);
        }
        return;
    }
    else
    {
        data->player->x++;
        ft_printf("Moves: %i\n", data->player->moves++);
        check_collect(data);
    }
    return;
}