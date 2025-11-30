/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:11:48 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 11:57:48 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "ui.h"

void	print_ui(t_game game, int ch)
{
	print_fps(ch);
	print_score(game);
	print_time(game);
	print_lives(game);
	if (game.player.invincibility <= 0)
	{
		render_box(score_win, 1);
		render_box(game_win, 1);
		render_box(time_win, 1);
		render_box(lives_win, 1);
	}
	else
	{
		if (game.player.invincibility % 30 < 10)
		{
			render_box(score_win, 4);
			render_box(game_win, 4);
			render_box(time_win, 4);
			render_box(lives_win, 4);
		}
		else
		{
			render_box(score_win, 3);
			render_box(game_win, 3);
			render_box(time_win, 3);
			render_box(lives_win, 3);
		}
	}
}
