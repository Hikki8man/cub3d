/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:59:28 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 10:11:31 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void 	get_sprite_values(t_mlx *mlx)
{
	mlx->frame.sprite_start = round(mlx->settings.res_height / 2 \
	- mlx->frame.sprite_height / 2) + mlx->move.crouch;
	mlx->frame.sprite_end = mlx->frame.sprite_start + mlx->frame.sprite_height;
	mlx->frame.pixel.y = mlx->frame.sprite_start;
}

int	check_side(t_mlx *mlx, t_sprite_list *l)
{
	if (mlx->player.y > l->pos.y && l->s.x > l->pos.x)
		return (1);
	if (mlx->player.y < l->pos.y && l->s.x < l->pos.x)
		return (1);
	if (mlx->player.y == l->pos.y)
	{
		if (mlx->player.x < l->pos.x && l->s.y > l->pos.y)
			return (1);
		if (mlx->player.x > l->pos.x && l->s.y > l->pos.y)
			return (1);
	}
	return (-1);
}

static void	get_sprite_color_index(t_mlx *mlx, t_sprite_list *l)
{
	int	y_texture;
	int	i;

	y_texture = l->tex.height * (mlx->frame.pixel.y - mlx->frame.sprite_start) \
	/ mlx->frame.sprite_height;
	i = y_texture * l->tex.width + l->tex.width / 2 \
	+ (fmodf(mlx->sprite.impact_dist, 64) / 64 * l->tex.width);
	if (i - y_texture * l->tex.width > l->tex.width - 1 \
	|| i - y_texture * l->tex.width < 0)
		i = y_texture * l->tex.width;
	if (l->tex.adrr[i] != 9961608)
	{
		ft_shading(mlx, mlx->frame.pixel.x, mlx->frame.pixel.y, -16777216);
		put_pixel(mlx, mlx->img, p(mlx->frame.pixel.x, mlx->frame.pixel.y), \
		l->tex.adrr[i]);
	}
}

void 	draw_sprite(t_mlx *mlx)
{
	t_sprite_list	*l;

	l = mlx->sprite.list;
	while (l)
	{
		mlx->frame.sprite_height = (int)(mlx->settings.res_height * 64 \
		/ l->mid_dist);
		get_sprite_values(mlx);
		mlx->sprite.impact_dist = hypotf(l->pos.x - l->s.x, l->pos.y - l->s.y);
		mlx->sprite.impact_dist *= check_side(mlx, l);
		if (mlx->sprite.impact_dist > -32 && mlx->sprite.impact_dist < 32)
		{
			while (mlx->frame.pixel.y < mlx->frame.sprite_end)
			{
				get_sprite_color_index(mlx, l);
				mlx->frame.pixel.y++;
			}
		}
		l = l->next;
	}
	mlx->sprite.yes = 0;
}
