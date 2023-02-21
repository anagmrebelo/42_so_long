/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_game_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:59:11 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 23:41:45 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_exit(t_vars *vars, int x, int y)
{
	if (vars->nl[(y / TILE_HEIGHT) * (vars->mem->cols + 1)
			+ (x / TILE_WIDTH)] == 'K')
		return (2);
	if (vars->nl[(y / TILE_HEIGHT) * (vars->mem->cols + 1)
			+ (x / TILE_WIDTH)] == 'E')
	{
		if (vars->mem->collectible == 0)
			return (1);
		return (2);
	}
	return (0);
}

void	terminate_game(t_vars *vars, int trgb, char *str)
{
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr,
		vars->mem->cols * TILE_WIDTH / 2,
		vars->mem->rows * TILE_HEIGHT / 2,
		trgb, str);
	vars->game_stat = 0;
}

void	eval_finish(t_vars *vars, int x, int y)
{
	if (is_exit(vars, x, y) == 1)
		terminate_game(vars, create_trgb(255, 0, 255, 0), "You won!");
	if (is_exit(vars, x, y) == 2)
		terminate_game(vars, create_trgb(255, 255, 0, 0), "You lost :(");
}
