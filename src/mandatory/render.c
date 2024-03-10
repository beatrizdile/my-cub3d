/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/10 02:30:53 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	render_square(t_cub3d *cub3d, t_vector map_point, size_t size, uint32_t color)
{
	for(size_t y = map_point.y; y < (map_point.y + size); y++)
	{
		for(size_t x = map_point.x; x < (map_point.x + size); x++)
		{
			if (y >= (map_point.y + size - 2) || x >= (map_point.x + size - 2))
				mlx_put_pixel(((t_cub3d *)cub3d)->image, x, y, GRID_TILE_COLOR);
			else
				mlx_put_pixel(((t_cub3d *)cub3d)->image, x, y, color);
		}
	}
}

void	render_player(t_cub3d *cub3d)
{
	t_vector	point;

	point = get_player_position(cub3d);
	point.x = point.x * MINI_MAP_TILE_SIZE;
	point.y = point.y * MINI_MAP_TILE_SIZE;

	for(size_t y = point.y; y < (point.y + MINI_MAP_PLAYER_SIZE); y++)
		for(size_t x = point.x; x < (point.x + MINI_MAP_PLAYER_SIZE); x++)
				mlx_put_pixel(((t_cub3d *)cub3d)->image, x, y, PLAYER_COLOR);
}
