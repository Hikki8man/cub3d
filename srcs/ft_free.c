//
// Created by Johan Chevet on 5/6/21.
//

#include "../includes/cub3d.h"

void 	free_tex(t_mlx *mlx)
{
	if (mlx->tex_s.img)
		mlx_destroy_image(mlx->mlx, mlx->tex_s.img);
	if (mlx->tex_e.img)
		mlx_destroy_image(mlx->mlx, mlx->tex_e.img);
	if (mlx->tex_w.img)
		mlx_destroy_image(mlx->mlx, mlx->tex_w.img);
	if (mlx->tex_n.img)
		mlx_destroy_image(mlx->mlx, mlx->tex_n.img);
	if (mlx->sprite.tex2.img)
		mlx_destroy_image(mlx->mlx, mlx->sprite.tex2.img);
	if (mlx->sprite.tex3.img)
		mlx_destroy_image(mlx->mlx, mlx->sprite.tex3.img);
	if (mlx->sprite.tex4.img)
		mlx_destroy_image(mlx->mlx, mlx->sprite.tex4.img);
	if (mlx->sprite.tex5.img)
		mlx_destroy_image(mlx->mlx, mlx->sprite.tex5.img);
	if (mlx->wallc4.img)
		mlx_destroy_image(mlx->mlx, mlx->wallc4.img);
	if (mlx->destructible_wall.img)
		mlx_destroy_image(mlx->mlx, mlx->destructible_wall.img);
	if (mlx->door.img)
		mlx_destroy_image(mlx->mlx, mlx->door.img);
}

void	destroy_img_img(t_mlx *mlx)
{
	if (mlx->hud.spriteinv.img.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.spriteinv.img.img);
	if (mlx->hud.shooting_gun.img.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.shooting_gun.img.img);
	if (mlx->hud.holding_gun.img.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.holding_gun.img.img);
	if (mlx->hud.filter.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.filter.img);
	if (mlx->hud.c4inv.img.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.c4inv.img.img);
	if (mlx->hud.c4.img.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.c4.img.img);
	if (mlx->hud.can.img.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.can.img.img);
	if (mlx->hud.cmd.img.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.cmd.img.img);
	if (mlx->hud.heart.img.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.heart.img.img);
	if (mlx->hud.drinking.img.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.drinking.img.img);
}

void 	destroy_tex_img(t_mlx *mlx)
{
	if (mlx->hud.spriteinv.tex.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.spriteinv.tex.img);
	if (mlx->hud.shooting_gun.tex.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.shooting_gun.tex.img);
	if (mlx->hud.holding_gun.tex.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.holding_gun.tex.img);
	if (mlx->hud.c4inv.tex.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.c4inv.tex.img);
	if (mlx->hud.c4.tex.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.c4.tex.img);
	if (mlx->hud.can.tex.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.can.tex.img);
	if (mlx->hud.cmd.tex.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.cmd.tex.img);
	if (mlx->hud.heart.tex.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.heart.tex.img);
	if (mlx->hud.drinking.tex.img)
		mlx_destroy_image(mlx->mlx, mlx->hud.drinking.tex.img);
}

void 	print_err(int err)
{
	if (err == -1 || err == -2)
		ft_putstr_fd("Error\nFile descriptor failed\n", 2);
	if (err == 0 || err == 1)
		ft_putstr_fd("Error\nMalloc failed\n", 2);
	if (err == 2)
		ft_putstr_fd("Error\nWrong setting\n", 2);
	if (err == 3)
		ft_putstr_fd("Error\nMap invalid\n", 2);
	if (err == 4)
		ft_putstr_fd("Error\nMap file invalid\n", 2);
	if (err == 6)
		ft_putstr_fd("Error\nWrong argument\n", 2);
	if (err == 7)
		ft_putstr_fd("Error\nMultiple direction\n", 2);
}
