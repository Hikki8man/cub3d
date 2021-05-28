//
// Created by Johan Chevet on 5/6/21.
//
#include "../includes/cub3d.h"

void	free_enemy_list(t_mlx *mlx)
{
	t_enemy	*tmp;

	while (mlx->enemy_list)
	{
		tmp = mlx->enemy_list->next;
		free(mlx->enemy_list);
		mlx->enemy_list = tmp;
	}
}

int	add_front_enemy(t_enemy **lst, int i, int j)
{
	t_enemy	*enemy;

	enemy = new_enemy(i, j);
	if (enemy == NULL)
		return (-1);
	enemy->next = *lst;
	*lst = enemy;
	return (1);
}

t_enemy	*new_enemy(int x, int y)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->pos.x = x;
	enemy->pos.y = y;
	enemy->hp = 100;
	enemy->next = NULL;
	return (enemy);
}

t_enemy	*which_enemy(t_mlx *mlx, int x, int y)
{
	t_enemy	*enemy;

	enemy = mlx->enemy_list;
	while (enemy != NULL)
	{
		if (enemy->pos.x == x && enemy->pos.y == y)
			return (enemy);
		enemy = enemy->next;
	}
	return (enemy);
}
