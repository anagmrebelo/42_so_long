/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:04:06 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/16 18:18:01 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	exit_clean(t_vars *vars)
{
	if (vars->mem)
		free(vars->mem);
	if (vars->imgs_created)
		free(vars->img_stock);
	if (vars->nl)
		free(vars->nl);
}

static _Bool	game_start(t_vars *vars)
{
	vars->moves = 0;
	vars->game_stat = 1;
	vars->pid = getpid();
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
	{
		exit_clean(vars);
		return (0);
	}
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, 32 * vars->mem->cols,
			32 * (vars->mem->rows + 1), "So_Long - Catch the potions");
	if (!vars->win_ptr || !print_initial_img(vars, *vars->mem))
	{
		exit_clean(vars);
		return (0);
	}
	return (1);
}

void	check_file_extension(char *file_name, t_vars *vars)
{
	int	i;

	i = ft_strlen(file_name) - 4;
	if (i <= 0)
	{
		printf("Insert a valid ber file.\n");
		exit_clean(vars);
		exit(0);
	}
	if (ft_strncmp(&file_name[i], ".ber", 4) != 0)
	{
		printf("Insert a valid ber file.\n");
		exit_clean(vars);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Please insert one and only one ber file.\n");
		return (1);
	}
	check_file_extension(argv[1], &vars);
	vars.mem = (t_stru *)ft_calloc(1, sizeof(t_stru));
	if (!vars.mem)
		return (1);
	if (!fill_array(argv[1], &vars.nl, vars.mem))
	{
		exit_clean(&vars);
		return (1);
	}
	if (!game_start(&vars))
		return (1);
	mlx_key_hook(vars.win_ptr, key_hook, &vars);
	mlx_loop_hook(vars.mlx_ptr, &inactive, &vars);
	mlx_hook(vars.win_ptr, 17, 0, &red_cross, &vars);
	mlx_loop(vars.mlx_ptr);
	exit_clean(&vars);
	return (0);
}
