/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:57:39 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 10:11:31 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_sucess(t_mlx *mlx)
{
	free_map(mlx);
	free_tex(mlx);
	destroy_img_img(mlx);
	destroy_tex_img(mlx);
	free_enemy_list(mlx);
	free_enemy_list(mlx);
	free_sprite_list(mlx);
	free_sprite_list(mlx);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void 	exit_error(t_mlx *mlx, int err)
{
	if (err == -1)
	{
		free(mlx->map.map);
		free(mlx->map.mapcpy);
	}
	if (err == 0)
	{
		free_map(mlx);
		free(mlx->map.mapcpy);
	}
	free_tex(mlx);
	destroy_img_img(mlx);
	destroy_tex_img(mlx);
	free_enemy_list(mlx);
	free_sprite_list(mlx);
	print_err(err);
	exit(1);
}
