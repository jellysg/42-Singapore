/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:19:34 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/21 10:19:35 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_list;
	t_list	*mapped_node;

	if (!f || !lst)
		return (NULL);
	result_list = NULL;
	while (lst)
	{
		mapped_node = ft_lstnew(f(lst->content));
		if (!mapped_node)
		{
			if (del)
				ft_lstdelone(mapped_node->content, del);
			ft_lstclear(&result_list, del);
			return (NULL);
		}
		ft_lstadd_back(&result_list, mapped_node);
		lst = lst->next;
	}
	return (result_list);
}
