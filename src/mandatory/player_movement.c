/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/22 21:10:57 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	walking_into_wall(t_cub3d *cub3d, int x_signal, int y_signal)
{
	t_vector	index;
	bool		wall_in_front;

	wall_in_front = false;
	index.x = ((cub3d->player.x) / MINI_MAP_TILE_SIZE);
	index.y = ((cub3d->player.y) / MINI_MAP_TILE_SIZE);

	if (x_signal == 0 && y_signal == -1)
		index.y = ((cub3d->player.y - PLAYER_SPEED) / MINI_MAP_TILE_SIZE);
	else if (x_signal == 0 && y_signal == 1)
		index.y = ((cub3d->player.y + PLAYER_SPEED) / MINI_MAP_TILE_SIZE);
	else if (x_signal == -1 && y_signal == 0)
		index.x = ((cub3d->player.x - PLAYER_SPEED) / MINI_MAP_TILE_SIZE);
	else if (x_signal == 1 && y_signal == 0)
		index.x = ((cub3d->player.x + PLAYER_SPEED) / MINI_MAP_TILE_SIZE);

	if (cub3d->map[(int)index.y][(int)index.x] == '1')
		wall_in_front = true;
	return (wall_in_front);
}

void	move_player(t_cub3d *cub3d, int x_signal, int y_signal)
{
	if (!walking_into_wall(cub3d, x_signal, y_signal))
	{
		if (x_signal == 0 && y_signal == -1) // moving player up
			cub3d->player.y = cub3d->player.y - PLAYER_SPEED;
		else if (x_signal == 0 && y_signal == 1) // moving player down
			cub3d->player.y = cub3d->player.y + PLAYER_SPEED;
		else if (x_signal == -1 && y_signal == 0) // moving player left
			cub3d->player.x = cub3d->player.x - PLAYER_SPEED;
		else if (x_signal == 1 && y_signal == 0) // moving player right
			cub3d->player.x = cub3d->player.x + PLAYER_SPEED;
	}
}
