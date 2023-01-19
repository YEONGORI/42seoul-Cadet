/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:07:21 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/19 16:42:13 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(twll **lst)
{
	twll	*tmp;

	tmp = ft_lstnew((*lst) -> data);
	ft_lstadd_back(lst, tmp);
	tmp = (*lst) -> next;
	ft_lstdelone(*lst);
	*lst = tmp;
	(*lst) -> prev = NULL;
}
