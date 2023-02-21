/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:59:41 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/20 14:59:45 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*ptr;
	unsigned long	counter;

	counter = 0;
	ptr = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
	{
		errno = ENOMEM;
		return (0);
	}
	while (counter <= ft_strlen(s1))
	{
		ptr[counter] = s1[counter];
		counter++;
	}
	return (ptr);
}
