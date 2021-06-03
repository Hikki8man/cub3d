/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:57:48 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 10:11:31 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void 	second_rd_error(t_mlx *mlx, char **line, int y)
{
	free(*line);
	if (mlx->map.map[y] == NULL)
		exit_error(mlx, 0);
	map_not_valid(mlx, y + 1);
}

void 	free_map(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (mlx->map.map[++i])
		free(mlx->map.map[i]);
	free(mlx->map.map);
}

void 	checkmap_error(t_map *map, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < map->y_max)
	{
		free(map->map[i]);
		free(map->mapcpy[i]);
		i++;
	}
	free(map->map);
	free(map->mapcpy);
	exit_error(mlx, 3);
}

void	map_not_valid(t_mlx *mlx, int y)
{
	int	i;

	i = 0;
	while (i < y + 1)
	{
		free(mlx->map.map[i]);
		i++;
	}
	free(mlx->map.map);
	free(mlx->map.mapcpy);
	free_enemy_list(mlx);
	exit_error(mlx, 3);
}
