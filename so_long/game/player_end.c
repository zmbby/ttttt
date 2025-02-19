/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:10:20 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/19 16:25:08 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	kill_player(t_game *game, t_vector pos)
{
	game->player.tile = NULL;
	effect_anim(&game->effect, pos);
	end_game(game, 0);
	end_program(game);
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
	end_game(game, 1);
	end_program(game);
}

void	move_follower(t_game *game)
{
	t_enemy	*current;

	if (game == NULL || game->enemy_list == NULL)
		return ;
	current = game->enemy_list;
	while (current != NULL)
	{
		if (current->type == FOLLOW_ENEM)
			follow_player(current, game);
		current = current->next;
	}
}
