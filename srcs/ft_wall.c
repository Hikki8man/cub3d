//
// Created by Johan Chevet on 5/6/21.
//

#include "../includes/cub3d.h"

int	get_wall_color(t_mlx *mlx, t_texture *tex)
{
	int	ytex;
	int	i;

	ytex = tex->height * (mlx->frame.pixel.y - mlx->frame.wall_start) \
	/ mlx->frame.wall_height;
	i = tex->width * ytex + ((fmod(mlx->ray.x, 64) / 64) * tex->width);
	if (i == NAN)
		i = 0;
	return (tex->adrr[i]);
}

void 	draw_bomb(t_mlx *mlx)
{
	int	color;

	color = get_wall_color(mlx, &mlx->wallc4);
	if (color != 9961608)
		put_pixel(mlx, mlx->img, p(mlx->frame.pixel.x, \
		mlx->frame.pixel.y), color);
}

void	texture_to_put(t_mlx *mlx)
{
	if (mlx->ray.dir == 1 && mlx->ray.y < mlx->player.y)
		mlx->tex_to_put = mlx->tex_n;
	else if (mlx->ray.dir == 1 && mlx->ray.y > mlx->player.y)
		mlx->tex_to_put = mlx->tex_s;
	else if (mlx->ray.dir == 0 && mlx->ray.x < mlx->player.x)
	{
		mlx->tex_to_put = mlx->tex_w;
		mlx->ray.x = mlx->ray.y;
	}
	else if (mlx->ray.dir == 0 && mlx->ray.x > mlx->player.x)
	{
		mlx->tex_to_put = mlx->tex_e;
		mlx->ray.x = mlx->ray.y;
	}
	if (mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '6')
		mlx->tex_to_put = mlx->destructible_wall;
	if (mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] == '7')
		mlx->tex_to_put = mlx->door;
}

void	ft_shading(t_mlx *mlx, int x, int y, int color)
{
	put_pixel(mlx, mlx->hud.filter, p(x, y), color);
}
