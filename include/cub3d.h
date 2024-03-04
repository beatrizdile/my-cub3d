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
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>

# define WIDTH 1200
# define HEIGHT 800
# define MINI_MAP_TILE_SIZE 30
# define RESIZE_WINDOW false

# define PLAYER_COLOR 0xFF0000FF
# define WALL_COLOR 0x000000FF
# define EMPTY_COLOR 0xFFFFFFFF
# define RAY_COLOR 0xFF0000FF

# define WEST "WE"
# define NORTH "NO"
# define EAST "EA"
# define SOUTH "SO"
# define FLOOR "F"
# define CEILING "C"

# define FILE_EXTENSION ".cub"

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_cub3d
{
	mlx_t			*mlx_ptr;
	mlx_image_t		*image;
	mlx_image_t		*image2;
	char			**map;
	size_t			map_x;
	size_t			map_y;
}					t_cub3d;

#endif
