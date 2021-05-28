//
// Created by Stellar on 02/05/2021.
//

#include "../includes/cub3d.h"

void 	door_action(t_mlx *mlx)
{
	if (mlx->map.map[mlx->player.m.y + (int)roundf(mlx->player.ydir)] \
	[mlx->player.m.x + (int)roundf(mlx->player.xdir)] == '7'\
	&& mlx->player.action2 == 1)
	{
		play_sound(mlx, "afplay ./sounds/opendoor.mp3 &");
		mlx->map.map[mlx->player.m.y + (int)roundf(mlx->player.ydir)] \
		[mlx->player.m.x + (int)roundf(mlx->player.xdir)] = '8';
	}
	else if (mlx->map.map[mlx->player.m.y + (int)roundf(mlx->player.ydir)] \
	[mlx->player.m.x + (int)roundf(mlx->player.xdir)] == '8' \
	&& mlx->player.action2 == 1)
	{
		play_sound(mlx, "afplay ./sounds/closedoor.mp3 &");
		mlx->map.map[mlx->player.m.y + (int)roundf(mlx->player.ydir)] \
		[mlx->player.m.x + (int)roundf(mlx->player.xdir)] = '7';
	}
	mlx->player.action2 = 0;
}

void	plant_bomb(t_mlx *mlx)
{
	if (mlx->map.map[mlx->player.m.y + (int)roundf(mlx->player.ydir)] \
	[mlx->player.m.x + (int)roundf(mlx->player.xdir)] == '6' \
	&& mlx->player.drinking == 0)
	{
		play_sound(mlx, "afplay ./sounds/bombplanted.mp3 &");
		mlx->map.bombpos.x = mlx->player.m.x + (int)roundf(mlx->player.xdir);
		mlx->map.bombpos.y = mlx->player.m.y + (int)roundf(mlx->player.ydir);
		mlx->player.inv.c4--;
		mlx->player.plant = 1;
		mlx->player.action = 0;
	}
}

void	drinking_frame(t_mlx *mlx)
{
	time_t	timer;

	timer = time(NULL);
	if (mlx->player.drinking == 1 && timer <= mlx->hud.drinking_time + 2)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, \
		mlx->hud.drinking.img.img, 0, 0);
	}
	if (mlx->player.drinking == 1 && timer > mlx->hud.drinking_time + 2)
		mlx->player.drinking = 0;
}

void 	drink_sprite(t_mlx *mlx)
{
	drinking_frame(mlx);
	if (mlx->player.action == 1 && mlx->player.inv.drinks != 0 \
	&& mlx->player.drinking == 0 && mlx->player.inv.slot2 == 1)
	{
		mlx->player.inv.drinks--;
		if (mlx->player.hp < 5)
			mlx->player.hp++;
		mlx->player.drinking = 1;
		play_sound(mlx, "afplay ./sounds/drink.mp3 &");
		time(&mlx->hud.drinking_time);
	}
}

void	action(t_mlx *mlx)
{
	pickup_sprite(mlx);
	step_on_lego(mlx);
	door_action(mlx);
	drink_sprite(mlx);
	door_action(mlx);
	footstep(mlx);
}
