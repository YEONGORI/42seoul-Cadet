/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:42:26 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/26 15:06:30 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(s_stack **a, s_stack *new)
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
