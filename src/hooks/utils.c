/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:49:16 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/05 15:15:58 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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

void	put_background(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img_stock[0].img_ptr, x, y);
}

void	move_player(t_vars *vars, int x, int y, int pos)
{	
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img_stock[pos].img_ptr, x, y);
	vars->moves++;
	write(1, "Number of movements: ", 21);
	ft_putnbr_fd(vars->moves, 1);
	ft_putchar_fd('\n', 1);
}
