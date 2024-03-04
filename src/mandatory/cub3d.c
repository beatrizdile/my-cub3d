/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:43:10 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/02/19 22:32:22 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	initialize(t_cub3d *cub3d)
// {
// 	cub3d->mlx_ptr = mlx_init(WIDTH, HEIGHT, "cub3D", true);
// 	if (cub3d->mlx_ptr == NULL)
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		exit(EXIT_FAILURE);
// 	}
// 	cub3d->image = mlx_new_image(cub3d->mlx_ptr, WIDTH, HEIGHT);
// 	if (cub3d->image == NULL)
// 	{
// 		mlx_close_window(cub3d->mlx_ptr);
// 		puts(mlx_strerror(mlx_errno));
// 		exit(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(cub3d->mlx_ptr, cub3d->image, 0, 0) == -1)
// 	{
// 		mlx_close_window(cub3d->mlx_ptr);
// 		puts(mlx_strerror(mlx_errno));
// 		exit(EXIT_FAILURE);
// 	}
// }

# include <stdio.h>
# include "libft.h"
# include <MLX42/MLX42.h>

# define WIDTH 1200
# define HEIGHT 800
# define MINI_MAP_TILE_SIZE 30
# define RESIZE_WINDOW false

typedef struct s_cub3d
{
	mlx_t			*mlx_ptr;
	mlx_image_t		*image;
}				t_cub3d;

void	ft_hook(void *cub3d)
{
	for(int i = 0; i < 30; i++)
		for(int j = 0; j < 30; j++)
			mlx_put_pixel(((t_cub3d *)cub3d)->image, i, j, 0xFF0000FF);
}

int	main()
{
	t_cub3d		cub3d;

	cub3d.mlx_ptr = mlx_init(WIDTH, HEIGHT, "cub3D", RESIZE_WINDOW);
	if (cub3d.mlx_ptr == NULL)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	cub3d.image = mlx_new_image(cub3d.mlx_ptr, WIDTH, HEIGHT);
	if (cub3d.image == NULL)
	{
		mlx_close_window(cub3d.mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(cub3d.mlx_ptr, cub3d.image, 0, 0) == -1)
	{
		mlx_close_window(cub3d.mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}

	mlx_loop_hook(cub3d.mlx_ptr, ft_hook, &cub3d);
	mlx_loop(cub3d.mlx_ptr);
	mlx_terminate(cub3d.mlx_ptr);
	return (EXIT_SUCCESS);
}
