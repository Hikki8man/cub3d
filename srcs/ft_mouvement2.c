/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouvement2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:58:46 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 10:11:31 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	strafe_left(t_mlx *mlx, t_collision *c)
{
	if (mlx->move.strafe_left && mlx->move.strafe_right == 0)
	{
		mlx->player.a += M_PI_2;
		fix_angle(&mlx->player.a);
		collision_offset(mlx, c);
		if (mlx->map.map[(int)c->p.y][(int)c->add_o.x] != '1' \
		&& mlx->map.map[(int)c->p.y][(int)c->add_o.x] != '6' &&
			mlx->map.map[(int)c->p.y][(int)c->add_o.x] != '7' \
			&& mlx->map.map[(int)c->p.y][(int)c->add_o.x] != '2')
			mlx->player.x += cos(mlx->player.a) * mlx->move.speed;
		collision_offset(mlx, c);
		if (mlx->map.map[(int)c->add_o.y][(int)c->p.x] != '1' \
		&& mlx->map.map[(int)c->add_o.y][(int)c->p.x] != '6' &&
			mlx->map.map[(int)c->add_o.y][(int)c->p.x] != '7' \
			&& mlx->map.map[(int)c->add_o.y][(int)c->p.x] != '2')
			mlx->player.y += -sin(mlx->player.a) * mlx->move.speed;
		mlx->player.a -= M_PI_2;
	}
}

void	strafe_right(t_mlx *mlx, t_collision *c)
{
	if (mlx->move.strafe_right && mlx->move.strafe_left == 0)
	{
		mlx->player.a -= M_PI_2;
		fix_angle(&mlx->player.a);
		collision_offset(mlx, c);
		if (mlx->map.map[(int)c->p.y][(int)c->add_o.x] != '1' \
		&& mlx->map.map[(int)c->p.y][(int)c->add_o.x] != '6' &&
			mlx->map.map[(int)c->p.y][(int)c->add_o.x] != '7' \
			&& mlx->map.map[(int)c->p.y][(int)c->add_o.x] != '2')
			mlx->player.x += cos(mlx->player.a) * mlx->move.speed;
		collision_offset(mlx, c);
		if (mlx->map.map[(int)c->add_o.y][(int)c->p.x] != '1' \
		&& mlx->map.map[(int)c->add_o.y][(int)c->p.x] != '6' &&
			mlx->map.map[(int)c->add_o.y][(int)c->p.x] != '7' \
			&& mlx->map.map[(int)c->add_o.y][(int)c->p.x] != '2')
			mlx->player.y += -sin(mlx->player.a) * mlx->move.speed;
		mlx->player.a += M_PI_2;
	}
}

void 	mousemove(t_mlx *mlx)
{
	int	x;
	int	y;

	if (mlx->move.mouse == 1)
	{
		mlx_mouse_hide();
		mlx_mouse_get_pos(mlx->win, &x, &y);
		x -= mlx->settings.res_width / 2;
		if (x < 0)
			mlx->player.a += (float) -x / 800.0;
		else if (x > 0)
			mlx->player.a -= (float) x / 800.0;
		fix_angle(&mlx->player.a);
		mlx->player.xdir = cos(mlx->player.a);
		mlx->player.ydir = -sin(mlx->player.a);
		mlx_mouse_move(mlx->win, mlx->settings.res_width / 2, \
		mlx->settings.res_height / 2);
	}
	else
		mlx_mouse_show();
}
