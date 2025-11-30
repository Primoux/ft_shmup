/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:31:56 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 17:17:25 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "projectile.h"
#include "objects.h"

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

void	player_action(int c, t_player *player, t_list **projectile)
{
	if (c != -1)
	{
		if (c == 'd')
		{
			obj_move(&player->y, &player->x, '>', 'r');
			player->direction = 'r';
		}
		if (c == 'a')
		{
			obj_move(&player->y, &player->x, '<', 'l');
			player->direction = 'l';
		}
		if (c == 'w')
		{
			obj_move(&player->y, &player->x, '^', 'u');
			player->direction = 'u';
		}
		if (c == 's')
		{
			obj_move(&player->y, &player->x, 'v', 'd');
			player->direction = 'd';
		}
		if (c == ' ')
			throw_projectil(player->y, player->x, 'o', player->direction, projectile);
	}
}
