/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:51:43 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/05 14:47:45 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

_Bool	img_background(t_vars *vars)
{
	vars->img_stock[0].img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"img/background.xpm", &vars->img_stock[0].width,
			&vars->img_stock[0].height);
	if (!vars->img_stock[0].img_ptr)
		return (0);
	vars->img_stock[0].img_data = (int *)mlx_get_data_addr(
			vars->img_stock[0].img_ptr, &vars->img_stock[0].bits_per_pixel,
			&vars->img_stock[0].line_length, &vars->img_stock[0].endian);
	if (!vars->img_stock[0].img_data)
		return (0);
	return (1);
}

_Bool	img_wall(t_vars *vars)
{
	vars->img_stock[1].img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"img/tree.xpm", &vars->img_stock[1].width,
			&vars->img_stock[1].height);
	if (!vars->img_stock[1].img_ptr)
		return (0);
	vars->img_stock[1].img_data = (int *)mlx_get_data_addr(
			vars->img_stock[1].img_ptr, &vars->img_stock[1].bits_per_pixel,
			&vars->img_stock[1].line_length, &vars->img_stock[1].endian);
	if (!vars->img_stock[1].img_data)
		return (0);
	return (1);
}

_Bool	img_collectible(t_vars *vars)
{
	vars->img_stock[2].img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"img/collectible.xpm", &vars->img_stock[2].width,
			&vars->img_stock[2].height);
	if (!vars->img_stock[2].img_ptr)
		return (0);
	vars->img_stock[2].img_data = (int *)mlx_get_data_addr(
			vars->img_stock[2].img_ptr, &vars->img_stock[2].bits_per_pixel,
			&vars->img_stock[2].line_length, &vars->img_stock[2].endian);
	if (!vars->img_stock[2].img_data)
		return (0);
	return (1);
}

_Bool	img_exit(t_vars *vars)
{
	vars->img_stock[3].img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"img/exit.xpm", &vars->img_stock[3].width,
			&vars->img_stock[3].height);
	if (!vars->img_stock[3].img_ptr)
		return (0);
	vars->img_stock[3].img_data = (int *)mlx_get_data_addr(
			vars->img_stock[3].img_ptr, &vars->img_stock[3].bits_per_pixel,
			&vars->img_stock[3].line_length, &vars->img_stock[3].endian);
	if (!vars->img_stock[3].img_data)
		return (0);
	return (1);
}
