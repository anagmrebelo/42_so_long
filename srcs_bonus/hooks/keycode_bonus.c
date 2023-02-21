/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:58:42 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 23:41:45 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	keycode_up(t_vars *vars, int *x, int *y, int *pos)
{		
	put_background(vars, *x, *y);
	*y -= TILE_HEIGHT;
	move_player(vars, *x, *y, 6);
	vars->nl[*pos] = '0';
	*pos = *pos - vars->mem->cols - 1;
	move_x(vars, *pos);
}

void	keycode_left(t_vars *vars, int *x, int *y, int *pos)
{
	put_background(vars, *x, *y);
	*x -= TILE_WIDTH;
	move_player(vars, *x, *y, 5);
	vars->nl[*pos] = '0';
	*pos -= 1;
	move_x(vars, *pos);
}

void	keycode_down(t_vars *vars, int *x, int *y, int *pos)
{
	put_background(vars, *x, *y);
	*y += TILE_HEIGHT;
	move_player(vars, *x, *y, 7);
	vars->nl[*pos] = '0';
	*pos += vars->mem->cols + 1;
	move_x(vars, *pos);
}

void	keycode_right(t_vars *vars, int *x, int *y, int *pos)
{
	put_background(vars, *x, *y);
	*x += TILE_WIDTH;
	move_player(vars, *x, *y, 4);
	vars->nl[*pos] = '0';
	*pos += 1;
	move_x(vars, *pos);
}

void	move_x(t_vars *vars, int pos)
{
	if (vars->nl[pos] != 'E' && vars->nl[pos] != 'K')
			vars->nl[pos] = 'X';
}
