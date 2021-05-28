//
// Created by Stellar on 02/05/2021.
//

#include "../includes/cub3d.h"

void	put_gun(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->hud.holding_gun.img.img, \
	0, mlx->settings.res_height / 2);
}

void	put_shooting_gun(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->hud.shooting_gun.img.img, \
	0, mlx->settings.res_height / 2);
}

void	hud_handler(t_mlx *mlx)
{
	if (mlx->player.inv.drinks > 0 && mlx->player.drinking == 0 \
	&& mlx->player.inv.slot2 == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->hud.can.img.img, 0, 0);
	}
	if (mlx->player.inv.c4 > 0 && mlx->player.inv.slot3 == 1 \
	&& mlx->player.plant == 0 && mlx->player.drinking == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->hud.c4.img.img, 0, 0);
		if (mlx->player.action == 1)
			plant_bomb(mlx);
	}
	if (mlx->player.inv.slot3 == 1 && mlx->player.plant == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->hud.cmd.img.img, 0, 0);
		trigger_bomb(mlx);
	}
	if (mlx->player.inv.slot1 == 1 && mlx->player.drinking == 0)
	{
		if (mlx->player.shooting == 0)
			put_gun(mlx);
		else
			put_shooting_gun(mlx);
	}
}

void	put_hud(t_mlx *mlx)
{
	hud_handler(mlx);
	put_heart(mlx);
	put_c4(mlx);
	put_sprite(mlx);
}
