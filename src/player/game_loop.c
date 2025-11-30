/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:38:26 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 18:07:32 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "player.h"

int	game_loop(t_player *player)
{
	int			c = 0;

	raw();
	noecho();
	timeout(0);
	nodelay(stdscr, TRUE);
	curs_set(0);

	*player = init_player();
	while (c != 'q')
	{
		c = getch();
		player_action(c, player);
		print_fps(c);
		refresh();
	}
	return (0);
}
