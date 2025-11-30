/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:27:20 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/29 18:07:08 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include <sys/time.h>

long	time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_fps(int c)
{
	const long	target_frame_time = 16667;
	static long	frame_count = 0;
	static long	fps_start = 0;
	static long	frame_start = 0;
	static int	fps = 0;
	static int	fps_color = 1;
	long		elapsed;
	long		sleep_time;
	long		now;

	now = time_in_ms();
	if (fps_start == 0)
	{
		fps_start = now;
		frame_start = now;
	}
	if (c == KEY_F(3))
		fps_color = (fps_color == 2) ? 1 : 2;
	wattron(stats_win, COLOR_PAIR(fps_color));
	mvwprintw(stats_win, 0, 1, "FPS: %3d", fps);
	wattroff(stats_win, COLOR_PAIR(fps_color));
	wrefresh(stats_win);
	elapsed = (time_in_ms() - frame_start) * 1000;
	sleep_time = target_frame_time - elapsed;
	if (sleep_time > 0)
		usleep(sleep_time);
	frame_start = time_in_ms();
	frame_count++;
	if (frame_start - fps_start >= 1000)
	{
		fps = frame_count;
		frame_count = 0;
		fps_start = frame_start;
	}
}
