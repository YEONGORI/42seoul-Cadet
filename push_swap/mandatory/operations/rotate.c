/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:03:36 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/29 17:11:55 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*bottom;

	tmp = *lst;
	*lst = (*lst)-> next;
	bottom = get_bottom(*lst);
	tmp -> next = NULL;
	bottom -> next = tmp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*bottom;

	tmp = *lst;
	*lst = (*lst)-> next;
	bottom = get_bottom(*lst);
	tmp -> next = NULL;
	bottom -> next = tmp;
	write(1, "rb\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*bottom;

	tmp = *a;
	*a = (*a)-> next;
	bottom = get_bottom(*a);
	tmp -> next = NULL;
	bottom -> next = tmp;
	tmp = *b;
	*b = (*b)-> next;
	bottom = get_bottom(*b);
	tmp -> next = NULL;
	bottom -> next = tmp;
	write(1, "rr\n", 3);
}
