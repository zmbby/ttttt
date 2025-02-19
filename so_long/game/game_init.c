/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:16:11 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/19 16:25:02 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map/map.h"
#include "../so_long.h"
#include "game.h"

t_tile	**map_init(int ac, char **av, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (!valid_file(ac, av[1]))
		return (NULL);
	map = read_map(av[1]);
	if (!map)
		return (NULL);
	if (!valid_map(map))
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	ft_free_chartable(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

static void	anim_setup(t_game *game)
{
	game->player.idle_frames = 17;
	game->player.action_frames = 10;
	game->collects_imgs.anim_frames = 25;
	game->effect.frames = 7;
	game->enemy_imgs.basic_anim = 16;
	game->enemy_imgs.follow_anim = 6;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("mlx failed !");
	game->win = mlx_new_window(game->mlx, game->win_size.x, game->win_size.y,
			"so_long hbek !");
	if (!game->win)
		error("open a windows failed !");
	mlx_hook(game->win, 17, 0, end_program, game);
	open_image(game);
}

int	start(t_game *game, int ac, char **av)
{
	game->tilemap = map_init(ac, av, game);
	if (!game->tilemap)
		return (0);
	anim_setup(game);
	game_init(game);
	return (1);
}
