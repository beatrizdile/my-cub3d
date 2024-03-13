/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:48:40 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/13 19:58:45 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static char	*map[8] = {	
						"111111111",
						"100000001",
						"101000111",
						"111001101",
						"100000101",
						"1010N0101",
						"100000001",
						"111111111"
					};

static t_vector	get_player_position(t_cub3d *cub3d)
{
	t_vector	point;

	for(size_t y = 0; y < cub3d->map_y; y++)
	{
		for(size_t x = 0; x < cub3d->map_x; x++)
		{
			if (cub3d->map[y][x] == 'N')
			{
				point.x = x;
				point.y = y;
			}
		}
	}
	return (point);
}

void	read_map(t_cub3d *cub3d)
{
	cub3d->map = map;
	cub3d->map_y = 8;
	cub3d->map_x = 9;
	cub3d->player = get_player_position(cub3d);
	cub3d->player.x = (cub3d->player.x * MINI_MAP_TILE_SIZE) + (MINI_MAP_TILE_SIZE / 2);
	cub3d->player.y = (cub3d->player.y * MINI_MAP_TILE_SIZE) + (MINI_MAP_TILE_SIZE / 2);
}

static uint32_t	get_mini_map_color(t_cub3d *cub3d, t_vector *point)
{
	uint32_t color;
	int y = point->y;
	int x = point->x;

	color = 0;
	if (cub3d->map[y][x] == '1')
		color = WALL_TILE_COLOR;
	else if (cub3d->map[y][x] == '0' || cub3d->map[y][x] == 'N')
		color = FLOOR_TILE_COLOR;
	return (color);
}

void	render_mini_map(t_cub3d *cub3d)
{
	t_vector	point;
	t_vector	map_point;

	for(point.y = 0; point.y < cub3d->map_y; point.y++)
	{
		for(point.x = 0; point.x < cub3d->map_x; point.x++)
		{
			map_point.y = point.y * MINI_MAP_TILE_SIZE;
			map_point.x = point.x * MINI_MAP_TILE_SIZE;
			render_square(cub3d, map_point, MINI_MAP_TILE_SIZE, \
							get_mini_map_color(cub3d, &point));
		}
	}
}
