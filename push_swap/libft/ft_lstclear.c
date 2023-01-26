/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:54:29 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/26 17:06:45 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstclear(s_stack	**lst)
{
	s_stack	*cur;
	s_stack	*nxt;

	if (!lst)
		return (0);
	cur = *lst;
	while (cur)
	{
		nxt = cur -> next;
		ft_lstdelone(cur);
		cur = nxt;
	}
	*lst = NULL;
	return (1);
}
