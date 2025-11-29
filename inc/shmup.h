/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:50:08 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/29 17:04:17 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHMUP_H
# define SHMUP_H

// INCLUDES

# include "player.h"
# include <ncurses.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// DEFINE

# define STAT_WIDTH (COLS / 6)
# define GAME_WIDTH (5 * STAT_WIDTH)

// GLOBAL

extern WINDOW *stats_win, *game_win;
extern WINDOW *live_win, *score_win, *time_win;

// STRUCTS

typedef struct s_game
{
	int			time;
	t_player	player;
}				t_game;

// FUNCS

void			init(void);
void			print_fps(void);

#endif
