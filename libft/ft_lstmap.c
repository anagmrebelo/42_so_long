/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:38:51 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/20 15:38:56 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*last;

	first = NULL;
	while (lst)
	{
		last = ft_lstnew((*f)(lst->content));
		if (!last)
		{
			ft_lstclear(&first, del);
			return (0);
		}
		ft_lstadd_back(&first, last);
		lst = lst->next;
	}
	return (first);
}
