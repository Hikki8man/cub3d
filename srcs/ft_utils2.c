//
// Created by Johan Chevet on 5/6/21.
//

#include "../includes/cub3d.h"

int	skip_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (i);
}

int	intlen(int nb)
{
	int	i;

	i = 1;
	while (nb / 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

float	dist(float px, float py, float rx, float ry)
{
	return (sqrtf(powf((px - rx), 2) + pow((py - ry), 2)));
}

t_ipoint	p(int x, int y)
{
	t_ipoint	point;

	point.x = x;
	point.y = y;
	return (point);
}

void 	play_sound(t_mlx *mlx, char *cmd)
{
	if (mlx->settings.sound == 1)
		system(cmd);
}
