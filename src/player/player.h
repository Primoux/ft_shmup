/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <gabach@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:27:37 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 16:37:22 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

// INCLUDES

# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>

// CONST

# define START_COL (1)
# define START_LINE (1)
# define END_COL (COLS - 2)
# define END_LINE (LINES - 2)

// STRUCTS

typedef struct	s_player
{
	int		x;
	int		y;
	char	icon;
}				t_player;

// FUNCS

int			game(void);

t_player	init_player(void);
void	player_action(int c, t_player *player);

#endif
