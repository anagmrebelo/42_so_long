/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:59:00 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/02 10:01:49 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

_Bool	init_imgs(t_vars *vars)
{
	vars->img_stock = (t_img *)ft_calloc(11, sizeof(t_img));
	vars->imgs_created = 1;
	if (!vars->img_stock)
		return (0);
	if (!img_background(vars))
		return (0);
	if (!img_wall(vars))
		return (0);
	if (!img_collectible(vars))
		return (0);
	if (!img_exit(vars))
		return (0);
	if (!img_player_right(vars))
		return (0);
	if (!img_player_left(vars))
		return (0);
	if (!img_player_down(vars))
		return (0);
	if (!img_player_up(vars))
		return (0);
	return (1);
}

static void	aux(size_t i, size_t j, int *pos, t_vars *vars)
{
	if (vars->nl[j * (vars->mem->cols + 1) + i] == '0')
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img_stock[0].img_ptr, pos[0], pos[1]);
	else if (vars->nl[j * (vars->mem->cols + 1) + i] == '1')
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img_stock[1].img_ptr, pos[0], pos[1]);
	else if (vars->nl[j * (vars->mem->cols + 1) + i] == 'C')
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img_stock[2].img_ptr, pos[0], pos[1]);
	else if (vars->nl[j * (vars->mem->cols + 1) + i] == 'E')
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img_stock[3].img_ptr, pos[0], pos[1]);
	else if (vars->nl[j * (vars->mem->cols + 1) + i] == 'P')
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img_stock[4].img_ptr, pos[0], pos[1]);
}

_Bool	print_initial_img(t_vars *vars, t_stru mem)
{
	size_t	i;
	size_t	j;
	int		pos[2];

	if (!init_imgs(vars))
		return (0);
	j = 0;
	pos[1] = 0;
	while (j < mem.rows)
	{
		i = 0;
		pos[0] = 0;
		while (i < mem.cols)
		{
			aux(i, j, pos, vars);
			i++;
			pos[0] += vars->img_stock[1].width;
		}
		pos[1] += vars->img_stock[1].height;
		j++;
	}
	return (1);
}
