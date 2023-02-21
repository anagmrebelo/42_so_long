/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:59:18 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 23:41:45 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	find_piece(char piece, char c, t_vars *vars)
{
	size_t	i;

	i = 0;
	while (vars->nl[i] != piece)
		i++;
	if (c == 'x')
		return (i % (vars->mem->cols + 1));
	else if (c == 'y')
		return (i / (vars->mem->cols + 1));
	else if (c == 'p')
		return (i);
	return (0);
}

int	find_k(t_vars *vars, int pos)
{
	while (vars->nl[pos])
	{
		if (vars->nl[pos] == 'K')
			return (pos);
		pos++;
	}
	return (-1);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	move_player(t_vars *vars, int x, int y, int pos)
{	
	char	*temp;

	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img_stock[pos].img_ptr, x, y);
	vars->moves++;
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img_stock[0].img_ptr, 85,
		vars->mem->rows * TILE_HEIGHT);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img_stock[0].img_ptr, 117,
		vars->mem->rows * TILE_HEIGHT);
	temp = ft_itoa(vars->moves);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 85,
		vars->mem->rows * TILE_HEIGHT + 16,
		create_trgb(255, 255, 255, 255), temp);
	free(temp);
}

void	put_background(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img_stock[0].img_ptr, x, y);
}
