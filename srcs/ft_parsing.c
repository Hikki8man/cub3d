/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:59:03 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 10:11:31 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_direction(char *c, t_mlx *mlx, int x, int y)
{
	if (*c == 'S' || *c == 'N' || *c == 'E' || *c == 'W')
	{
		if (mlx->player.direction != 0)
			exit_error(mlx, 7);
		mlx->player.direction = *c;
		*c = '0';
		mlx->player.x = (float)x;
		mlx->player.y = (float)y;
	}
}

static void	checkmap(t_map *map, int x, int y, t_mlx *mlx)
{
	if (x < 0 || y < 0 || y > map->y_max || x > map->x_max \
	|| map->mapcpy[y][x] == '1' || map->mapcpy[y][x] == '*')
		return ;
	if (map->mapcpy[y][x] == mlx->player.direction || map->mapcpy[y][x] == '2' \
	|| map->mapcpy[y][x] == '3' ||
	map->mapcpy[y][x] == '4' || map->mapcpy[y][x] == '5' \
	|| map->mapcpy[y][x] == '6' || map->mapcpy[y][x] == '7')
		map->mapcpy[y][x] = '*';
	if ((map->mapcpy[y][x] != '1' && (y == map->y_max || x == map->x_max)) \
	|| y == 0 || x == 0 || map->mapcpy[y][x] == ' ')
		checkmap_error(map, mlx);
	if (map->mapcpy[y][x] == '0')
		map->mapcpy[y][x] = '*';
	checkmap(map, x - 1, y, mlx);
	checkmap(map, x + 1, y, mlx);
	checkmap(map, x, y - 1, mlx);
	checkmap(map, x, y + 1, mlx);
	checkmap(map, x + 1, y + 1, mlx);
	checkmap(map, x + 1, y - 1, mlx);
	checkmap(map, x - 1, y + 1, mlx);
	checkmap(map, x - 1, y - 1, mlx);
	return ;
}

void	parsing(t_mlx *mlx)
{
	first_rd_file(mlx);
	checkmap(&mlx->map, (int)mlx->player.x, (int)mlx->player.y, mlx);
}
