/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <gabach@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:41:56 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 15:38:26 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	game(void)
{
	int			c;
	t_player	player;

	initscr();
	box(stdscr, ACS_VLINE, ACS_HLINE);

	raw();
	noecho();
	timeout(0);
	nodelay(stdscr, TRUE);
	curs_set(0);

	player = init_player();
	while (c != 'q')
	{
		c = getch();
		player_action(c, &player);
		refresh();
		usleep(1000 / 60);
	}
	endwin();
	return (0);
}
