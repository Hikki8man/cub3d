/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:59:13 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 13:49:43 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

static void	fov_shoot(t_mlx *mlx, t_sprite_list **elem)
{
	(*elem)->tex = mlx->sprite.tex2;
	if ((mlx->ray.a < (mlx->player.a + 0.04)) && \
	(mlx->ray.a > (mlx->player.a - 0.04)) && \
	mlx->shot == 0 && mlx->player.shooting == 1)
		player_shooting(mlx);
}

static void	dead_animation(t_mlx *mlx, t_sprite_list **e)
{
	clock_t	start;

	start = clock();
	if (start < mlx->sprite.deadclock + 100000)
		(*e)->tex = mlx->sprite.deadss1;
	else
		mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] = '-';
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
		fov_shoot(mlx, &elem);
	if (mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '9')
		dead_animation(mlx, &elem);
	if (mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '-')
		elem->tex = mlx->sprite.deadss2;
	add_front(&mlx->sprite.list, elem);
}
