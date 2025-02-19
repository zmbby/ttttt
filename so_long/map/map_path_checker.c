/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_cer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:00:31 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:44:13 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	**copy_map(char **map, t_vector size)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (size.y + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < size.y)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
				free(map_copy[--i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	flood_fill(char **map, int x, int y, t_vector size)
{
	if (map[y][x] == 'E')
		map[y][x] = '1';
	if (x < 0 || y < 0 || x >= size.x - 1 || y >= size.y || map[y][x] == '1'
		|| map[y][x] == 'G')
		return ;
	map[y][x] = 'G';
	flood_fill(map, x + 1, y, size);
	flood_fill(map, x - 1, y, size);
	flood_fill(map, x, y + 1, size);
	flood_fill(map, x, y - 1, size);
}

static t_vector	find_player(char **map)
{
	t_vector	pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'P')
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

int	ft_ft(int valid, char **map_copy, t_vector tmp)
{
	while (map_copy[tmp.y])
		free(map_copy[tmp.y++]);
	free(map_copy);
	if (!valid)
		return (error("Not all collectibles or exit are reachable"));
	return (1);
}

int	check_path(char **map)
{
	t_check_path	c;

	c.size.x = ft_strlen(map[0]);
	c.size.y = ft_chartable_linecount(map);
	c.map_copy = copy_map(map, c.size);
	if (!c.map_copy)
		return (error("Memory allocation failed"));
	c.player_pos = find_player(c.map_copy);
	if (c.player_pos.x == -1)
		return (error("Player position not found"));
	flood_fill(c.map_copy, c.player_pos.x, c.player_pos.y, c.size);
	ft_ft1(&c.valid, &c.tmp.y);
	while (c.map_copy[c.tmp.y] && c.valid)
	{
		c.tmp.x = 0;
		while (c.map_copy[c.tmp.y][c.tmp.x] && c.valid)
		{
			if (ft1(c.map_copy[c.tmp.y][c.tmp.x]))
				c.valid = 0;
			c.tmp.x++;
		}
		c.tmp.y++;
	}
	c.tmp.y = 0;
	return (ft_ft(c.valid, c.map_copy, c.tmp));
}
