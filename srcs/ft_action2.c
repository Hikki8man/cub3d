//
// Created by Stellar on 02/05/2021.
//

#include "../includes/cub3d.h"

void	footstep(t_mlx *mlx)
{
	time_t	timer;
	int		nb;

	timer = time(NULL);
	if (mlx->move.soundplaying == 0 && mlx->move.crouch == 0 && (mlx->move.w \
	|| mlx->move.s || mlx->move.strafe_right || mlx->move.strafe_left) == 1)
	{
		time(&mlx->move.foot_time);
		nb = rand() % 2;
		if (nb == 0)
			play_sound(mlx, "afplay -v 0.4 ./sounds/footstep.mp3 &");
		if (nb == 1)
			play_sound(mlx, "afplay -v 0.4 ./sounds/footstep2.mp3 &");
		mlx->move.soundplaying = 1;
	}
	if (mlx->move.soundplaying == 1 && timer >= mlx->move.foot_time + 1)
		mlx->move.soundplaying = 0;
}

void	trigger_bomb(t_mlx *mlx)
{
	if (mlx->player.action == 1 && mlx->player.drinking == 0)
	{
		play_sound(mlx, "afplay ./sounds/bombexplode.mp3 &");
		mlx->map.map[mlx->map.bombpos.y][mlx->map.bombpos.x] = '0';
		mlx->player.action = 0;
		mlx->player.plant = 0;
	}
}

void	player_shooting(t_mlx *mlx)
{
	t_enemy	*current_enemy;

	current_enemy = which_enemy(mlx, mlx->ray.m.x, mlx->ray.m.y);
	if (current_enemy->hp > 0)
	{
		current_enemy->hp -= 50;
		play_sound(mlx, "afplay ./sounds/hit.mp3 &");
	}
	if (current_enemy->hp <= 0)
	{
		play_sound(mlx, "afplay ./sounds/ahh.mp3 &");
		mlx->map.map[mlx->ray.m.y][mlx->ray.m.x] = '0';
	}
	mlx->shot = 1;
}

void	pickup_sprite(t_mlx *mlx)
{
	if (mlx->map.map[mlx->player.m.y][mlx->player.m.x] == '3' \
	&& mlx->player.inv.drinks < 5)
	{
		mlx->map.map[mlx->player.m.y][mlx->player.m.x] = '0';
		mlx->player.inv.drinks++;
	}
	if (mlx->map.map[mlx->player.m.y][mlx->player.m.x] == '5' \
	&& mlx->player.inv.c4 < 5)
	{
		mlx->map.map[mlx->player.m.y][mlx->player.m.x] = '0';
		mlx->player.inv.c4++;
	}
}

void	step_on_lego(t_mlx *mlx)
{
	if (mlx->map.map[mlx->player.m.y][mlx->player.m.x] == '4')
	{
		play_sound(mlx, "afplay ./sounds/oof.mp3 &");
		mlx->map.map[mlx->player.m.y][mlx->player.m.x] = '0';
		mlx->player.hp -= 1;
	}
}
