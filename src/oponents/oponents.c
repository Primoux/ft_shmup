/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oponents.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <gabach@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:24:20 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 21:24:22 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "oponents.h"
#include "player.h"

void	actualize_oponent(t_list **oponents, int counter, t_list **projectiles)
{
	t_list		*last;
	t_list		*current;
	t_oponent	*oponent;

	if (counter % 50 == 0)
		spawn_oponent(oponents);
	if (*oponents == NULL || !oponents || counter % 10 != 0)
		return ;
	current = *oponents;
	last = NULL;
	while (current)
	{
		oponent = (t_oponent*)current->content;
		if ((rand() % 100 + 1) % 10 == 0)
			throw_projectil((oponent->y), (oponent->x), '-', (oponent->direction), projectiles);
		if (obj_move(&(oponent->y), &(oponent->x), (oponent->icon), (oponent->direction)) == -1)
		{
			move((oponent->y), (oponent->x));
			addch(' ');
			if (last)
			{
				last->next = NULL;
				ft_lstadd_back(oponents, current->next);
				ft_lstdelone(current, free);
				current = last->next;
			}
			else
			{
				*oponents = current->next;
				ft_lstdelone(current, free);
				current = *oponents;
			}
		}
		else {
			last = current;
			current = current->next;
		}
	}
}

t_oponent	*new_oponent(int row, int col, char icon, char direction)
{
	t_oponent *oponent;

	oponent = malloc(sizeof(t_oponent));
	if (!oponent)
		return (NULL);
	oponent->x = col;
	oponent->y = row;
	oponent->direction = direction;
	oponent->icon = icon;
	return (oponent);
}

void	spawn_oponent(t_list **oponents)
{
	t_oponent	*oponent;
	t_list		*list;

	oponent = new_oponent(((rand() % (END_LINE - START_LINE)) + START_LINE), END_COL, '&', 'l');
	if (!oponent)
		return ;
	list = ft_lstnew((void*)oponent);
	if (!list)
		return ;
	ft_lstadd_back(oponents, list);
}
