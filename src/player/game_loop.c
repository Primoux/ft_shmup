/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:38:26 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 10:02:00 by enchevri         ###   ########lyon.fr   */
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


	*player = init_player();
	while (ch != 'q')
	{
		ch = getch();
		actualize_projectiles(&projectiles, counter);
		actualize_oponent(&oponents, counter, &projectiles);
		player_action(ch, player, &projectiles);
		print_fps(ch);
		refresh();
		counter++;
	}
	return (0);
}
