/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:07:18 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/19 16:49:33 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(twll **lst)
{
	twll	*tmp;
	twll	**new;

	tmp = *lst;
	while (tmp -> next)
	{
		ft_lstadd_front(new, ft_lstnew(tmp -> data));
		tmp = tmp -> next;
	}
}