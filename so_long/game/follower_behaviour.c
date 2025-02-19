/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follower_behaviour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:16:27 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 18:00:04 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	define_dir(int value)
{
	if (value < 0)
		return (1);
	else if (value > 0)
		return (0);
	return (-1);
}

void	follow_player(t_enemy *enemy, t_game *game)
{
	int		dis_x;
	int		dis_y;

	if (game->player.tile == NULL)
		return ;
	dis_x = enemy->tile->position.x - game->player.tile->position.x;
	dis_y = enemy->tile->position.y - game->player.tile->position.y;
	if (dis_x > dis_y)
	{
		enemy->dir = define_dir(dis_x);
		if (!move_hor(enemy, game) || enemy->dir == -1)
		{
			enemy->dir = define_dir(dis_y);
			move_ver(enemy, game);
		}
	}
	else
	{
		enemy->dir = define_dir(dis_y);
		if (!move_ver(enemy, game) || enemy->dir == -1)
		{
			enemy->dir = define_dir(dis_x);
			move_hor(enemy, game);
		}
	}
}
