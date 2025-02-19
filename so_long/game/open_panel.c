/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:15:23 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/19 16:02:20 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

void	color_panel(t_panel *panel, t_color color)
{
	int	x;
	int	y;

	panel->pixels = mlx_get_data_addr(panel->pointer, &panel->bpp,
			&panel->line_size, &panel->endian);
	y = 0;
	while (y < panel->size.y)
	{
		x = 0;
		while (x < panel->size.x)
		{
			panel->pixels[(x * 4 + panel->line_size * y) + 0] = color.b;
			panel->pixels[(x * 4 + panel->line_size * y) + 0] = color.g;
			panel->pixels[(x * 4 + panel->line_size * y) + 0] = color.r;
			panel->pixels[(x * 4 + panel->line_size * y) + 0] = color.a;
			x++;
		}
		y++;
	}
}

void	*new_panel(t_game *game, t_color color)
{
	t_panel		panel;

	panel.pointer = mlx_new_image(game->mlx, game->win_size.x,
			game->win_size.y);
	panel.size.x = game->win_size.x;
	panel.size.y = game->win_size.y;
	color_panel(&panel, color);
	add_to_garbage(game, panel.pointer);
	return (panel.pointer);
}
