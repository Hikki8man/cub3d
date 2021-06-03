/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_lst_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:59:22 by jchevet           #+#    #+#             */
/*   Updated: 2021/06/03 13:49:19 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_sprite_list	*new_elem(void)
{
	t_sprite_list	*list;

	list = (t_sprite_list *)malloc(sizeof(t_sprite_list));
	if (!list)
		return (NULL);
	list->next = NULL;
	return (list);
}

void	add_front(t_sprite_list **lst, t_sprite_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	free_sprite_list(t_mlx *mlx)
{
	t_sprite_list	*tmp;

	while (mlx->sprite.list)
	{
		tmp = mlx->sprite.list->next;
		free(mlx->sprite.list);
		mlx->sprite.list = tmp;
	}
}
