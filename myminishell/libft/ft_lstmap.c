/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:02:47 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/14 14:56:39 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cur;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		cur = ft_lstnew(f(lst -> content));
		if (!cur)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new, cur);
		lst = lst -> next;
	}
	return (new);
}
