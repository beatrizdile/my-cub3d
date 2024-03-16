/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_rendering.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:48:40 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/16 10:56:06 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_tiles_color_mini_map(t_cub3d *cub3d, t_vector *point)
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
							get_tiles_color_mini_map(cub3d, &point));
		}
	}
}
