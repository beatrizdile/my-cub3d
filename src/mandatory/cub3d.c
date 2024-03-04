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

void	ft_hook(void *cub3d)
{
	for(int i = 0; i < 30; i++)
		for(int j = 0; j < 30; j++)
			mlx_put_pixel(((t_cub3d *)cub3d)->image, i, j, 0xFF0000FF);
	for(int i = 0; i < 15; i++)
		for(int j = 0; j < 15; j++)
			mlx_put_pixel(((t_cub3d *)cub3d)->image2, i, j, 0x0000FFFF);
}

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

int	main()
{
	mlx_t			*mlx_ptr;
	mlx_image_t		*image;
	mlx_image_t		*image2;

	mlx_ptr = mlx_init(WIDTH, HEIGHT, "cub3D", RESIZE_WINDOW);
	if (mlx_ptr == NULL)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	image = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	if (image == NULL)
	{
		mlx_close_window(mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	image2 = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	if (image == NULL)
	{
		mlx_close_window(mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx_ptr, image, 0, 0) == -1)
	{
		mlx_close_window(mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx_ptr, image2, 0, 0) == -1)
	{
		mlx_close_window(mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}

	t_cub3d		cub3d;
	cub3d.mlx_ptr = mlx_ptr;
	cub3d.image = image;
	cub3d.image2 = image2;

	mlx_loop_hook(mlx_ptr, ft_hook, &cub3d);
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
	return (EXIT_SUCCESS);
}
