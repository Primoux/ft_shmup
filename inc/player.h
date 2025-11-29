/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:27:37 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 17:07:35 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

// INCLUDES

# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>

// CONST

# define START_COL (COLS / 6 + 1)
# define START_LINE (1)
# define END_COL (COLS - 3)
# define END_LINE (LINES - 3)

// STRUCTS

typedef struct s_player
{
	int		x;
	int		y;
	char	icon;
	int		live;
	int		score;
}			t_player;

// FUNCS

int			game_loop(t_player *player);

t_player	init_player(void);
void		player_action(int c, t_player *player);

#endif
