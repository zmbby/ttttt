/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:15:12 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 17:35:20 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_tile	**alloc_tilemap(char **map)
{
	t_tile	**tilemap;
	int		i;

	tilemap = malloc(sizeof(t_tile *) * (ft_chartable_linecount(map) + 1));
	if (tilemap == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		tilemap[i] = malloc(sizeof(t_tile) * (ft_strlen(*map) + 1));
		if (tilemap == NULL)
		{
			while (i > 0)
				free(tilemap[i--]);
			return (NULL);
		}
		i++;
	}
	tilemap[i] = NULL;
	return (tilemap);
}

t_tiletype	define_tiletype(char definer)
{
	if (definer == '1')
		return (WALL);
	if (definer == 'C')
		return (COIN);
	if (definer == 'P')
		return (PLAYER);
	if (definer == 'E')
		return (EXIT);
	if (definer == 'H' || definer == 'V')
		return (ENEMY);
	else if (definer == 'F')
		return (FOLLOWER);
	return (EMPTY);
}

void	setup_tile(t_tile **tilemap, int x, int y)
{
	tilemap[y][x].position.x = x * IMG_SIZE;
	tilemap[y][x].position.y = y * IMG_SIZE;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (tilemap[y + 1] != NULL)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

void	set_gamevars(t_tile *tile, t_game *game, char c)
{
	if (tile->type == PLAYER)
		game->player.tile = tile;
	else if (tile->type == COIN)
		game->collects++;
	else if (tile->type == ENEMY || tile->type == FOLLOWER)
		add_enemy(game, c, tile);
}

t_tile	**generate_tilemap(char **map, t_game *game)
{
	t_tile	**tilemap;

	t_vector (pos) = {0};
	tilemap = alloc_tilemap(map);
	if (!tilemap)
		return (null_error("malloc faild ! ps : alloc_tilemap() !"));
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x] != '\0')
		{
			tilemap[pos.y][pos.x].type = define_tiletype(map[pos.y][pos.x]);
			setup_tile(tilemap, pos.x, pos.y);
			set_gamevars(&tilemap[pos.y][pos.x], game, map[pos.y][pos.x]);
			pos.x++;
		}
		tilemap[pos.y][pos.x].type = 0;
		pos.y++;
	}
	tilemap[pos.y] = NULL;
	game->win_size.x = pos.x * IMG_SIZE;
	game->win_size.y = pos.y * IMG_SIZE;
	return (tilemap);
}
