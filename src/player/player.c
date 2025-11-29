/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <gabach@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:31:56 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 16:38:58 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	init_player(void)
{
	t_player	player;

	player.x = START_COL + 5;
	player.y = LINES / 2;
	player.icon = '>';

	move(player.y, player.x);
	addch(player.icon);

	refresh();

	return (player);
}

void	obj_moov(int *row, int *col, char icon, char direction)
{
	if (direction == 'r')
	{
		if (*col == END_COL) return ;
		move(*row, *col);
		addch(' ');
		(*col)++;
		move(*row, *col);
		addch(icon);
	}
	else if (direction == 'l')
	{
		if (*col == START_COL) return ;
		move(*row, *col);
		addch(' ');
		(*col)--;
		move(*row, *col);
		addch(icon);
	}
	else if (direction == 'u')
	{
		if (*row == START_LINE) return ;
		move(*row, *col);
		addch(' ');
		(*row)--;
		move(*row, *col);
		addch(icon);
	}
	else if (direction == 'd')
	{
		if (*row == END_LINE) return ;
		move(*row, *col);
		addch(' ');
		(*row)++;
		move(*row, *col);
		addch(icon);
	}
}


void	player_shoot(t_player *player)
{
	
}

void	player_action(int c, t_player *player)
{
		if (c != -1)
		{
			if (c == 'd')
				obj_moov(&player->y, &player->x, '>', 'r');
			if (c == 'a')
				obj_moov(&player->y, &player->x, '<', 'l');
			if (c == 'w')
				obj_moov(&player->y, &player->x, '^', 'u');
			if (c == 's')
				obj_moov(&player->y, &player->x, 'v', 'd');
		}
}
