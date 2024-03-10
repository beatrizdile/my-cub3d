/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/10 13:26:35 by bedos-sa         ###   ########.fr       */
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
	t_vector	player;

	player = cub3d->player;

	// we divide by two so we render around our player's coordinates, that way,
	// the player's x and y will be at the center of our square, not in the top left
	for(size_t y = (player.y - MINI_MAP_PLAYER_SIZE/2); y < (player.y + MINI_MAP_PLAYER_SIZE/2); y++)
		for(size_t x = (player.x - MINI_MAP_PLAYER_SIZE/2); x < (player.x + MINI_MAP_PLAYER_SIZE/2); x++)
				mlx_put_pixel(((t_cub3d *)cub3d)->image, x, y, PLAYER_COLOR);
}
