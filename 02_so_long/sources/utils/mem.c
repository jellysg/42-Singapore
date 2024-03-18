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
	data->map->map = NULL;
	data->map->map_buffer = NULL;
	free(data->monster->x);
	free(data->monster->y);
	free(data->monster->facing);
	data->monster->x = NULL;
	data->monster->y = NULL;
	data->monster->facing = NULL;
}

void	free_game(t_data *data)
{
	free_elements(data);
	if (data->map != NULL)
	{
		free(data->map);
		data->map = NULL;
	}
	if (data->player != NULL)
	{
		free(data->player);
		data->player = NULL;
	}
	if (data->monster != NULL)
	{
		free(data->monster);
		data->monster = NULL;
	}
	if (data->texture != NULL)
	{
		free(data->texture);
		data->texture = NULL;
	}
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

void	mem_dup(t_map *c)
{
	int	count;

	count = 0;
	if (c->current_line != 0)
		c->map[c->current_line - 1] = ft_strdup(c->prev_line);
	if (!c->map_buffer)
		return ;
	while (count < c->current_line)
	{
		c->map_buffer[count] = ft_strdup(c->map[count]);
		count++;
	}
}

void	mem_alloc(t_map *c)
{
	int	i;

	i = 0;
	c->map_buffer = (char **)malloc((c->current_line + 1) * sizeof(char *));
	mem_dup(c);
	c->map = (char **)malloc((c->current_line + 1) * sizeof(char *));
	while (i < c->current_line)
	{
		c->map[i] = ft_strdup(c->map_buffer[i]);
		i++;
	}
	c->map[c->current_line] = ft_strdup(c->line);
	c->map_buffer[c->current_line] = ft_strdup(c->line);
}
