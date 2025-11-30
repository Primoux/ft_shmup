/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:00:17 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/29 18:06:20 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

WINDOW *stats_win, *game_win;
WINDOW *live_win, *score_win, *time_win;

void	init_colors(void)
{
	start_color();
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
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
	wattron(live_win, COLOR_PAIR(1));
	box(live_win, ACS_VLINE, ACS_HLINE);
	wattroff(live_win, COLOR_PAIR(1));
	wattron(time_win, COLOR_PAIR(1));
	box(time_win, ACS_VLINE, ACS_HLINE);
	wattroff(time_win, COLOR_PAIR(1));
	wattron(score_win, COLOR_PAIR(1));
	box(score_win, ACS_VLINE, ACS_HLINE);
	wattroff(score_win, COLOR_PAIR(1));
	wattron(game_win, COLOR_PAIR(1));
	box(game_win, ACS_VLINE, ACS_HLINE);
	wattroff(game_win, COLOR_PAIR(1));
}

void	init(void)
{
	initscr();
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Error\nYour terminal does not support color\n");
		exit(1);
	}
	init_colors();  // init color pairs
	init_windows(); // init different sub-windows
	noecho();
	cbreak();
	keypad(stdscr, true);
	halfdelay(1);
	curs_set(0);
	halfdelay(1);
}
