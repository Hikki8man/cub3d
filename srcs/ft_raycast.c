//
// Created by Johan Chevet on 5/5/21.
//

#include "../includes/cub3d.h"

void	ray_offset(t_mlx *mlx)
{
	if (mlx->ray.xo < 0)
	{
		mlx->ray.step.x = -64;
		mlx->ray.side.x = (mlx->player.x - (float) mlx->ray.map.x) * \
		mlx->ray.delta.x;
	}
	else
	{
		mlx->ray.step.x = 64;
		mlx->ray.side.x = ((float) mlx->ray.map.x + 64.0 - mlx->player.x) * \
		mlx->ray.delta.x;
	}
	if (mlx->ray.yo < 0)
	{
		mlx->ray.step.y = -64;
		mlx->ray.side.y = (float)(mlx->player.y - (float)mlx->ray.map.y) *\
		mlx->ray.delta.y;
	}
	else
	{
		mlx->ray.step.y = 64;
		mlx->ray.side.y = ((float) mlx->ray.map.y + 64.0 - mlx->player.y) * \
		mlx->ray.delta.y;
	}
}

void	ray_dir(t_mlx *mlx)
{
	if (mlx->ray.side.x < mlx->ray.side.y)
	{
		mlx->ray.side.x += 64 * mlx->ray.delta.x;
		mlx->ray.map.x += mlx->ray.step.x;
		mlx->ray.dir = 0;
	}
	else
	{
		mlx->ray.side.y += 64 * mlx->ray.delta.y;
		mlx->ray.map.y += mlx->ray.step.y;
		mlx->ray.dir = 1;
	}
}

void	ray_hit(t_mlx *mlx)
{
	mlx->ray.hit = 0;
	while (mlx->ray.hit == 0)
	{
		ray_dir(mlx);
		mlx->ray.m.y = mlx->ray.map.y >> 6;
		mlx->ray.m.x = mlx->ray.map.x >> 6;
		if (mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '2' ||
			mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '3' ||
			mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '4' ||
			mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '5')
			sprite_hit(mlx);
		mlx->sprite.yes = 1;
		if (mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '1' ||
			mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '6' ||
			mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '7')
			mlx->ray.hit = 1;
	}
}

void	get_ray_pos_and_dist(t_mlx *mlx)
{
	if (mlx->ray.dir == 0)
		mlx->ray.dist = ((mlx->ray.map.x - mlx->player.x + \
		(64 - mlx->ray.step.x) / 2) / mlx->ray.xo);
	else
		mlx->ray.dist = ((mlx->ray.map.y - mlx->player.y + \
		(64 - mlx->ray.step.y) / 2) / mlx->ray.yo);
	mlx->ray.x = mlx->ray.dist * mlx->ray.xo + mlx->player.x;
	mlx->ray.y = mlx->ray.dist * mlx->ray.yo + mlx->player.y;
}

void	ray_cast(t_mlx *mlx)
{
	mlx->shot = 0;
	mlx->frame.pixel.x = 0;
	mlx->ray.a = mlx->player.a + 0.523599;
	fix_angle(&mlx->ray.a);
	mlx->up = 1;
	while (mlx->frame.pixel.x <= mlx->settings.res_width)
	{
		reset_ray(mlx);
		ray_offset(mlx);
		ray_hit(mlx);
		get_ray_pos_and_dist(mlx);
		texture_to_put(mlx);
		sprite_plan(mlx);
		draw_frame(mlx);
		mlx->ray.a -= 1.047198 * mlx->up / mlx->settings.res_width;
		fix_angle(&mlx->ray.a);
		mlx->frame.pixel.x += mlx->up;
		free_sprite_list(mlx);
	}
}
