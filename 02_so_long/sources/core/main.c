/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:14:26 by jergoh            #+#    #+#             */
/*   Updated: 2024/03/18 11:14:29 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_end(t_data *data, int i)
{
	if (i == 1)
	{
		ft_printf("You won!\n");
		game_destroy(data);
	}
	else if (i == 0)
	{
		ft_printf("You lost!\n");
		game_destroy(data);
	}
	else if (i == -1)
	{
		ft_printf("Game ended.\n");
		game_destroy(data);
	}
}

int	game_loop(t_data *data)
{
	while (1)
	{
		mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &on_keypress, data);
		mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
			&game_destroy, data);
		mlx_loop_hook(data->mlx_ptr, &refresh, data);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_struct_pointers(&data);
	create_map(&data, argc, argv);
	game_end(&data, -1);
	return (0);
}
