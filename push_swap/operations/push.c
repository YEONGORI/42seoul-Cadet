/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:02:45 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/29 17:12:12 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b)-> next;
	(*b)-> next = *a;
	*a = *b;
	*b = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)-> next;
	(*a)-> next = *b;
	*b = *a;
	*a = tmp;
	write(1, "pb\n", 3);
}
