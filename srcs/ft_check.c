//
// Created by Johan Chevet on 5/15/21.
//

#include "../includes/cub3d.h"

int	check_res(t_mlx *mlx)
{
	if (mlx->settings.res_height <= 0 || mlx->settings.res_width <= 0 \
	|| mlx->settings.r > 1)
		return (-1);
	if (mlx->settings.res_height > 1440)
		mlx->settings.res_height = 1440;
	if (mlx->settings.res_width > 2560)
		mlx->settings.res_width = 2560;
	return (1);
}
