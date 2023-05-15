/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:54:29 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 10:13:33 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_lstclear(t_stack	**lst)
{
	t_stack	*cur;
	t_stack	*nxt;

	if (!lst)
		return (0);
	cur = *lst;
	while (cur)
	{
		nxt = cur -> next;
		free(cur);
		cur = nxt;
	}
	*lst = NULL;
	return (1);
}
