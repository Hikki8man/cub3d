/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:58:15 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/04 13:00:30 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_movement(t_mlx *mlx)
{
	mlx->move.w = 0;
	mlx->move.s = 0;
	mlx->move.right = 0;
	mlx->move.left = 0;
	mlx->move.strafe_left = 0;
	mlx->move.strafe_right = 0;
	mlx->move.crouch = 0;
	mlx->move.speed = SPEED;
	mlx->move.soundplaying = 0;
	mlx->move.mouse = 0;
	mlx_mouse_move(&mlx->win, mlx->settings.res_width / 2, \
	mlx->settings.res_height / 2);
}

static void	init_player(t_mlx *mlx)
{
	mlx->player.shooting = 0;
	mlx->player.inv.slot1 = 0;
	mlx->player.inv.slot2 = 0;
	mlx->player.inv.slot3 = 0;
	mlx->player.inv.c4 = 0;
	mlx->player.inv.drinks = 0;
	mlx->player.keypress = 0;
	mlx->player.action = 0;
	mlx->player.action2 = 0;
	mlx->player.drinking = 0;
	mlx->player.plant = 0;
	mlx->player.hp = 5;
	mlx->enemy_list = NULL;
	mlx->player.direction = 0;
}

static void	init_settings(t_mlx *mlx)
{
	mlx->settings.f = 0;
	mlx->settings.c = 0;
	mlx->settings.no = 0;
	mlx->settings.so = 0;
	mlx->settings.ea = 0;
	mlx->settings.we = 0;
	mlx->settings.mapstart = -1;
	mlx->settings.c_color = -1;
	mlx->settings.f_color = -1;
	mlx->settings.nb_enemy = 0;
	mlx->settings.s = 0;
	mlx->settings.s3 = 0;
	mlx->settings.s4 = 0;
	mlx->settings.s5 = 0;
	mlx->map.x_max = 0;
	mlx->map.y_max = 1;
	mlx->settings.sound = ON;
	mlx->settings.res_width = 1000;
	mlx->settings.res_height = 1000;
}

void	init_all(t_mlx *mlx)
{
	init_mlx(mlx);
	init_settings(mlx);
	init_movement(mlx);
	init_img_img(mlx);
	init_tex_img(mlx);
	init_player(mlx);
}
