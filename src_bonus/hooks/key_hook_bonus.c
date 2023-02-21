/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:14:10 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/04 10:38:32 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	key_limits(t_vars *vars, int x, int y)
{
	if (vars->nl[(y / TILE_HEIGHT) * (vars->mem->cols + 1)
			+ (x / TILE_WIDTH)] == '1')
		return (0);
	else if (vars->nl[(y / TILE_HEIGHT) * (vars->mem->cols + 1)
			+ (x / TILE_WIDTH)] == 'C')
	{
		vars->mem->collectible--;
		vars->nl[(y / TILE_HEIGHT) * (vars->mem->cols + 1)
			+ (x / TILE_WIDTH)] = '0';
	}
	return (1);
}

static void	init_vars(t_vars *vars, int *x, int *y, int *pos)
{
		*x = find_piece('P', 'x', vars) * TILE_WIDTH;
		*y = find_piece('P', 'y', vars) * TILE_HEIGHT;
		*pos = find_piece('P', 'p', vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	static int	x;
	static int	y;
	static int	pos;

	if (!x && !y)
		init_vars(vars, &x, &y, &pos);
	exit_hook(keycode, vars);
	if (vars->game_stat == 0)
		return (0);
	else if (keycode == UP
		&& key_limits(vars, x, y - TILE_HEIGHT) == 1)
		keycode_up(vars, &x, &y, &pos);
	else if (keycode == LEFT
		&& key_limits(vars, x - TILE_WIDTH, y) == 1)
		keycode_left(vars, &x, &y, &pos);
	else if (keycode == DOWN
		&& key_limits(vars, x, y + TILE_HEIGHT) == 1)
		keycode_down(vars, &x, &y, &pos);
	else if (keycode == RIGHT
		&& key_limits(vars, x + TILE_WIDTH, y) == 1)
		keycode_right(vars, &x, &y, &pos);
	eval_finish(vars, x, y);
	return (0);
}
