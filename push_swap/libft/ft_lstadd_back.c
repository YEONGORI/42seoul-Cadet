/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:19:34 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/26 15:06:34 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(s_stack **lst, s_stack *new)
{
	s_stack	*tmp;

	if (!new)
		return ;
	else if (!lst)
		lst = &new;
	else if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp -> next)
			tmp = tmp -> next;
		tmp -> next = new;
	}
}
