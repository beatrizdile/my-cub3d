/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:26:54 by paulo             #+#    #+#             */
/*   Updated: 2024/02/19 22:23:06 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <MLX42/MLX42.h>
# include <string.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>

# define ERR_INVALID_NUM_OF_PARAMS "Error\nInvalid number of parameters\n"
# define ERR_INVALID_MAP_FILE "Error\nInvalid map file\n"
# define ERR_INVALID_EMPTY_FILE "Error\nEmpty file\n"
# define ERR_INVALID_FILE_NAME "Error\nInvalid map file name\n"

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
# define MINI_MAP_TILE_SIZE 40
# define MINI_MAP_PLAYER_SIZE 20
# define RESIZABLE_WINDOW false
# define FILE_EXTENSION ".cub"

# define PLAYER_COLOR 0xFF0000FF
# define RAY_COLOR 0xFF0000FF
# define FLOOR_TILE_COLOR 0xFFFFFFFF
# define WALL_TILE_COLOR 0x000000FF
# define GRID_TILE_COLOR 0x131415FF

# define PLAYER_SPEED 2

# define WEST "WE"
# define NORTH "NO"
# define EAST "EA"
# define SOUTH "SO"
# define FLOOR "F"
# define CEILING "C"

# define WALL_CHAR '1'
# define FLOOR_CHAR '0'
# define FILE_EXTENSION ".cub"

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_cub3d
{
	char			**argv;
	int				argc;
	mlx_t			*mlx_ptr;
	mlx_image_t		*image;
	char			**map;
	size_t			map_x;
	size_t			map_y;
	size_t			num_of_map_lines;
	t_vector		player;
}					t_cub3d;

// map.c
void		get_map(t_cub3d	*cub3d);
void		read_map(t_cub3d *cub3d);
void		render_mini_map(t_cub3d *cub3d);

// map_validation.c
void		check_valid_map(t_cub3d *cub3d);

// render.c
void		render_square(t_cub3d *cub3d, t_vector map_point, size_t size, uint32_t color);
void		render_player(t_cub3d *cub3d);

// player.c
void		move_player(t_cub3d *cub3d, int x_signal, int y_signal);

// finish.c
void		err_exit(char *str);

// free.c
void		free_map_content(t_cub3d *cub3d);

#endif
