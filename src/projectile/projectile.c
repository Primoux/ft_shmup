/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <gabach@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:45:38 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 17:45:40 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "objects.h"
#include "projectile.h"

void	actualize_projectiles(t_list **projectiles, int counter)
{
	t_list		*last;
	t_list		*current;
	t_projectile	*projectile;

	if (*projectiles == NULL || !projectiles)
		return ;
	current = *projectiles;
	last = NULL;
	projectile = (t_projectile*)current->content;
	while (current)
	{
		projectile = (t_projectile*)current->content;
		if (obj_move(&(projectile->y), &(projectile->x), (projectile->icon), (projectile->direction)) == -1)
		{
			move((projectile->y), (projectile->x));
			addch(' ');
			if (last)
			{
				last->next = NULL;
				ft_lstadd_back(projectiles, current->next);
				ft_lstdelone(current, free);
				current = last->next;
			}
			else
			{
				*projectiles = current->next;
				ft_lstdelone(current, free);
				current = *projectiles;
			}
		}
		else {
			last = current;
			current = current->next;
		}
	}
}

t_projectile	*new_projectil(int row, int col, char icon, char direction)
{
	t_projectile *projectil;

	projectil = malloc(sizeof(t_projectile));
	if (!projectil)
		return (NULL);
	projectil->x = col;
	projectil->y = row;
	projectil->direction = direction;
	projectil->icon = icon;
	return (projectil);
}

void	throw_projectil(int row, int column, char icon, char direction, t_list **projectils)
{
	t_projectile	*projectil;
	t_list		*list;

	projectil = new_projectil(row, column, icon, direction);
	if (!projectil)
		return ;
	list = ft_lstnew((void*)projectil);
	if (!list)
		return ;
	ft_lstadd_back(projectils, list);
}
