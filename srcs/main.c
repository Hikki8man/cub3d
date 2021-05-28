#include "../includes/cub3d.h"

int 	render_next_frame(t_mlx *mlx)
{
	playermove(mlx);
	mousemove(mlx);
	ray_cast(mlx);
	draw_minimap(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->hud.filter.img, 0, 0);
	action(mlx);
	put_hud(mlx);
	mlx->player.shooting = 0;
	mlx->player.action = 0;
	if (mlx->player.hp == 0)
		exit_sucess(mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	init_all(&mlx);
	if (ac == 2)
	{
		args(&mlx, av[1]);
		parsing(&mlx);
		set_everything(&mlx);
		draw_hud_images(&mlx);
		mlx_hook(mlx.win, 2, 1L << 0, key_press, &mlx);
		mlx_hook(mlx.win, 17, 1L << 15, exit_sucess, &mlx);
		mlx_hook(mlx.win, 3, 1L << 1, key_release, &mlx);
		mlx_hook(mlx.win, 4, 1L << 2, button, &mlx);
		mlx_loop_hook(mlx.mlx, render_next_frame, &mlx);
		mlx_loop(mlx.mlx);
	}
	exit_error(&mlx, 6);
}
