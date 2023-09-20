#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*todelete;

	if (!lst)
		return ;
	while (*lst)
	{
		todelete = (*lst);
		*lst = (*lst)->next;
		ft_lstdelone(todelete, del);
	}
}
