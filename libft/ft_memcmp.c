/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:58:25 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/20 14:58:33 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned long n)
{
	unsigned long	counter;

	if (n == 0)
		return (0);
	counter = 0;
	while (((unsigned char *)s1)[counter] == ((unsigned char *)s2)[counter]
			&& counter < n - 1)
		counter ++;
	return (((unsigned char *)s1)[counter] - ((unsigned char *)s2)[counter]);
}
