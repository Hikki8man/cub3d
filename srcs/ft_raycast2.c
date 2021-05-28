//
// Created by Johan Chevet on 5/5/21.
//

#include "../includes/cub3d.h"

void	reset_ray(t_mlx *mlx)
{
	mlx->ray.xo = cos(mlx->ray.a);
	mlx->ray.yo = -sin(mlx->ray.a);
	mlx->ray.map.y = (((int)mlx->player.y >> 6) << 6);
	mlx->ray.map.x = (((int)mlx->player.x >> 6) << 6);
	mlx->ray.delta.x = fabsf(1 / mlx->ray.xo);
	mlx->ray.delta.y = fabsf(1 / mlx->ray.yo);
	mlx->sprite.list = NULL;
}

void	sprite_plan(t_mlx *mlx)
{
	t_plan			p;
	t_sprite_list	*l;

	l = mlx->sprite.list;
	while (l)
	{
		p.rotate90.x = -mlx->player.ydir;
		p.rotate90.y = mlx->player.xdir;
		p.n.x = l->pos.x + p.rotate90.x + 0.01;
		p.n.y = l->pos.y + p.rotate90.y;
		p.p.x = mlx->player.x + mlx->ray.xo + 0.01;
		p.p.y = mlx->player.y + mlx->ray.yo + 0.01;
		p.vda = p.p.y - ((mlx->player.y - p.p.y) \
			/ (mlx->player.x - p.p.x) * p.p.x);
		p.vdb = p.n.y - ((l->pos.y - p.n.y) / (l->pos.x - p.n.x) * p.n.x);
		p.vco = -((l->pos.y - p.n.y) / (l->pos.x - p.n.x)) + \
		(mlx->player.y - p.p.y) / (mlx->player.x - p.p.x);
		p.vcob = -p.vdb + p.vda + 0.01;
		if (mlx->player.x == p.p.x)
			l->s.x = p.p.x;
		else
			l->s.x = -(p.vcob / p.vco);
		l->s.y = (l->pos.y - p.n.y) / (l->pos.x - p.n.x) * l->s.x + p.vdb;
		l = l->next;
	}
}

void	sprite_hit(t_mlx *mlx)
{
	t_sprite_list	*elem;

	elem = new_elem();
	if (elem == NULL)
		exit_error(mlx, 1);
	elem->pos.x = mlx->ray.map.x + 32;
	elem->pos.y = mlx->ray.map.y + 32;
	elem->mid_dist = dist(mlx->player.x, mlx->player.y, \
	elem->pos.x, elem->pos.y);
	if (mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '3')
		elem->tex = mlx->sprite.tex3;
	else if (mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '4')
		elem->tex = mlx->sprite.tex4;
	else if (mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '5')
		elem->tex = mlx->sprite.tex5;
	else if (mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '2')
	{
		elem->tex = mlx->sprite.tex2;
		if ((mlx->ray.a < (mlx->player.a + 0.04)) && \
			(mlx->ray.a > (mlx->player.a - 0.04)) && \
			mlx->shot == 0 && \
			mlx->player.shooting == 1)
			player_shooting(mlx);
	}
	add_front(&mlx->sprite.list, elem);
}
