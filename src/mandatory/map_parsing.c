/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/22 19:17:58 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static char	*map[8] = {	
						"111111111",
						"100000001",
						"101000111",
						"111001101",
						"100000101",
						"1010N0101",
						"100000001",
						"111111111"
					};


static t_vector	get_player_position(t_cub3d *cub3d)
{
	t_vector	point;

	for(size_t y = 0; y < cub3d->map_y; y++)
	{
		for(size_t x = 0; x < cub3d->map_x; x++)
		{
			if (cub3d->map[y][x] == 'N' || cub3d->map[y][x] == 'S' || \
					cub3d->map[y][x] == 'W' || cub3d->map[y][x] == 'E')
			{
				point.x = x;
				point.y = y;
			}
		}
	}
	return (point);
}

void	read_map(t_cub3d *cub3d)
{
	cub3d->map = map;
	cub3d->map_y = 8;
	cub3d->map_x = 9;
	cub3d->player = get_player_position(cub3d);
	cub3d->player.x = (cub3d->player.x * MINI_MAP_TILE_SIZE) + (MINI_MAP_TILE_SIZE / 2);
	cub3d->player.y = (cub3d->player.y * MINI_MAP_TILE_SIZE) + (MINI_MAP_TILE_SIZE / 2);
}

static size_t	get_file_size(char *map_file)
{
	char	*line;
	int		fd;
	size_t	num_of_map_lines;

	num_of_map_lines = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		err_exit(ERR_INVALID_MAP_FILE);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		num_of_map_lines++;
		free(line);
	}
	close(fd);
	return (num_of_map_lines);
}

bool	valid_map_file_name(char *argv)
{
	size_t	filename_size;
	size_t	extension_size;

	filename_size = ft_strlen(argv);
	extension_size = ft_strlen(FILE_EXTENSION);
	if (filename_size < extension_size)
		err_exit(ERR_INVALID_FILE_NAME);
	while (extension_size--)
	{
		if (argv[--filename_size] != FILE_EXTENSION[extension_size])
			return (false);
	}
	return (true);
}

void	store_map_content(t_cub3d *cub3d)
{
	int		fd;

	fd = open(cub3d->argv[1], O_RDONLY);
	cub3d->map = calloc(cub3d->num_of_map_lines, sizeof(char *));
	for (int i = 0; i < (int)(cub3d->num_of_map_lines); i++)
	{
		cub3d->map[i] = get_next_line(fd);
		if (cub3d->map[i] == NULL)
			break ;
	}
	close(fd);
	// for (int i = 0; i < (int)cub3d->num_of_map_lines; i++)
	// 	printf("%s", cub3d->map[i]);
}

void	get_map(t_cub3d	*cub3d)
{
	char	*map_file = cub3d->argv[1];
		
	if (cub3d->argc != 2)
		err_exit(ERR_INVALID_NUM_OF_PARAMS);
	if (!valid_map_file_name(map_file))
		err_exit(ERR_INVALID_FILE_NAME);
	cub3d->num_of_map_lines = get_file_size(map_file);
	if (cub3d->num_of_map_lines == 0)
		err_exit(ERR_INVALID_EMPTY_FILE);
	store_map_content(cub3d);
	free_map_content(cub3d);
	read_map(cub3d);
}

	// TODO: check for valid file name
	// TODO: get map size to malloc
	// TODO: malloc and store map content
	// TODO: check for valid map
	