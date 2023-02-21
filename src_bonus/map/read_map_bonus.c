/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:12:52 by arebelo           #+#    #+#             */
/*   Updated: 2022/04/25 15:14:06 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	free_temp(char *temp)
{
	if (temp)
		free(temp);
}

static _Bool	read_eval(char **nl, int fd, t_stru *mem, char **temp)
{
	*temp = get_next_line(fd);
	if (*temp)
	{
		if (!line_middle(*temp, mem))
			return (0);
		*nl = ft_strjoin_2(*nl, *temp);
	}
	return (1);
}

static _Bool	matrix_first(char **nl, int fd, t_stru *mem)
{
	*nl = get_next_line(fd);
	if (!*nl || !line_one(*nl, mem))
		return (0);
	return (1);
}

static _Bool	matrix_following(char **nl, int fd, t_stru *mem)
{
	char	*temp;

	temp = NULL;
	if (!read_eval(nl, fd, mem, &temp))
	{
		free_temp(temp);
		return (0);
	}
	while (temp)
	{
		free(temp);
		if (!read_eval(nl, fd, mem, &temp))
		{
			free_temp(temp);
			return (0);
		}
	}
	free(temp);
	if (!line_last(&nl[0][(mem->rows - 1) * (mem->cols + 1)], mem))
		return (0);
	return (1);
}

_Bool	fill_array(char *argv, char **nl, t_stru *mem)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!matrix_first(nl, fd, mem))
	{
		close(fd);
		return (0);
	}
	if (!matrix_following(nl, fd, mem))
	{
		close(fd);
		return (0);
	}
	if (close(fd) < 0)
		return (0);
	return (1);
}
