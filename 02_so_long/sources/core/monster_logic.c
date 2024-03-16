#include "../../includes/so_long.h"

void    monster_logic(t_data *data, t_monster *mon)
{
    if (data->map->m_count > 0)
    {
        mon->x = malloc((data->map->m_count) * sizeof(int));
        mon->y = malloc((data->map->m_count) * sizeof(int));

        int row;
        int col;
        int num;
    
        num = 0;
        row = 0;
        while (row < data->map->current_line && num < data->map->m_count)
        {
            col = 0;
            while (col < data->map->len)
            {
                if (data->map->map[row][col] == 'M')
                {
                    mon->y[num] = row;
                    mon->x[num] = col;
                    num++;
                }
                col++;
            }
            row++;
        }
    }
    mon->idle_time = (mon->idle_time + 1) % 42;
    if (mon->idle_time == 0)
    {
        {
            if (mon->facing == 'L')
            {
                if (data->map->map[mon->y[1]][mon->x[1] - 1] == '1')
                    return;
                else if (data->map->map[mon->y[1]][mon->x[1] - 1] == 'E')
                {
                    if (data->player->win == 1)
                    {
                        ft_printf("You won!\n");
                        game_destroy(data);
                    }
                    return;
                }
                else
                {
                    mon->x--;
                }
    return;
            }
            else if (mon->facing == 'R')
            {
                if (data->map->map[mon->y[1]][mon->x[1] + 1] == '1')
                    return;
                else if (data->map->map[mon->y[1]][mon->x[1] + 1] == 'E')
                {
                    if (data->player->win == 1)
                    {
                        ft_printf("You won!\n");
                        game_destroy(data);
                    }
                    return;
                }
                else
                {
                    mon->x++;
                }
            }
        }
    }
}