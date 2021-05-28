//
// Created by Johan Chevet on 5/8/21.
//
#include "../includes/cub3d.h"

static t_texture	*texture_address(t_texture *tex, int *set)
{
	if (set != NULL)
		*set += 1;
	return (tex);
}

static int	get_texture_path(char *s, t_mlx *mlx)
{
	t_texture	*tex;

	if (*s == 'N' && *(s + 1) == 'O')
		tex = texture_address(&mlx->tex_n, &mlx->settings.no);
	else if (*s == 'S' && *(s + 1) == 'O')
		tex = texture_address(&mlx->tex_s, &mlx->settings.so);
	else if (*s == 'W' && *(s + 1) == 'E')
		tex = texture_address(&mlx->tex_w, &mlx->settings.we);
	else if (*s == 'E' && *(s + 1) == 'A')
		tex = texture_address(&mlx->tex_e, &mlx->settings.ea);
	else if (*s == 'S' && *(s + 1) == '3')
		tex = texture_address(&mlx->sprite.tex3, &mlx->settings.s3);
	else if (*s == 'S' && *(s + 1) == '4')
		tex = texture_address(&mlx->sprite.tex4, &mlx->settings.s4);
	else if (*s == 'S' && *(s + 1) == '5')
		tex = texture_address(&mlx->sprite.tex5, &mlx->settings.s5);
	else if (*s == 'S' && *(s + 1) == ' ')
		tex = texture_address(&mlx->sprite.tex2, &mlx->settings.s);
	else
		return (1);
	s += 2;
	s += skip_space(s);
	if (get_texture(mlx, tex, s) < 0)
		return (-1);
	return (1);
}

static int	get_res(char *s, t_mlx *mlx)
{
	int	t[2];
	int	i;

	mlx->settings.r += 1;
	i = 0;
	s++;
	if (*s != ' ')
		return (-1);
	while (i < 2)
	{
		s += skip_space(s);
		t[i] = ft_atoi(s);
		s += intlen(t[i]);
		i++;
	}
	if (*s != 0)
		return (-1);
	mlx->settings.res_width = t[0];
	mlx->settings.res_height = t[1];
	if (check_res(mlx) == -1)
		return (-1);
	return (1);
}

static int	get_color(char *s, int *color, int *nb)
{
	int	t[3];
	int	i;

	*nb += 1;
	i = -1;
	s++;
	if (*s != ' ')
		return (-1);
	while (++i < 3)
	{
		s += skip_space(s);
		t[i] = ft_atoi(s);
		s += intlen(t[i]);
		if (t[i] < 0 || t[i] > 255)
			return (-1);
		s += skip_space(s);
		if (*s != ',' && i != 2)
			return (-1);
		if (i != 2)
			s++;
	}
	if (*s != 0)
		return (-1);
	*color = create_trgb(0, t[0], t[1], t[2]);
	return (1);
}

int 	get_settings(char *s, int start, t_mlx *mlx)
{
	int	check;

	check = 1;
	if (*s == 'R')
		check = get_res(s, mlx);
	else if (*s == 'F')
		check = get_color(s, &mlx->settings.f_color, &mlx->settings.f);
	else if (*s == 'C')
		check = get_color(s, &mlx->settings.c_color, &mlx->settings.c);
	else if (*s == 'S' || *s == 'N' || *s == 'E' || *s == 'W')
		check = get_texture_path(s, mlx);
	else if (*s == '\0')
		return (1);
	else if (check_settings(mlx) && (*s == '1' || *s == ' ') \
	&& mlx->settings.mapstart == -1)
	{
		mlx->settings.mapstart = start;
		return (1);
	}
	else if (mlx->settings.mapstart < 0)
		return (-1);
	return (check);
}
