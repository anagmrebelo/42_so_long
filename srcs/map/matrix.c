/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:16:47 by arebelo           #+#    #+#             */
/*   Updated: 2022/04/25 15:48:56 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

_Bool	line_one(char *nl, t_stru *mem)
{
	size_t	i;

	i = 0;
	if (!nl)
	{
		printf("Error\nMap is empty\n");
		return (0);
	}
	while (i < ft_strlen(nl))
	{
		if (nl[i] != '1' && nl[i] != '\n')
		{
			printf("Error\nMap must be surrounded by walls\n");
			return (0);
		}
		i++;
	}
	if (nl[i - 1] == '1')
		mem->cols = i;
	else
		mem->cols = i - 1;
	mem->rows++;
	return (1);
}

static int	pos_finder(char *nl)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(nl))
	{
		if (nl[i] != '1' && nl[i] != '\n')
		{
			printf("Error\nMap must be surrounded by walls\n");
			return (0);
		}
		i++;
	}
	return (i);
}

_Bool	line_last(char *nl, t_stru *mem)
{
	size_t	i;

	i = pos_finder(nl);
	if (!i)
		return (0);
	if ((nl[i - 1] == '1' && i != mem->cols) || (i - 1) != mem->cols)
	{
		printf("Error\nMap must be rectangular\n");
		return (0);
	}
	if (mem->exit < 1 || mem->collectible < 1 || mem->sp < 1)
	{
		printf("Error\nMap must contain at least one exit,");
		printf(" one collectible and one starting position\n");
		return (0);
	}
	if (mem->sp > 1)
	{
		printf("Error\nMap must only contain one starting position\n");
		return (0);
	}
	return (1);
}

static _Bool	eval_format(char c, t_stru *mem)
{
	if (c == 'C')
		mem->collectible++;
	else if (c == 'E')
		mem->exit++;
	else if (c == 'P')
		mem->sp++;
	else if (c != '0' && c != '1' && c != '\n')
	{
		printf("Error\nInvalid map symbol on line %zu\n", mem->rows);
		return (0);
	}
	return (1);
}

_Bool	line_middle(char *nl, t_stru *mem)
{
	size_t	i;

	i = 0;
	mem->rows++;
	while (i < ft_strlen(nl))
	{
		if (!eval_format(nl[i], mem))
			return (0);
		i++;
	}
	if ((nl[0] != '1') || (nl[i - 1] != '1' && nl[i - 2] != '1'))
	{
		printf("Error\nMap must be surrounded by walls\n");
		return (0);
	}
	if ((nl[i - 1] == '1' && i != mem->cols) || (i - 1) != mem->cols)
	{
		printf("Error\nMap must be rectangular\n");
		return (0);
	}
	return (1);
}
