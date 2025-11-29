/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:27:20 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/29 16:49:30 by enchevri         ###   ########lyon.fr   */
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

void	print_fps(void)
{
	const double frame_delay = 1000.0 / 60.0;
	static long frame_count = 0;
	static long fps_start = 0;
	static long frame_start = 0;
	static int fps = 0;
	long frame_time;
	long now;

	if (fps_start == 0)
	{
		fps_start = time_in_ms();
		frame_start = time_in_ms();
	}

	frame_time = time_in_ms() - frame_start;
	if (frame_time < frame_delay)
		usleep((frame_delay - frame_time) * 1000);

	frame_start = time_in_ms();

	attron(2);
	mvprintw(LINES / 2, 0, "FPS: %3d", fps);
	attroff(2);
	refresh();

	frame_count++;
	now = time_in_ms();
	if (now - fps_start >= 1000)
	{
		fps = frame_count;
		frame_count = 0;
		fps_start = now;
	}
}
