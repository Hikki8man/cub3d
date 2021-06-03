/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:58:31 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 10:11:31 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
