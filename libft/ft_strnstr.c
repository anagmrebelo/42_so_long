/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:58:46 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/20 14:58:59 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;

	counter = 0;
	if (!needle[0])
		return ((char *)haystack);
	else if (len == 0)
		return (0);
	else
	{
		while (haystack[counter] && counter < (len - ft_strlen(needle) + 1))
		{
			if (ft_strncmp(&haystack[counter], needle, ft_strlen(needle)) == 0)
				return (&((char *)haystack)[counter]);
			counter++;
		}
	}
	return (0);
}
