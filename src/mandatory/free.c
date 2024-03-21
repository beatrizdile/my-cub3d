/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/20 21:15:47 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_content(t_cub3d *cub3d)
{
	size_t	i;

	i = 0;
	if (cub3d->map[i])
	{
		while (i < cub3d->num_of_map_lines)
		{
			free(cub3d->map[i]);
			i++;
		}
		free(cub3d->map);
	}
}
