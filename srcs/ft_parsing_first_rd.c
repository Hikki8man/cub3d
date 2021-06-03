/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_first_rd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:58:51 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 10:11:31 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_settings(t_mlx *mlx)
{
	if (mlx->settings.c == 1 && mlx->settings.f == 1 \
	&& mlx->tex_n.img && mlx->tex_s.img && mlx->tex_w.img && mlx->tex_e.img \
	&& mlx->settings.s <= 1 && mlx->settings.s3 <= 1 && mlx->settings.s4 <= 1 \
	&& mlx->settings.s5 <= 1 && mlx->settings.no == 1 \
	&& mlx->settings.so == 1 && mlx->settings.ea == 1 \
	&& mlx->settings.we == 1)
		return (1);
	else
		return (0);
}

static void	malloc_maps(t_mlx *mlx)
{
	mlx->map.map = ft_calloc(mlx->map.y_max - mlx->settings.mapstart \
	+ 2, sizeof(char *));
	mlx->map.mapcpy = ft_calloc(mlx->map.y_max - mlx->settings.mapstart \
	+ 2, sizeof(char *));
	if (mlx->map.map == NULL || mlx->map.mapcpy == NULL)
		exit_error(mlx, 1);
}

static void	get_longest_line(t_mlx *mlx, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > mlx->map.x_max)
		mlx->map.x_max = len;
}

void	first_rd_file(t_mlx *mlx)
{
	char	*line;
	int		fd;
	int		good;

	good = 1;
	fd = open(mlx->map.path, O_RDWR);
	if (fd == -1)
		exit_error(mlx, -2);
	while (get_next_line(fd, &line) && good > 0)
	{
		good = get_settings(line, mlx->map.y_max, mlx);
		get_longest_line(mlx, line);
		mlx->map.y_max++;
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	if (good < 1 || !check_settings(mlx))
		exit_error(mlx, 2);
	malloc_maps(mlx);
	second_rd_file2(mlx);
}
