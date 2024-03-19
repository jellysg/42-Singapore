/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:37:45 by jergoh            #+#    #+#             */
/*   Updated: 2024/03/18 11:37:45 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_elements(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->current_line)
	{
		free(data->map->map[i]);
		free(data->map->map_buffer[i]);
		i++;
	}
	free(data->map->map);
	free(data->map->map_buffer);
	free(data->monster->x);
	free(data->monster->y);
	free(data->monster->facing);
	free(data->map->line);
	free(data->map->prev_line);
}

void	free_game(t_data *data)
{
	free_elements(data);
	free(data->map);
	free(data->player);
	free(data->monster);
	free(data->texture);
}

void	mem_monster(t_data *data)
{
	int	i;

	i = 0;
	data->monster->x = malloc((data->map->m_count) * sizeof(int));
	data->monster->y = malloc((data->map->m_count) * sizeof(int));
	data->monster->facing = malloc((data->map->m_count) * sizeof(char));
	while (i < data->map->m_count)
	{
		data->monster->facing[i] = data->monster->init_facing;
		i++;
	}
}

void	mem_map_buffer(t_map *c)
{
	int	i;

	i = 0;
	c->map_buffer = (char **)malloc((c->current_line + 1) * sizeof(char *));
	while (i < c->current_line)
	{
		c->map_buffer[i] = ft_strdup(c->map[i]);
		i++;
	}
	c->map_buffer[c->current_line] = ft_strdup(c->line);
}

void	mem_alloc(t_map *c)
{
	int	i;

	i = 0;
	if (c->current_line != 0)
	{
		free(c->map[c->current_line - 1]);
		c->map[c->current_line - 1] = ft_strdup(c->prev_line);
	}
	mem_map_buffer(c);
	c->map = (char **)malloc((c->current_line + 1) * sizeof(char *));
	while (i < c->current_line)
	{
		c->map[i] = ft_strdup(c->map_buffer[i]);
		i++;
	}
	c->map[c->current_line] = ft_strdup(c->line);
}
