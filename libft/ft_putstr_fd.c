/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:11:19 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/20 15:11:36 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned long	len;
	unsigned long	counter;

	if (!s)
		return ;
	len = ft_strlen(s);
	counter = 0;
	while (counter < len)
	{
		ft_putchar_fd(s[counter], fd);
		counter++;
	}
}
