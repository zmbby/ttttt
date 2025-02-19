/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:05:56 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:06:04 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	open_walls_up(t_game *game)
{
	game->wall_imgs.block = load_xpm(game, "sprites/wall_02.xpm");
	game->wall_imgs.up_left = load_xpm(game, "sprites/wall_ul.xpm");
	game->wall_imgs.up = load_xpm(game, "sprites/wall_u.xpm");
	game->wall_imgs.up_right = load_xpm(game, "sprites/wall_ur.xpm");
	game->wall_imgs.right = load_xpm(game, "sprites/wall_r.xpm");
}

void	open_wallimgs_down(t_game *game)
{
	game->wall_imgs.down_right = load_xpm(game, "sprites/wall_dr.xpm");
	game->wall_imgs.down = load_xpm(game, "sprites/wall_d.xpm");
	game->wall_imgs.down_left = load_xpm(game, "sprites/wall_dl.xpm");
	game->wall_imgs.left = load_xpm(game, "sprites/wall_l.xpm");
}

// void    end_game_imgs(t_game *game)
// {
//         game->endgame.win_vec.x = 768;
//         game->endgame.win_vec.y = 432;
//         game->endgame.you_win_img = mlx_xpm_file_to_image(game->mlx,
//                 "sprites/you_win.xpm", &game->endgame.win_vec.x,
// }