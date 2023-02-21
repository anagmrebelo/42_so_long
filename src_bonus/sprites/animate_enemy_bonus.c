/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:22:40 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/04 12:22:45 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	put_fire(t_vars *vars, int fire_pos, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img_stock[fire_pos].img_ptr, x * TILE_WIDTH,
		y * TILE_HEIGHT);
}

void	animate_enemy(t_vars *vars)
{
	static int	i;
	static int	pos;
	int			x;
	int			y;

	i++;
	while (find_k(vars, pos) != -1 && vars->game_stat == 1)
	{
		pos = find_k(vars, pos);
		x = pos % (vars->mem->cols + 1);
		y = pos / (vars->mem->cols + 1);
		if (i == CHANGE_ENEM)
			put_fire(vars, FIRE_UP, x, y);
		else if (i == 2 * CHANGE_ENEM)
			put_fire(vars, FIRE_DOWN, x, y);
		pos++;
	}
	if (i == 2 * CHANGE_ENEM)
		i = 0;
	pos = 0;
}
