/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:57:18 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 10:11:31 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void 	draw_sky(t_mlx *mlx)
{
	while (mlx->frame.pixel.y < mlx->frame.wall_start)
	{
		put_pixel(mlx, mlx->img, p(mlx->frame.pixel.x, mlx->frame.pixel.y), \
		mlx->settings.c_color);
		ft_shading(mlx, mlx->frame.pixel.x, mlx->frame.pixel.y, -16777216);
		mlx->frame.pixel.y++;
	}
}

static void	draw_wall(t_mlx *mlx)
{
	int	color;

	while (mlx->frame.pixel.y < mlx->frame.wall_end \
	&& mlx->frame.pixel.y < mlx->settings.res_height)
	{
		put_pixel(mlx, mlx->img, p(mlx->frame.pixel.x, mlx->frame.pixel.y), \
		get_wall_color(mlx, &mlx->tex_to_put));
		if (mlx->ray.m.x == mlx->map.bombpos.x \
		&& mlx->ray.m.y == mlx->map.bombpos.y)
			draw_bomb(mlx);
		if (mlx->ray.dist > 1500)
			color = 0;
		else
			color = create_trgb(255 - (mlx->ray.dist / 1500 * 255), \
			0, 0, 0);
		ft_shading(mlx, mlx->frame.pixel.x, mlx->frame.pixel.y, color);
		mlx->frame.pixel.y++;
	}
}

static void 	draw_floor(t_mlx *mlx)
{
	while (mlx->frame.pixel.y < mlx->settings.res_height)
	{
		put_pixel(mlx, mlx->img, p(mlx->frame.pixel.x, mlx->frame.pixel.y), \
		mlx->settings.f_color);
		ft_shading(mlx, mlx->frame.pixel.x, mlx->frame.pixel.y, -16777216);
		mlx->frame.pixel.y++;
	}
}

static void	reset_frame(t_mlx *mlx)
{
	mlx->frame.pixel.y = 0;
	mlx->frame.fisheye = mlx->player.a - mlx->ray.a;
	fix_angle(&mlx->frame.fisheye);
	mlx->ray.dist = mlx->ray.dist * cos(mlx->frame.fisheye);
	mlx->frame.wall_height = (int)(mlx->settings.res_height * 64 / \
	mlx->ray.dist);
	mlx->frame.wall_start = round(mlx->settings.res_height / 2 - \
	mlx->frame.wall_height / 2) + mlx->move.crouch;
	mlx->frame.wall_end = mlx->frame.wall_start + mlx->frame.wall_height;
	mlx->sprite.dist *= ((cos(mlx->frame.fisheye) + 2) / 3);
}

void	draw_frame(t_mlx *mlx)
{
	reset_frame(mlx);
	draw_sky(mlx);
	draw_wall(mlx);
	draw_floor(mlx);
	if (mlx->sprite.yes == 1)
		draw_sprite(mlx);
}
