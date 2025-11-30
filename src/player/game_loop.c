/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:38:26 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 11:26:33 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "oponents.h"
#include "player.h"
#include "projectile.h"
#include "shmup.h"
#include "ui.h"

int	game_loop(t_game *game)
{
	int		counter;
	int		ch;
	t_list	*projectiles;
	t_list	*oponents;

	counter = 0;
	ch = 0;
	projectiles = NULL;
	oponents = NULL;
	game->player = init_player();
	game->player.invincibility = 200;
	while (ch != 'q')
	{
		ch = getch();
		actualize_projectiles(&projectiles, counter);
		actualize_oponent(&oponents, counter, &projectiles);
		player_action(ch, &game->player, &projectiles);
		print_ui(*game, ch);
		refresh();
		counter++;
		game->player.invincibility--;
	}
	return (0);
}
