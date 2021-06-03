/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:57:24 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 10:11:31 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_heart(t_mlx *mlx)
{
	int		i;
	float	j;

	i = 0;
	j = 0.01;
	while (i++ < mlx->player.hp)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->hud.heart.img.img, \
		mlx->settings.res_width * j, 0);
		j += 0.1;
	}
}

void	put_c4(t_mlx *mlx)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	x = 0.001;
	y = 0.03;
	while (i++ < mlx->player.inv.c4)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->hud.c4inv.img.img, \
		mlx->settings.res_width * x, mlx->settings.res_width * y);
		x += 0.1;
	}
}

void	put_sprite(t_mlx *mlx)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	x = 0.001;
	y = 0.07;
	while (i++ < mlx->player.inv.drinks)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->hud.spriteinv.img.img, \
		mlx->settings.res_width * x, mlx->settings.res_width * y);
		x += 0.1;
	}
}

void	draw_hud(t_mlx *mlx, t_img_tex *data, int r)
{
	int		x;
	int		y;
	float	xf;
	float	yf;
	int		color;

	x = 0;
	while (x <= mlx->settings.res_width)
	{
		y = 0;
		while (y <= mlx->settings.res_height)
		{
			xf = (float)(x * data->tex.width * r / mlx->settings.res_width);
			yf = (float)(y * data->tex.height * r / mlx->settings.res_height);
			color = get_color_index((int) xf, (int) yf, &data->tex);
			if (color != 9961608)
				put_pixel(mlx, data->img, p(x, y), color);
			else
				put_pixel(mlx, data->img, p(x, y), -16777216);
			y++;
		}
		x++;
	}
}

void	draw_hud_images(t_mlx *mlx)
{
	draw_hud(mlx, &mlx->hud.can, 1);
	draw_hud(mlx, &mlx->hud.drinking, 1);
	draw_hud(mlx, &mlx->hud.heart, 8);
	draw_hud(mlx, &mlx->hud.cmd, 1);
	draw_hud(mlx, &mlx->hud.c4, 1);
	draw_hud(mlx, &mlx->hud.holding_gun, 2);
	draw_hud(mlx, &mlx->hud.shooting_gun, 2);
	draw_hud(mlx, &mlx->hud.c4inv, 8);
	draw_hud(mlx, &mlx->hud.spriteinv, 8);
}
