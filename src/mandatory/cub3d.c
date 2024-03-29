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

void	initialize_mlx(t_cub3d *cub3d)
{
	cub3d->mlx_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", RESIZABLE_WINDOW);
	if (cub3d->mlx_ptr == NULL)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	cub3d->image = mlx_new_image(cub3d->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (cub3d->image == NULL)
	{
		mlx_close_window(cub3d->mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(cub3d->mlx_ptr, cub3d->image, 0, 0) == -1)
	{
		mlx_close_window(cub3d->mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

static void	main_hook(void *param)
{	
	t_cub3d	*cub3d;

	cub3d = param;
	render_mini_map(cub3d);
	render_player(cub3d);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(cub3d->mlx_ptr);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_W))
		move_player(cub3d, 0, -1);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_S))
		move_player(cub3d, 0, 1);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_A))
		move_player(cub3d, -1, 0);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_D))
		move_player(cub3d, 1, 0);
}

int	main(int argc, char **argv)
{
	t_cub3d		cub3d;

	cub3d.argc = argc;
	cub3d.argv = argv;
	get_map(&cub3d);
	initialize_mlx(&cub3d);
	mlx_loop_hook(cub3d.mlx_ptr, main_hook, &cub3d);
	mlx_loop(cub3d.mlx_ptr);
	mlx_terminate(cub3d.mlx_ptr);
	return (EXIT_SUCCESS);
}
