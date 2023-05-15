/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:02:55 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 13:14:34 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_a(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*bottom;
	t_stack	*before_bottom;

	bottom = get_bottom(*lst);
	before_bottom = get_before_bottom(*lst);
	tmp = *lst;
	*lst = bottom;
	(*lst)-> next = tmp;
	before_bottom -> next = NULL;
	write(1, "rra\n", 4);
}

void	reverse_b(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*bottom;
	t_stack	*before_bottom;

	bottom = get_bottom(*lst);
	before_bottom = get_before_bottom(*lst);
	tmp = *lst;
	*lst = bottom;
	(*lst)-> next = tmp;
	before_bottom -> next = NULL;
	write(1, "rrb\n", 4);
}

void	reverse_both(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*bottom;
	t_stack	*before_bottom;

	bottom = get_bottom(*a);
	before_bottom = get_before_bottom(*a);
	tmp = *a;
	*a = bottom;
	(*a)-> next = tmp;
	before_bottom -> next = NULL;
	bottom = get_bottom(*b);
	before_bottom = get_before_bottom(*b);
	tmp = *b;
	*b = bottom;
	(*b)-> next = tmp;
	before_bottom -> next = NULL;
	write(1, "rrr\n", 4);
}
