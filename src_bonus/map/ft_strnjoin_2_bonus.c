/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:58:12 by arebelo           #+#    #+#             */
/*   Updated: 2022/04/25 15:58:14 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

char	*ft_strjoin_2(char *s1, char *s2)
{
	char			*ptr;
	unsigned long	counter;
	unsigned long	size;
	char			*temp;

	temp = ft_strndup(s1, ft_strlen(s1));
	free(s1);
	counter = 0;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(temp) + ft_strlen(s2);
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, temp, ft_strlen(temp));
	ft_memcpy(&ptr[ft_strlen(temp)], s2, ft_strlen(s2));
	ptr[size] = '\0';
	free(temp);
	return (ptr);
}
