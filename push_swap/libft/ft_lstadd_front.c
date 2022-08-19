/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:42:26 by yeongele          #+#    #+#             */
/*   Updated: 2022/08/19 15:54:42 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(twll **a, twll *new)
{
	if (!new)
		return ;
	else if (!a)
		a = &new;
	else if (!(*a))
		*a = new;
	else
	{
		new -> next = *a;
		(*a) -> prev = new;
		*a = new;
	}
}
