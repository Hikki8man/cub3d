//
// Created by Johan Chevet on 5/14/21.
//
#include "../includes/cub3d.h"

void	args(t_mlx *mlx, char *map)
{
	int	l;
	int	fd;

	mlx->map.path = map;
	fd = open(map, O_RDWR);
	if (ft_strlen(map) < 5 || fd == -1)
		exit_error(mlx, 4);
	close (fd);
	l = ft_strlen(map) - 4;
	map += l;
	if (ft_strncmp(map, ".cub", 4) != 0)
		exit_error(mlx, 4);
}
