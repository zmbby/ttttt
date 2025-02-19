/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:17:03 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:17:29 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	draw_corner(t_tile tile, t_game game, t_vector pos)
{
	if (tile.position.x == 0 && tile.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.win, game.wall_imgs.up_left,
			pos.x, pos.y);
	else if (tile.position.x == 0 && tile.position.y == game.win_size.y
		- IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.win, game.wall_imgs.down_left,
			pos.x, pos.y);
	else if (tile.position.x == game.win_size.x - IMG_SIZE
		&& tile.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.win, game.wall_imgs.up_right,
			pos.x, pos.y);
	else if (tile.position.x == game.win_size.x - IMG_SIZE
		&& tile.position.y == game.win_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.win, game.wall_imgs.down_right,
			pos.x, pos.y);
	else
		return (0);
	return (1);
}

int	draw_sides(t_tile tile, t_game game, t_vector pos)
{
	if (tile.position.x == 0)
		mlx_put_image_to_window(game.mlx, game.win, game.wall_imgs.left, pos.x,
			pos.y);
	else if (tile.position.x == game.win_size.x - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.win, game.wall_imgs.right, pos.x,
			pos.y);
	else if (tile.position.y == game.win_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.win, game.wall_imgs.down, pos.x,
			pos.y);
	else
		return (0);
	return (1);
}

void	draw_wall(t_tile tile, t_game game, t_vector pos)
{
	if (draw_corner(tile, game, pos))
		return ;
	else if (draw_sides(tile, game, pos))
		return ;
	mlx_put_image_to_window(game.mlx, game.win, game.wall_imgs.block, pos.x,
		pos.y);
}
