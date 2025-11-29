
#ifndef OPONENTS_H
# define OPONENTS_H

// INCLUDES

#include "linked_list.h"
#include "projectile.h"

// STRUCTS

typedef struct s_oponent
{
	int		x;
	int		y;
	char	icon;
	char	direction;
}				t_oponent;

// FUNCS

void		spawn_oponent(t_list **oponents);
t_oponent	*new_oponent(int row, int col, char icon, char direction);
void	actualize_oponent(t_list **oponents, int counter, t_list **projectiles);

#endif
