//
// Created by Johan Chevet on 5/17/21.
//

#include "../includes/cub3d.h"

static void	data_to_bitmap(t_mlx *mlx, int fd)
{
	int	i;
	int	j;
	int	*img;

	img = (int *)mlx->img.adrr;
	i = mlx->settings.res_height - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < mlx->settings.res_width)
			write(fd, &img[i * mlx->settings.res_width + j], 4);
		i--;
	}
}

static void	bitmap_info_header(t_mlx *mlx, int fd)
{
	int	header_info_size;
	int	plane_nbr;
	int	count;
	int	bit_pixel;

	header_info_size = 40;
	plane_nbr = 1;
	count = -1;
	bit_pixel = 32;
	write(fd, &header_info_size, 4);
	write(fd, &mlx->settings.res_width, 4);
	write(fd, &mlx->settings.res_height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &bit_pixel, 2);
	while (++count < 28)
		write(fd, "\0", 1);
}

int	create_bitmap(t_mlx *mlx)
{
	int	fd;
	int	file_size;
	int	first_pix;

	fd = open("image.bmp", O_CREAT | O_RDWR, 00744);
	file_size = 40 + 14 + 4 + (mlx->settings.res_width * \
	mlx->settings.res_height * 4);
	first_pix = 40 + 14 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	bitmap_info_header(mlx, fd);
	data_to_bitmap(mlx, fd);
	close(fd);
	return (1);
}
