/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:00:17 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/29 16:42:52 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

WINDOW *stats_win, *game_win;
WINDOW *live_win, *score_win, *time_win;

void	init_colors(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE); // Game: bleu
	init_pair(2, COLOR_BLACK, COLOR_WHITE); // Game: bleu
}

void	init_windows(void)
{
	stats_win = subwin(stdscr, LINES, STAT_WIDTH, 0, 0);
	live_win = subwin(stats_win, LINES / 3, STAT_WIDTH, 0, 0);
	score_win = subwin(stats_win, LINES / 3, STAT_WIDTH, LINES / 3, 0);
	time_win = subwin(stats_win, LINES / 3, STAT_WIDTH, LINES / 3 * 2, 0);
	if (LINES % 3 != 0)
		game_win = subwin(stdscr, LINES - 1, GAME_WIDTH, 0, STAT_WIDTH);
	else
		game_win = subwin(stdscr, LINES, GAME_WIDTH, 0, STAT_WIDTH);
	wattron(live_win, COLOR_PAIR(1)); // Bleu
	box(live_win, ACS_VLINE, ACS_HLINE);
	wattroff(live_win, COLOR_PAIR(1));
	wattron(time_win, COLOR_PAIR(1)); // Bleu
	box(time_win, ACS_VLINE, ACS_HLINE);
	wattroff(time_win, COLOR_PAIR(1));
	wattron(score_win, COLOR_PAIR(1)); // Bleu
	box(score_win, ACS_VLINE, ACS_HLINE);
	wattroff(score_win, COLOR_PAIR(1));
	wattron(game_win, COLOR_PAIR(1)); // Bleu
	box(game_win, ACS_VLINE, ACS_HLINE);
	wattroff(game_win, COLOR_PAIR(1));
}

void	init(void)
{
	initscr();
	init_colors();
	init_windows();
	noecho();
	cbreak();
	halfdelay(1);
	curs_set(0);
	halfdelay(1);
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
}
