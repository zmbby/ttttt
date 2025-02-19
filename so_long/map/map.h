/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:57:21 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/19 16:32:42 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../basics.h"
# include "../so_long.h"

typedef struct s_tile	t_tile;
typedef struct s_game	t_game;

typedef struct s_mapchecker
{
	t_vector			size;
	t_vector			point;
	int					b_player;
	int					b_exit;
	int					b_collect;
}						t_mapchecker;
typedef struct s_fff
{
	char				**map;
	char				*line;
	int					fd;
	int					i;
	int					check;
}						t_fff;

// map functions
int						valid_file(int ac, char *file);
char					**read_map(char *file);
int						valid_char(char c);
int						valid_uniquechar(char c, int *b_player);
int						valid_map(char **map);
t_tile					**alloc_tilemap(char **map);

t_tile					**generate_tilemap(char **map, t_game *game);
int						valid_border(char **map, t_vector size);
void					ft_ft1(int *valid, int *y);
int						ft1(char c);

/**/
// enemy
t_enemy					*new_enemy(t_enemytype type, t_tile *tile);
t_enemy					*last_enemy(t_enemy *list);
void					add_enemy(t_game *game, t_enemytype type, t_tile *tile);
int						check_path(char **map);
#endif