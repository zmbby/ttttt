/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:57:32 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/19 14:26:11 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_enemy	*new_enemy(t_enemytype type, t_tile *tile)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		return (null_error("malloc fails ! ps: new_enemy()"));
	enemy->type = type;
	enemy->dir = 0;
	enemy->tile = tile;
	enemy->next = NULL;
	return (enemy);
}

t_enemy	*last_enemy(t_enemy *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	add_enemy(t_game *game, t_enemytype type, t_tile *tile)
{
	t_enemy	*new;

	new = new_enemy(type, tile);
	if (!new)
		return ;
	if (!game->enemy_list)
		game->enemy_list = new;
	else
		last_enemy(game->enemy_list)->next = new;
}
