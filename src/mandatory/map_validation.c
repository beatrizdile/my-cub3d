/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/23 22:48:25 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	get_texture_ceiling_and_floor()
// {
	
// }

static size_t	map_size_without_empty_lines(t_cub3d *cub3d)
{
	size_t	num;

	num = 0;
	for (int i = 0; i < (int)cub3d->num_of_map_lines; i++)
	{
		if (!(cub3d->map[i][0] == '\n'))
			num++;
	}
	return (num);
}

static void	delete_empty_lines(t_cub3d *cub3d)
{	
	int		index;
	char	**new_map;

	new_map = calloc(map_size_without_empty_lines(cub3d), sizeof(char *));
	index = 0;
	for (int i = 0; i < (int)cub3d->num_of_map_lines; i++)
	{
		if (!(cub3d->map[i][0] == '\n'))
		{
			new_map[index] = strdup(cub3d->map[i]);
			index++;
		}
	}
	free_map_content(cub3d);
	cub3d->map = new_map;
	cub3d->num_of_map_lines = index;
}

void	check_valid_map(t_cub3d *cub3d)
{
	delete_empty_lines(cub3d);
	for (int i = 0; i < (int)cub3d->num_of_map_lines; i++)
	{
		printf("i: %d | %s", i, cub3d->map[i]);
	}
}
