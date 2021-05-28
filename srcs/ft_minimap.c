//
// Created by Johan Chevet on 5/26/21.
//

#include "../includes/cub3d.h"

static void	draw_player(t_mlx *mlx, int r)
{
	float	x;
	float	y;

	x = mlx->settings.res_width - (mlx->map.x_max * r) \
	+ ((mlx->player.x / 64) * r);
	y = (mlx->player.y / 64) * r;
	put_pixel(mlx, mlx->img, p(x, y), 2667619);
	put_pixel(mlx, mlx->img, p(x + 1, y), 2667619);
	put_pixel(mlx, mlx->img, p(x - 1, y), 2667619);
	put_pixel(mlx, mlx->img, p(x + 1, y + 1), 2667619);
	put_pixel(mlx, mlx->img, p(x + 1, y - 1), 2667619);
	put_pixel(mlx, mlx->img, p(x - 1, y + 1), 2667619);
	put_pixel(mlx, mlx->img, p(x - 1, y - 1), 2667619);
	put_pixel(mlx, mlx->img, p(x, y + 1), 2667619);
	put_pixel(mlx, mlx->img, p(x, y - 1), 2667619);
}

static int	is_sprite(t_mlx *mlx, int xx, int y, int r)
{
	if (mlx->map.map[y / r][xx / r] == '2' \
			|| mlx->map.map[y / r][xx / r] == '3' \
			|| mlx->map.map[y / r][xx / r] == '4' \
			|| mlx->map.map[y / r][xx / r] == '5' \
			|| mlx->map.map[y / r][xx / r] == '6' \
			|| mlx->map.map[y / r][xx / r] == '7' \
			|| mlx->map.map[y / r][xx / r] == '8')
		return (1);
	return (0);
}

static void	set(t_mlx *mlx, int *r)
{
	mlx->up = 0;
	if (mlx->map.x_max >= mlx->map.y_max)
		*r = mlx->settings.res_width / mlx->map.x_max / 4;
	else
		*r = mlx->settings.res_height / mlx->map.y_max / 4;
	if (*r == 0)
		*r = 1;
}

void	draw_minimap(t_mlx *mlx)
{
	int	x;
	int	y;
	int	r;
	int	xx;

	y = 0;
	set(mlx, &r);
	while (y / r < mlx->map.y_max)
	{
		x = mlx->settings.res_width - (mlx->map.x_max * r);
		xx = 0;
		while (x < mlx->settings.res_width)
		{
			if (mlx->map.map[y / r][xx / r] == '1')
				put_pixel(mlx, mlx->img, p(x, y), 13458524);
			if (mlx->map.map[y / r][xx / r] == '0')
				put_pixel(mlx, mlx->img, p(x, y), 13158600);
			if (is_sprite(mlx, xx, y, r))
				put_pixel(mlx, mlx->img, p(x, y), 8543437);
			xx++;
			x++;
		}
		y++;
	}
	draw_player(mlx, r);
}
