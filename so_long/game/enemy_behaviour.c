/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behaviour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:08:41 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:11:53 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_enemy_to(t_enemy *enemy, t_tile *tile)
{
	enemy->tile->type = EMPTY;
	if (enemy->type == FOLLOW_ENEM)
		tile->type = FOLLOWER;
	else
		tile->type = ENEMY;
	enemy->tile = tile;
}

int	change_dir(t_enemy *enemy)
{
	if (enemy->dir == 0)
		enemy->dir = 1;
	else
		enemy->dir = 0;
	return (0);
}

int	move_hor(t_enemy *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->left->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->left);
		else if (enemy->tile->left->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->left);
			kill_player(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	else if (enemy->dir == 1)
	{
		if (enemy->tile->right->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->right);
		else if (enemy->tile->right->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->right);
			kill_player(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	return (1);
}

int	move_ver(t_enemy *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->up->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->up);
		else if (enemy->tile->up->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->up);
			kill_player(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	else if (enemy->dir == 1)
	{
		if (enemy->tile->down->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->down);
		else if (enemy->tile->down->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->down);
			kill_player(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	return (1);
}

void	move_enemy(t_game *game)
{
	t_enemy		*current;

	static int (counter) = 0;
	counter++;
	if (counter >= 40)
	{
		if (game == NULL || game->enemy_list == NULL)
			return ;
		current = game->enemy_list;
		while (current != NULL)
		{
			if (current->type == HORIZONTAL_ENEM)
				move_hor(current, game);
			else if (current->type == VERTICAL_ENEM)
				move_ver(current, game);
			else if (current->type == FOLLOW_ENEM)
				follow_player(current, game);
			current = current->next;
		}
		counter = 0;
	}
}
