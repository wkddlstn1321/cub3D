
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	f(lst->content);
	if (lst->next)
		ft_lstiter(lst->next, f);
}
