//
// Created by Stellar on 27/04/2021.
//

#include "../includes/cub3d.h"

void	set_hud_images(t_mlx *mlx, t_img_tex *hud, char *path)
{
	hud->img.img = mlx_new_image(mlx->mlx, mlx->settings.res_width, \
	mlx->settings.res_height);
	if (hud->img.img == NULL)
		exit_error(mlx, 1);
	hud->img.adrr = mlx_get_data_addr(hud->img.img, &hud->img.bits_per_pixel, \
	&hud->img.line_lenght, &hud->img.endian);
	hud->tex.img = mlx_xpm_file_to_image(mlx->mlx, path, &hud->tex.width, \
	&hud->tex.height);
	if (hud->tex.img == NULL)
		exit_error(mlx, 1);
	hud->tex.addr = mlx_get_data_addr(hud->tex.img, &hud->tex.bits_per_pixel, \
	&hud->tex.line_lenght, &hud->tex.endian);
}

void	set_mlx(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, mlx->settings.res_width, \
	mlx->settings.res_height, "bonk");
	if (mlx->win == NULL)
		exit_error(mlx, 1);
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->settings.res_width, \
	mlx->settings.res_height);
	if (mlx->img.img == NULL)
		exit_error(mlx, 1);
	mlx->img.adrr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, \
	&mlx->img.line_lenght, &mlx->img.endian);
	mlx->hud.filter.img = mlx_new_image(mlx->mlx, mlx->settings.res_width, \
	mlx->settings.res_height);
	mlx->hud.filter.adrr = mlx_get_data_addr(mlx->hud.filter.img, \
	&mlx->hud.filter.bits_per_pixel, &mlx->hud.filter.line_lenght, \
	&mlx->hud.filter.endian);
	set_hud_images(mlx, &mlx->hud.can, "./hud/holding_sprite.xpm");
	set_hud_images(mlx, &mlx->hud.drinking, "./hud/drinking.xpm");
	set_hud_images(mlx, &mlx->hud.heart, "./hud/heart.xpm");
	set_hud_images(mlx, &mlx->hud.spriteinv, "./hud/sprite.xpm");
	set_hud_images(mlx, &mlx->hud.holding_gun, "./hud/holding_gun.xpm");
	set_hud_images(mlx, &mlx->hud.shooting_gun, "./hud/shooting_gun.xpm");
}

void	set_c4(t_mlx *mlx)
{
	set_hud_images(mlx, &mlx->hud.c4, "./hud/c4inhand.xpm");
	set_hud_images(mlx, &mlx->hud.cmd, "./hud/c4cmd.xpm");
	set_hud_images(mlx, &mlx->hud.c4inv, "./hud/c4onground.xpm");
	if (get_texture(mlx, &mlx->wallc4, "./hud/c4onwall.xpm") < 0 \
	|| get_texture(mlx, &mlx->destructible_wall, "./hud/walldestructible.xpm") \
	< 0 || get_texture(mlx, &mlx->door, "./textures/doormine.xpm") < 0)
		exit_error(mlx, 1);
}

void	set_player_dir(t_mlx *mlx)
{
	mlx->player.x = mlx->player.x * 64 + 32;
	mlx->player.y = mlx->player.y * 64 + 32;
	if (mlx->player.direction == 'N' || mlx->player.direction == 'S')
	{
		if (mlx->player.direction == 'N')
			mlx->player.a = M_PI_2;
		else
			mlx->player.a = 3 * M_PI_2;
		mlx->player.xdir = cos(mlx->player.a);
		mlx->player.ydir = -sin(mlx->player.a);
	}
	if (mlx->player.direction == 'W' || mlx->player.direction == 'E')
	{
		if (mlx->player.direction == 'W')
			mlx->player.a = M_PI;
		else
			mlx->player.a = 0;
		mlx->player.xdir = cos(mlx->player.a);
		mlx->player.ydir = -sin(mlx->player.a);
	}
}

void	set_everything(t_mlx *mlx)
{
	set_player_dir(mlx);
	set_mlx(mlx);
	set_c4(mlx);
}
