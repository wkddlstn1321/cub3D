/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:08:55 by jeoan             #+#    #+#             */
/*   Updated: 2021/11/29 17:30:48 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
