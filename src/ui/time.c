/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:08:38 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 17:26:24 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "ui.h"

void	print_time(t_game game)

{
	int max_y, max_x;
	int time_len;
	char score_str[20];
	int time_s, time_m;
	time_m = game.player.time / (FRAME_RATE * 60);
	time_s = game.player.time / FRAME_RATE - (time_m * 60);
	getmaxyx(time_win, max_y, max_x);

	mvwprintw(time_win, max_y / 2 - 1, max_x / 2 - 2, "TIME");
	sprintf(score_str, "%d : %d", time_m, time_s);
	time_len = strlen(score_str);
	mvwprintw(time_win, max_y / 2 + 1, max_x / 2 - (time_len / 2), "%s",
		score_str);
	wrefresh(time_win);
}
