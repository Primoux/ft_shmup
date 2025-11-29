/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <gabach@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:44:24 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 20:44:26 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_H
# define PROJECTILE_H

// INCLUDES

#include "linked_list.h"

// STRUCTS

typedef struct s_projectile
{
	int		x;
	int		y;
	char	icon;
	char	direction;
}				t_projectile;

// FUNCS

void	throw_projectil(int row, int column, char icon, char direction, t_list **projectils);
void	actualize_projectiles(t_list **projectiles, int counter);

#endif
