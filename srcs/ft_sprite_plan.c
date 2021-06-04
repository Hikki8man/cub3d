/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:59:13 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 13:49:43 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	inter_plan_test(t_mlx *mlx, t_sprite_list **l)
{
	t_point		u;
	t_point		v;
	double		cosAl;

	u.x = mlx->player.x - (*l)->pos.x;
	u.y = mlx->player.y - (*l)->pos.y;
	v.x = mlx->ray.xo;
	v.y = mlx->ray.yo;
	cosAl = (u.x * v.x + u.y * v.y) / (sqrt(pow(u.x, 2) \
	+ pow(u.y, 2)) * sqrt(pow(v.x, 2) + pow(v.y, 2)));
	if (v.x > 0)
		v.x = (cosAl * u.x) + (sqrt(1 - powf(cosAl, 2)) * u.y);
	else
		v.x = cosAl * u.x - sqrt(1 - powf(cosAl, 2)) * u.y;
	if (v.y > 0)
		v.y = -(sqrt(1 - powf(cosAl, 2)) * u.x - cosAl * u.y);
	else
		v.y = sqrt(1 - powf(cosAl, 2)) * u.x + cosAl * u.y;
	(*l)->s.x = mlx->player.x + v.x;
	(*l)->s.y = mlx->player.y + v.y;
}

static void	set_vars(t_mlx *mlx, t_sprite_list *l)
{
	mlx->p.n.x = l->pos.x - (mlx->player.y - l->pos.y);
	mlx->p.n.y = l->pos.y + mlx->player.x - l->pos.x;
	mlx->p.p.x = mlx->player.x + mlx->ray.xo;
	mlx->p.p.y = mlx->player.y + mlx->ray.yo;
	mlx->p.vda = mlx->p.p.y - ((mlx->player.y - mlx->p.p.y) \
	/ (mlx->player.x - mlx->p.p.x) * mlx->p.p.x);
	mlx->p.vdb = mlx->p.n.y - ((l->pos.y - mlx->p.n.y) \
	/ (l->pos.x - mlx->p.n.x) * mlx->p.n.x);
}

void	inter_plan(t_mlx *mlx)
{
	mlx->p.l = mlx->sprite.list;
	while (mlx->p.l)
	{
		if (mlx->player.y == mlx->p.l->pos.y)
			inter_plan_test(mlx, &mlx->p.l);
		else
		{
			set_vars(mlx, mlx->p.l);
			if (mlx->player.x == mlx->p.p.x)
				mlx->p.l->s.x = mlx->p.p.x;
			else if (mlx->p.l->pos.x == mlx->p.n.x)
				mlx->p.l->s.x = mlx->p.l->pos.x;
			else
				mlx->p.l->s.x = -((-mlx->p.vdb + mlx->p.vda) \
				/ (-((mlx->p.l->pos.y - mlx->p.n.y) \
				/ (mlx->p.l->pos.x - mlx->p.n.x)) + \
				(mlx->player.y - mlx->p.p.y) / (mlx->player.x - mlx->p.p.x)));
			mlx->p.l->s.y = (mlx->p.l->pos.y - mlx->p.n.y) / (mlx->p.l->pos.x \
			- mlx->p.n.x) * mlx->p.l->s.x + mlx->p.vdb;
			if (mlx->player.y == mlx->p.l->pos.y)
				mlx->p.l->s.x = mlx->p.l->pos.x;
		}
		mlx->p.l = mlx->p.l->next;
	}
}
