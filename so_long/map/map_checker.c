/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:55:52 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/19 14:24:56 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_mapchecker	init_checker(char **map)
{
	t_mapchecker	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_chartable_linecount(map);
	data.b_player = 0;
	data.b_collect = 0;
	data.b_exit = 0;
	data.point.x = 0;
	data.point.y = 0;
	return (data);
}

static int	check(char **map, t_mapchecker *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(map[y][x]))
		return (error("invalid map character"));
	if (!valid_uniquechar(map[y][x], &data->b_player))
		return (error("must be only one player !"));
	if (map[y][x] == 'E')
		data->b_exit += 1;
	if (map[y][x] == 'C')
		data->b_collect = 1;
	return (1);
}

int	valid_map(char **map)
{
	t_mapchecker	data;
	int				valid;

	data = init_checker(map);
	valid = 1;
	while (map[data.point.y])
	{
		if (!valid_border(map, data.size))
			return (error("map must be surrounded by walls !"));
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (check(map, &data) == 0)
				return (0);
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_player || (!data.b_exit || data.b_exit > 1) || !data.b_collect)
		valid = error("there must be one P ,E and at least on Coin !");
	if (valid && !check_path(map))
		valid = 0;
	if (data.point.x > 31 || data.point.y > 16)
		valid = error("kbira lmap asahbi dir chi hel !");
	return (valid);
}

int	valid_file(int ac, char *file)
{
	if (ac == 1)
		return (error("need a map !"));
	if (ac > 2)
		return (error("only one map needed !"));
	if (!ft_strend_cmp(file, ".ber"))
		return (error("a valid map name should end with .ber !"));
	return (1);
}

void	ft_ft1(int *valid, int *y)
{
	*valid = 1;
	*y = 0;
}
