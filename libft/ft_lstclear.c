/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:34:41 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/20 15:52:37 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = NULL;
	if (lst)
	{
		if (*lst)
		{
			temp = *lst;
			while (*lst)
			{
				*lst = (*lst)->next;
				ft_lstdelone(temp, del);
				temp = *lst;
			}
		}
		lst = NULL;
	}
}
