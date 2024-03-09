/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/09 19:04:34 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	render_square(t_cub3d *cub3d, t_vector map_point, uint32_t color)
{
	for(size_t i = map_point.y; i < (map_point.y + MINI_MAP_TILE_SIZE); i++)
		for(size_t j = map_point.x; j < (map_point.x + MINI_MAP_TILE_SIZE); j++)
			mlx_put_pixel(((t_cub3d *)cub3d)->image, j, i, color);
	
}
