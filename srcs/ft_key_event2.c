//
// Created by Johan Chevet on 5/6/21.
//

#include "../includes/cub3d.h"

void 	action_keys(int keycode, t_mlx *mlx)
{
	if (keycode == 14)
		mlx->player.action = 1;
	if (keycode == 3 && mlx->player.keypress == 0)
	{
		mlx->player.action2 = 1;
		mlx->player.keypress = 1;
	}
	if (keycode == 49 && mlx->player.keypress == 0 \
	&& mlx->player.inv.slot1 == 1)
	{
		mlx->player.shooting = 1;
		mlx->player.keypress = 1;
		play_sound(mlx, "afplay ./sounds/pan.mp3 &");
	}
}

void	hud_keys2(int keycode, t_mlx *mlx)
{
	if (keycode == 20)
	{
		if (mlx->player.inv.slot3 == 0)
		{
			mlx->player.inv.slot3 = 1;
			mlx->player.inv.slot2 = 0;
			mlx->player.inv.slot1 = 0;
		}
		else
			mlx->player.inv.slot3 = 0;
	}
	if (keycode == 50)
	{
		if (mlx->move.mouse == 0)
			mlx->move.mouse = 1;
		else
			mlx->move.mouse = 0;
	}
}

void	hud_keys(int keycode, t_mlx *mlx)
{
	if (keycode == 18)
	{
		if (mlx->player.inv.slot1 == 0)
		{
			mlx->player.inv.slot1 = 1;
			mlx->player.inv.slot2 = 0;
			mlx->player.inv.slot3 = 0;
			play_sound(mlx, "afplay ./sounds/kruikrui.mp3 &");
		}
		else
			mlx->player.inv.slot1 = 0;
	}
	if (keycode == 19)
	{
		if (mlx->player.inv.slot2 == 0)
		{
			mlx->player.inv.slot1 = 0;
			mlx->player.inv.slot2 = 1;
			mlx->player.inv.slot3 = 0;
		}
		else
			mlx->player.inv.slot2 = 0;
	}
	hud_keys2(keycode, mlx);
}

int 	button(int but, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (but == 1 && mlx->move.mouse == 1 && mlx->player.inv.slot1 == 1)
	{
		play_sound(mlx, "afplay ./sounds/pan.mp3 &");
		mlx->player.shooting = 1;
	}
	return (0);
}
