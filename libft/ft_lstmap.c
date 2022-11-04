
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
			return (ft_lstclear(&new, del), NULL);
		ft_lstlast(new)->next = tmp;
	}
	return (new);
}
