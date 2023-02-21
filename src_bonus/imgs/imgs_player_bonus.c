/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:51:43 by arebelo           #+#    #+#             */
/*   Updated: 2022/04/25 16:50:09 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

_Bool	img_player_right(t_vars *vars)
{
	vars->img_stock[4].img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"img/player-right.xpm", &vars->img_stock[4].width,
			&vars->img_stock[4].height);
	if (!vars->img_stock[4].img_ptr)
		return (0);
	vars->img_stock[4].img_data = (int *)mlx_get_data_addr(
			vars->img_stock[4].img_ptr, &vars->img_stock[4].bits_per_pixel,
			&vars->img_stock[4].line_length, &vars->img_stock[4].endian);
	if (!vars->img_stock[4].img_data)
		return (0);
	return (1);
}

_Bool	img_player_left(t_vars *vars)
{
	vars->img_stock[5].img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"img/player-left.xpm", &vars->img_stock[5].width,
			&vars->img_stock[5].height);
	if (!vars->img_stock[5].img_ptr)
		return (0);
	vars->img_stock[5].img_data = (int *)mlx_get_data_addr(
			vars->img_stock[5].img_ptr, &vars->img_stock[5].bits_per_pixel,
			&vars->img_stock[5].line_length, &vars->img_stock[5].endian);
	if (!vars->img_stock[5].img_data)
		return (0);
	return (1);
}

_Bool	img_player_up(t_vars *vars)
{
	vars->img_stock[6].img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"img/player-up.xpm", &vars->img_stock[6].width,
			&vars->img_stock[6].height);
	if (!vars->img_stock[6].img_ptr)
		return (0);
	vars->img_stock[6].img_data = (int *)mlx_get_data_addr(
			vars->img_stock[6].img_ptr, &vars->img_stock[6].bits_per_pixel,
			&vars->img_stock[6].line_length, &vars->img_stock[6].endian);
	if (!vars->img_stock[6].img_data)
		return (0);
	return (1);
}

_Bool	img_player_down(t_vars *vars)
{
	vars->img_stock[7].img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"img/player-down.xpm", &vars->img_stock[7].width,
			&vars->img_stock[7].height);
	if (!vars->img_stock[7].img_ptr)
		return (0);
	vars->img_stock[7].img_data = (int *)mlx_get_data_addr(
			vars->img_stock[7].img_ptr, &vars->img_stock[7].bits_per_pixel,
			&vars->img_stock[7].line_length, &vars->img_stock[7].endian);
	if (!vars->img_stock[7].img_data)
		return (0);
	return (1);
}
