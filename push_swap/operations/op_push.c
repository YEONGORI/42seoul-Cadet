/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:58:37 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/19 16:16:51 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(twll **push_ll, twll **pop_ll)
{
	twll	*tmp;

	tmp = (*pop_ll) -> next;
	ft_lstadd_front(push_ll, ft_lstnew((*pop_ll) -> data));
	ft_lstdelone(*pop_ll); // 여기서 모든 리스트가 지워지진 않을지 의심됨
	*pop_ll = tmp;
	(*pop_ll) -> prev = NULL;
} 