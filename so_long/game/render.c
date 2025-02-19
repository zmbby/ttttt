/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:46 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/19 15:58:12 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	draw_image(t_tile tile, t_game game, t_vector pos)
{
	if (tile.type == WALL)
		draw_wall(tile, game, pos);
	else if (tile.type == EXIT)
	{
		if (game.collects)
			mlx_put_image_to_window(game.mlx, game.win, game.door_open_img,
				pos.x, pos.y);
		if (game.collects == 0)
			mlx_put_image_to_window(game.mlx, game.win, game.door_close_img,
				pos.x, pos.y);
	}
	else if (tile.type == COIN)
		mlx_put_image_to_window(game.mlx, game.win,
			game.collects_imgs.current_img, pos.x, pos.y);
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(game.mlx, game.win, game.player.current_img,
			pos.x, pos.y);
	else if (tile.type == ENEMY)
		mlx_put_image_to_window(game.mlx, game.win,
			game.enemy_imgs.basic_current, pos.x, pos.y);
	else if (tile.type == FOLLOWER)
		mlx_put_image_to_window(game.mlx, game.win,
			game.enemy_imgs.follow_current, pos.x, pos.y);
}

static void	draw_effect(t_game game)
{
	if (game.effect.counter < game.effect.frames)
		mlx_put_image_to_window(game.mlx, game.win, game.effect.img,
			game.effect.pos.x, game.effect.pos.y);
}

static void	draw_text(t_game game)
{
	char	*str;

	str = ft_itoa(game.moves);
	if (!str)
		return ;
	if (game.collects >= 0)
		mlx_string_put(game.mlx, game.win, game.win_size.x - IMG_SIZE / 2.3,
			IMG_SIZE - IMG_SIZE / 1.5, -1, str);
	free(str);
}

void	render(t_game game)
{
	t_tile	tile;
	int		x;
	int		y;

	mlx_clear_window(game.mlx, game.win);
	y = 0;
	while (game.tilemap[y])
	{
		x = 0;
		while (game.tilemap[y][x].type)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position);
			draw_effect(game);
			x++;
		}
		y++;
	}
	draw_text(game);
}
