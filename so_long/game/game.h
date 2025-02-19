/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:08:28 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:08:31 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../map/map.h"
# include "../so_long.h"

/**/
// game function

t_tile	**map_init(int ac, char **av, t_game *game);
int		start(t_game *game, int ac, char **av);
int		end_program(t_game *game);
void	open_image(t_game *game);
void	open_walls_up(t_game *game);
void	color_panel(t_panel *panel, t_color color);
void	*new_panel(t_game *game, t_color color);
t_color	new_color(int r, int g, int b, int a);
void	open_walls_up(t_game *game);
void	open_wallimgs_down(t_game *game);
int		draw_corner(t_tile tile, t_game game, t_vector pos);
void	draw_wall(t_tile tile, t_game game, t_vector pos);
int		update(t_game *game);
void	render(t_game game);
int		input(int key, t_game *game);
void	move_to_empty(t_game *game, t_tile *tile);
void	effect_anim(t_effect *effect, t_vector pos);
void	action_anim(t_player *player);
void	pick_coin(t_game *game, t_tile *tile);
void	remove_player(t_game *game);
void	move_to_exit(t_game *game, t_tile *tile);
void	move_to_enemy(t_game *game, t_tile *tile);
void	kill_player(t_game *game, t_vector pos);
int		move_hor(t_enemy *enemy, t_game *game);
int		move_ver(t_enemy *enemy, t_game *game);
void	follow_player(t_enemy *enemy, t_game *game);
void	move_enemy(t_game *game);
void	move_follower(t_game *game);
void	*load_xpm(t_game *game, char *path);
void	add_to_garbage(t_game *game, void *img);
#endif