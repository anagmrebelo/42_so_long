/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:58:42 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/05 15:30:16 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	up_keycode(t_vars *vars, int *x, int *y)
{		
	put_background(vars, *x, *y);
	*y -= TILE_HEIGHT;
	move_player(vars, *x, *y, 6);
}

void	left_keycode(t_vars *vars, int *x, int *y)
{
	put_background(vars, *x, *y);
	*x -= TILE_WIDTH;
	move_player(vars, *x, *y, 5);
}

void	down_keycode(t_vars *vars, int *x, int *y)
{
	put_background(vars, *x, *y);
	*y += TILE_HEIGHT;
	move_player(vars, *x, *y, 7);
}

void	right_keycode(t_vars *vars, int *x, int *y)
{
	put_background(vars, *x, *y);
	*x += TILE_WIDTH;
	move_player(vars, *x, *y, 4);
}
