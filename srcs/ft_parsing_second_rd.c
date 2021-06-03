/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_second_rd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:58:58 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 11:28:54 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_texture(t_mlx *mlx, t_texture *tex, char *s)
{
	tex->img = mlx_xpm_file_to_image(mlx->mlx, s, &tex->width, &tex->height);
	if (!tex->img)
		return (-1);
	tex->adrr = (int *)mlx_get_data_addr(tex->img, &tex->bits_per_pixel, \
	&tex->line_lenght, &tex->endian);
	return (1);
}

static int	check_line(t_mlx *mlx, int j, char *line)
{
	int		i;

	i = -1;
	if (line[0] == '\0')
		return (-1);
	while (line[++i])
	{
		player_direction(&line[i], mlx, i, j);
		if (line[i] != '1' && line[i] != '0' && line[i] != '2' \
		&& line[i] != '3' && line[i] != '4' && line[i] != '5'\
		&& line[i] != '6' && line[i] != '7' && line[i] != ' ')
			return (-1);
		if (line[i] == '2')
		{
			mlx->settings.nb_enemy++;
			if (add_front_enemy(&mlx->enemy_list, i, j) == -1)
				return (-1);
		}
		if ((line[i] == '3' && mlx->settings.s3 == 0) || (line[i] == '4' \
		&& mlx->settings.s4 == 0) || (line[i] == '5' && mlx->settings.s5 == 0) \
		|| (mlx->settings.s == 0 && line[i] == '2'))
			return (-1);
		mlx->map.map[j][i] = line[i];
	}
	return (1);
}

static void 	fill_rest_with_spaces(t_mlx *mlx, int y)
{
	int	linelen;

	linelen = ft_strlen(mlx->map.map[y]);
	while (linelen < mlx->map.x_max)
	{
		mlx->map.map[y][linelen] = ' ';
		linelen++;
	}
}

static void	mapcpy(t_mlx *mlx, int y)
{
	int	i;

	i = -1;
	mlx->map.y_max = y;
	while (mlx->map.map[++i])
		mlx->map.mapcpy[i] = ft_strdup(mlx->map.map[i]);
}

void 	second_rd_file2(t_mlx *mlx)
{
	char		*line;
	t_ipoint	p;
	int			fd;

	p.x = -1;
	p.y = 0;
	fd = open(mlx->map.path, O_RDWR);
	if (fd == -1)
		exit_error(mlx, -1);
	while (++p.x < mlx->map.y_max)
	{
		get_next_line(fd, &line);
		if (p.x >= mlx->settings.mapstart - 1)
		{
			mlx->map.map[p.y] = ft_calloc(mlx->map.x_max + 1, sizeof(char));
			if (mlx->map.map[p.y] == NULL || check_line(mlx, p.y, line) < 0)
				second_rd_error(mlx, &line, p.y);
			fill_rest_with_spaces(mlx, p.y);
			p.y++;
		}
		free(line);
	}
	close(fd);
	mapcpy(mlx, p.y);
}
