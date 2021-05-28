//
// Created by Stellar on 02/05/2021.
//

#include "../includes/cub3d.h"

void	collision_offset(t_mlx *mlx, t_collision *c)
{
	if (cos(mlx->player.a) <= 0)
		c->o.x = -20;
	else
		c->o.x = 20;
	if (-sin(mlx->player.a) <= 0)
		c->o.y = -20;
	else
		c->o.y = 20;
	c->p.x = (int)mlx->player.x >> 6;
	c->p.y = (int)mlx->player.y >> 6;
	c->add_o.x = (int)(mlx->player.x + c->o.x) >> 6;
	c->add_o.y = (int)(mlx->player.y + c->o.y) >> 6;
	c->sub_o.x = (int)(mlx->player.x - c->o.x) >> 6;
	c->sub_o.y = (int)(mlx->player.y - c->o.y) >> 6;
}

static void	move_forward(t_mlx *mlx, t_collision *c)
{
	if (mlx->move.w)
	{
		collision_offset(mlx, c);
		if (mlx->map.map[c->p.y][c->add_o.x] != '1' \
		&& mlx->map.map[c->p.y][c->add_o.x] != '6' &&
			mlx->map.map[c->p.y][c->add_o.x] != '7' \
			&& mlx->map.map[c->p.y][c->add_o.x] != '2')
			mlx->player.x += mlx->player.xdir * mlx->move.speed;
		collision_offset(mlx, c);
		if (mlx->map.map[c->add_o.y][c->p.x] != '1' \
		&& mlx->map.map[c->add_o.y][c->p.x] != '6' &&
			mlx->map.map[c->add_o.y][c->p.x] != '7' \
			&& mlx->map.map[c->add_o.y][c->p.x] != '2')
			mlx->player.y += mlx->player.ydir * mlx->move.speed;
	}
}

static void	move_backward(t_mlx *mlx, t_collision *c)
{
	if (mlx->move.s)
	{
		collision_offset(mlx, c);
		if (mlx->map.map[(int)c->p.y][(int)c->sub_o.x] != '1' \
		&& mlx->map.map[(int)c->p.y][(int)c->sub_o.x] != '6' &&
			mlx->map.map[(int)c->p.y][(int)c->sub_o.x] != '7' \
			&& mlx->map.map[(int)c->p.y][(int)c->sub_o.x] != '2')
			mlx->player.x -= mlx->player.xdir * mlx->move.speed;
		collision_offset(mlx, c);
		if (mlx->map.map[(int)c->sub_o.y][(int)c->p.x] != '1' \
		&& mlx->map.map[(int)c->sub_o.y][(int)c->p.x] != '6' &&
			mlx->map.map[(int)c->sub_o.y][(int)c->p.x] != '7' \
			&& mlx->map.map[(int)c->sub_o.y][(int)c->p.x] != '2')
			mlx->player.y -= mlx->player.ydir * mlx->move.speed;
	}
}

static void	look_left_right(t_mlx *mlx)
{
	if (mlx->move.left)
	{
		mlx->player.a += 0.05;
		fix_angle(&mlx->player.a);
		mlx->player.xdir = cos(mlx->player.a);
		mlx->player.ydir = -sin(mlx->player.a);
	}
	if (mlx->move.right)
	{
		mlx->player.a -= 0.05;
		fix_angle(&mlx->player.a);
		mlx->player.xdir = cos(mlx->player.a);
		mlx->player.ydir = -sin(mlx->player.a);
	}
}

void	playermove(t_mlx *mlx)
{
	t_collision	c;

	mlx->player.m.x = (int)mlx->player.x >> 6;
	mlx->player.m.y = (int)mlx->player.y >> 6;
	move_forward(mlx, &c);
	move_backward(mlx, &c);
	look_left_right(mlx);
	strafe_left(mlx, &c);
	strafe_right(mlx, &c);
}
