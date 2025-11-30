/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:08:38 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 17:56:45 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "ui.h"

void	print_time(t_game game)
{
    int max_y, max_x;
    char time_str[20];
    int total_seconds, time_s, time_m;
    
    total_seconds = game.player.time / FRAME_RATE;
    time_m = total_seconds / 60;
    time_s = total_seconds % 60;
    
    getmaxyx(time_win, max_y, max_x);
    mvwprintw(time_win, max_y / 2 - 1, max_x / 2 - 2, "TIME");
    
    sprintf(time_str, "%02d:%02d", time_m, time_s);  
    mvwprintw(time_win, max_y / 2 + 1, max_x / 2 - 2, "%s", time_str);
    wrefresh(time_win);
}
