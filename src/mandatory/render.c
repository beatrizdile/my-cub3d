/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/09 22:52:46 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	render_square(t_cub3d *cub3d, t_vector map_point, uint32_t color)
{
	for(size_t y = map_point.y; y < (map_point.y + MINI_MAP_TILE_SIZE); y++)
		for(size_t x = map_point.x; x < (map_point.x + MINI_MAP_TILE_SIZE); x++)
			mlx_put_pixel(((t_cub3d *)cub3d)->image, x, y, color);
}
