/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:49:16 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 23:41:45 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	red_cross(t_vars *vars)
{
	exit_clean(vars);
	exit(1);
	return (0);
}

int	exit_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit_clean(vars);
		exit(1);
	}
	return (0);
}
