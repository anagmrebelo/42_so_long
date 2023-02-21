/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:21:50 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/04 10:19:28 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	update_enemy_pos(t_vars *vars, int pos)
{
	if (vars->nl[pos] == 'X')
		terminate_game(vars, create_trgb(255, 255, 0, 0), "You lost :(");
	else if (vars->nl[pos])
		vars->nl[pos] = 'K';
}

static void	vars_init(t_vars *vars, int *x, int *y, int *pos)
{
	*pos = find_k(vars, *pos);
	*x = *pos % (vars->mem->cols + 1) * TILE_WIDTH;
	*y = *pos / (vars->mem->cols + 1) * TILE_HEIGHT;
}

static void	aux_move_enemy(t_vars *vars, int *coor, int pos, int i)
{
	if (i == MOVE_ENEM && vars->nl[pos + 1] != '1')
	{	
		put_background(vars, coor[0], coor[1]);
		vars->nl[pos] = '0';
		pos += 1;
		update_enemy_pos(vars, pos);
	}
	else if (i == 2 * MOVE_ENEM && vars->nl[pos - 1] != '1')
	{
		put_background(vars, coor[0], coor[1]);
		vars->nl[pos] = '0';
		pos -= 1;
		update_enemy_pos(vars, pos);
	}
}

void	move_enemy(t_vars *vars)
{
	static int	i;
	static int	pos;
	int			coor[2];

	i++;
	while (find_k(vars, pos) != -1 && vars->game_stat == 1)
	{
		vars_init(vars, &coor[0], &coor[1], &pos);
		aux_move_enemy(vars, coor, pos, i);
		pos += 32;
	}
	if (i == 2 * MOVE_ENEM)
		i = 0;
	pos = 0;
}

int	inactive(t_vars *vars)
{
	animate_enemy(vars);
	move_enemy(vars);
	return (0);
}
