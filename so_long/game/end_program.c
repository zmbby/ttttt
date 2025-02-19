/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:09:20 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:12:30 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "game.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;

	tilemap = game->tilemap;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free(tilemap);
}

void	free_enemies(t_game *game)
{
	t_enemy	*head;
	t_enemy	*next;

	head = game->enemy_list;
	next = NULL;
	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

void	add_to_garbage(t_game *game, void *img)
{
	t_garbage	*new;
	t_garbage	*temp;

	new = malloc(sizeof(t_garbage));
	if (!new)
		return ;
	new->img = img;
	new->next = NULL;
	if (!game->garbage_head)
	{
		game->garbage_head = new;
		return ;
	}
	temp = game->garbage_head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	*load_xpm(t_game *game, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &game->img_size.x,
			&game->img_size.y);
	if (img)
		add_to_garbage(game, img);
	return (img);
}

int	end_program(t_game *game)
{
	cleanup_images(game);
	free_tilemap(game);
	game->tilemap = NULL;
	free_enemies(game);
	game->enemy_list = NULL;
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
