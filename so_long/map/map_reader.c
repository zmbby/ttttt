/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:17 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/19 16:32:28 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "map.h"

static int	file_linecount(char *file)
{
	int		lncount;
	int		fd;
	int		rdcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	lncount = 1;
	while (1)
	{
		rdcount = read(fd, &c, 1);
		if (rdcount == 0)
			break ;
		if (rdcount < 0)
			return (-1);
		if (c == '\n')
			lncount++;
	}
	close(fd);
	return (lncount);
}

static char	**alloc_columns(char *file)
{
	char	**map;
	int		line_count;

	line_count = file_linecount(file);
	if (line_count <= 0)
		return (null_error("open or reading error, the file may not exist !"));
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (null_error("malloc faild ! ps: on alloc_map()"));
	return (map);
}

char	**read_map(char *file)
{
	t_fff (c) = {0};
	c.map = alloc_columns(file);
	if (!c.map)
		return (NULL);
	c.fd = open(file, O_RDONLY);
	c.i = 0;
	c.check = 0;
	while (1)
	{
		c.line = get_next_line(c.fd);
		if (c.line == NULL)
			break ;
		if (*c.line == '\n')
			c.check = 1;
		c.map[c.i] = c.line;
		c.i++;
	}
	c.map[c.i] = NULL;
	close(c.fd);
	if (c.check)
	{
		ft_free_chartable(c.map);
		return (null_error("parsing map failed !"));
	}
	return (c.map);
}
