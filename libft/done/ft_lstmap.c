#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*resultList;
	t_list	*mappedNode;

	if (!f || !lst)
		return (NULL);

	resultList = NULL;

	while (lst)
	{
		mappedNode = ft_lstnew(f(lst->content));
		if (!mappedNode)
		{
			ft_lstclear(&resultList, del);
			return (NULL);
		}
		ft_lstadd_back(&resultList, mappedNode);
		lst = lst->next;
	}

	return (resultList);
}
