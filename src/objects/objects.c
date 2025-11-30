/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <gabach@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:35:46 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 17:44:49 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "shmup.h"

int	obj_move(int *row, int *col, char icon, char direction)
{
	if (direction == 'r')
	{
		if (*col == END_COL) return (-1);
		move(*row, *col);
		addch(' ');
		(*col)++;
		move(*row, *col);
		addch(icon);
	}
	else if (direction == 'l')
	{
		if (*col == START_COL) return (-1);
		move(*row, *col);
		addch(' ');
		(*col)--;
		move(*row, *col);
		addch(icon);
	}
	else if (direction == 'u')
	{
		if (*row == START_LINE) return (-1) ;
		move(*row, *col);
		addch(' ');
		(*row)--;
		move(*row, *col);
		addch(icon);
	}
	else if (direction == 'd')
	{
		if (*row == END_LINE) return (-1) ;
		move(*row, *col);
		addch(' ');
		(*row)++;
		move(*row, *col);
		addch(icon);
	}
	return (0);
}
