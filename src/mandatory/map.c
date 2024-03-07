/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:48:40 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/07 19:06:23 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*map[5] = {	
						"1111111",
						"1000001",
						"1001101",
						"1N00101",
						"1111111"
					};

void	read_map(t_cub3d *cub3d)
{
	cub3d->map = map;
	cub3d->map_y = 5;
	cub3d->map_x = 7;
}

void	render_mini_map(t_cub3d *cub3d)
{
	t_vector	point;
	t_vector	map_point;

	point.y = 0;
	for(size_t y = 0; y < cub3d->map_y; point.y++)
	{
		point.x = 0;
		for(size_t x = 0; x < cub3d->map_x; point.x++)
		{
			map_point.y = point.y * MINI_MAP_TILE_SIZE;
			map_point.x = point.x * MINI_MAP_TILE_SIZE;
			// printf("%c", cub3d->map[y][x]);
			// if (cub3d->map[y][x] == WALL_CHAR)
			// 	mlx_put_pixel(((t_cub3d *)cub3d)->image, (i*MINI_MAP_TILE_SIZE), \
			// 	(j*MINI_MAP_TILE_SIZE), WALL_TILE_COLOR);
			// else if (cub3d->map[y][x] == FLOOR_CHAR)
			// 	mlx_put_pixel(((t_cub3d *)cub3d)->image, (i*MINI_MAP_TILE_SIZE), \
			// 	(j*MINI_MAP_TILE_SIZE), FLOOR_TILE_COLOR);
		}
		printf("\n");
	}
			
}

static uint32_t	get_mini_map_color(t_cub3d *cub3d, t_vector *point)
{
	uint32_t color;

	if (cub3d->map[])
}

