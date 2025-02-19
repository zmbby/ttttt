/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:06:19 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:06:26 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "game.h"

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = load_xpm(game, "sprites/player_01.xpm");
	game->player.idle_img_1 = load_xpm(game, "sprites/player_02.xpm");
	game->player.action_img = load_xpm(game, "sprites/player_03.xpm");
	game->player.current_img = game->player.action_img;
}

static void	open_collect_imgs(t_game *game)
{
	game->collects_imgs.img_0 = load_xpm(game, "sprites/plant_03.xpm");
	game->collects_imgs.img_1 = load_xpm(game, "sprites/plant_04.xpm");
	game->collects_imgs.current_img = game->collects_imgs.img_0;
	game->effect.img = load_xpm(game, "sprites/effect_w.xpm");
}

static void	open_enemy_imgs(t_game *game)
{
	game->enemy_imgs.basic_01 = load_xpm(game, "sprites/enemy_01.xpm");
	game->enemy_imgs.basic_02 = load_xpm(game, "sprites/enemy_02.xpm");
	game->enemy_imgs.basic_current = game->enemy_imgs.basic_01;
	game->enemy_imgs.follow_01 = load_xpm(game, "sprites/enemy_03.xpm");
	game->enemy_imgs.follow_02 = load_xpm(game, "sprites/enemy_04.xpm");
	game->enemy_imgs.follow_current = game->enemy_imgs.follow_01;
}

static void	open_door_imgs(t_game *game)
{
	game->door_open_img = load_xpm(game, "sprites/door_01.xpm");
	game->door_close_img = load_xpm(game, "sprites/door_02.xpm");
}

void	open_image(t_game *game)
{
	open_walls_up(game);
	open_wallimgs_down(game);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_enemy_imgs(game);
	open_door_imgs(game);
}
