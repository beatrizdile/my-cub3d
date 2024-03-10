/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/10 02:20:45 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	get_player_position(t_cub3d *cub3d)
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
