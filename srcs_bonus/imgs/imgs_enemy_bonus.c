/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:51:43 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 23:41:45 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

_Bool	img_fire_up(t_vars *vars)
{
	vars->img_stock[8].img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"img/fire1.xpm", &vars->img_stock[8].width,
			&vars->img_stock[8].height);
	if (!vars->img_stock[8].img_ptr)
		return (0);
	vars->img_stock[8].img_data = (int *)mlx_get_data_addr(
			vars->img_stock[8].img_ptr, &vars->img_stock[8].bits_per_pixel,
			&vars->img_stock[8].line_length, &vars->img_stock[8].endian);
	if (!vars->img_stock[8].img_data)
		return (0);
	return (1);
}

_Bool	img_fire_down(t_vars *vars)
{
	vars->img_stock[9].img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"img/fire2.xpm", &vars->img_stock[9].width,
			&vars->img_stock[9].height);
	if (!vars->img_stock[9].img_ptr)
		return (0);
	vars->img_stock[9].img_data = (int *)mlx_get_data_addr(
			vars->img_stock[9].img_ptr, &vars->img_stock[9].bits_per_pixel,
			&vars->img_stock[9].line_length, &vars->img_stock[9].endian);
	if (!vars->img_stock[9].img_data)
		return (0);
	return (1);
}
