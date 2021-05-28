//
// Created by Stellar on 27/04/2021.
//

#include "../includes/cub3d.h"

int	get_color_index(int x, int y, t_texture *tex)
{
	char	*dst;
	int		color;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (-1);
	dst = tex->addr + (y * tex->line_lenght + x * (tex->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_pixel(t_mlx *mlx, t_img img, t_ipoint p, int color)
{
	char	*dst;
	int		i;

	if (p.x >= 0 && p.x < mlx->settings.res_width && p.y >= 0 \
	&& p.y < mlx->settings.res_height)
	{
		dst = img.adrr + (p.y * img.line_lenght + p.x \
		* (img.bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
	i = 1;
	while (i < mlx->up)
	{
		if (p.x + i >= 0 && p.x + i < mlx->settings.res_width && p.y >= 0 \
		&& p.y < mlx->settings.res_height)
		{
			dst = img.adrr + (p.y * img.line_lenght + (p.x + i) \
			 * (img.bits_per_pixel / 8));
			*(unsigned int *) dst = color;
		}
		i++;
	}
}

void	fix_angle(float *a)
{
	if (*a < 0)
		*a += 2 * M_PI;
	if (*a > 2 * M_PI)
		*a -= 2 * M_PI;
}
