/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:07:25 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/19 15:58:55 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(twll **lst)
{
	int	size;
	int	tmp;
	
	size = ft_lstsize(*lst);
	if (size <= 1)
		return;
	tmp = (*lst) -> data;
	(*lst) -> data = (*lst) -> next ->data;
	(*lst) -> next -> data = tmp;
}