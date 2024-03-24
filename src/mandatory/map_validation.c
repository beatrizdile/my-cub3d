/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/23 23:29:09 by bedos-sa         ###   ########.fr       */
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

	if (map_size_without_empty_lines(cub3d) != 0)
		new_map = calloc(map_size_without_empty_lines(cub3d), sizeof(char *));
	else
	{
		free_map_content(cub3d);
		err_exit(ERR_INVALID_EMPTY_FILE);
	}

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
	// char	**splited_line;

	delete_empty_lines(cub3d);
	for (int i = 0; i < (int)cub3d->num_of_map_lines; i++)
	{
		printf("%s", cub3d->map[i]);
		// splited_line = ft_split(cub3d->map[i], ' ');
		// if (splited_line[0])
		// printf("%s\n", splited_line[0]);
		// ft_free_split(splited_line);
	}
}

// CHECKS FOR VALID MAP
// TODO: delete empty lines
// TODO: check if lines are in the correct format (NO ./path)
// TODO: check if the path is valid
