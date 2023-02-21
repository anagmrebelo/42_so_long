/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:06:06 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/20 15:16:29 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	counter;
	unsigned int	len;

	if (!s)
		return ;
	counter = 0;
	len = ft_strlen(s);
	while (counter < len)
	{
		f(counter, &s[counter]);
		counter++;
	}
}
