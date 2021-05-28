//
// Created by Johan Chevet on 5/10/21.
//

#include "../includes/cub3d.h"

void	init_img_img(t_mlx *mlx)
{
	mlx->img.img = NULL;
	mlx->tex_e.img = NULL;
	mlx->tex_n.img = NULL;
	mlx->tex_s.img = NULL;
	mlx->tex_w.img = NULL;
	mlx->destructible_wall.img = NULL;
	mlx->hud.can.img.img = NULL;
	mlx->hud.drinking.img.img = NULL;
	mlx->hud.heart.img.img = NULL;
	mlx->hud.c4.img.img = NULL;
	mlx->hud.c4inv.img.img = NULL;
	mlx->hud.cmd.img.img = NULL;
	mlx->hud.holding_gun.img.img = NULL;
	mlx->hud.shooting_gun.img.img = NULL;
	mlx->hud.spriteinv.img.img = NULL;
	mlx->wallc4.img = NULL;
	mlx->door.img = NULL;
	mlx->hud.filter.img = NULL;
}

void	init_tex_img(t_mlx *mlx)
{
	mlx->sprite.tex2.img = NULL;
	mlx->sprite.tex3.img = NULL;
	mlx->sprite.tex4.img = NULL;
	mlx->sprite.tex5.img = NULL;
	mlx->hud.can.tex.img = NULL;
	mlx->hud.drinking.tex.img = NULL;
	mlx->hud.heart.tex.img = NULL;
	mlx->hud.c4.tex.img = NULL;
	mlx->hud.c4inv.tex.img = NULL;
	mlx->hud.cmd.tex.img = NULL;
	mlx->hud.holding_gun.tex.img = NULL;
	mlx->hud.shooting_gun.tex.img = NULL;
	mlx->hud.spriteinv.tex.img = NULL;
}

void 	init_mlx(t_mlx *mlx)
{
	mlx->win = NULL;
	mlx->img.img = NULL;
}
