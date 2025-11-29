/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:38:26 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 17:07:04 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "projectile.h"
#include "player.h"
#include "oponents.h"

int	game_loop(t_player *player)
{
	int			counter = 0;
	int			ch = 0;
	t_list		*projectiles = NULL;
	t_list		*oponents = NULL;

	initscr();
	box(stdscr, ACS_VLINE, ACS_HLINE);

	noecho();
	timeout(0);
	nodelay(stdscr, TRUE);
	curs_set(0);

	*player = init_player();
	while (ch != 'q')
	{
		ch = getch();
		actualize_projectiles(&projectiles, counter);
		actualize_oponent(&oponents, counter, &projectiles);
		player_action(ch, player, &projectiles);
		refresh();
		usleep(1000000 / 60);
		counter++;
	}
	endwin();
	return (0);
}
