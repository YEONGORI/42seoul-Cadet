/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:42:26 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 10:13:30 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_lstadd_front(t_stack **a, t_stack *new)
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
		(*a)-> prev = new;
		*a = new;
	}
}
