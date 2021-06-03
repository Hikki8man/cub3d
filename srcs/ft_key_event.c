/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:58:19 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 10:11:31 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mouvement_keys(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->move.w = 1;
	if (keycode == 1)
		mlx->move.s = 1;
	if (keycode == 123)
		mlx->move.left = 1;
	if (keycode == 124)
		mlx->move.right = 1;
	if (keycode == 0)
		mlx->move.strafe_left = 1;
	if (keycode == 2)
		mlx->move.strafe_right = 1;
	if (keycode == 257)
	{
		mlx->move.crouch = mlx->settings.res_height / -30;
		mlx->move.speed /= 2;
	}
}

int 	key_press(int keycode, t_mlx *mlx)
{
	mouvement_keys(keycode, mlx);
	hud_keys(keycode, mlx);
	action_keys(keycode, mlx);
	if (keycode == 53)
		exit_sucess(mlx);
	return (0);
}

void 	mouvement_release_keys(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->move.w = 0;
	if (keycode == 1)
		mlx->move.s = 0;
	if (keycode == 123)
		mlx->move.left = 0;
	if (keycode == 124)
		mlx->move.right = 0;
	if (keycode == 0)
		mlx->move.strafe_left = 0;
	if (keycode == 2)
		mlx->move.strafe_right = 0;
	if (keycode == 257)
	{
		mlx->move.crouch = 0;
		mlx->move.speed = SPEED;
	}
}

int 	key_release(int keycode, t_mlx *mlx)
{
	mouvement_release_keys(keycode, mlx);
	if (keycode == 3)
	{
		mlx->player.action2 = 0;
		mlx->player.keypress = 0;
	}
	if (keycode == 49)
	{
		mlx->player.shooting = 0;
		mlx->player.keypress = 0;
	}
	return (0);
}
