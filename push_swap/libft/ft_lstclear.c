/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:54:29 by yeongele          #+#    #+#             */
/*   Updated: 2022/08/19 16:15:16 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstclear(twll	**lst)
{
	twll	*cur;
	twll	*nxt;

	if (!lst)
		return ;
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
