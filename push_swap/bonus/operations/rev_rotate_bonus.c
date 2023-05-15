/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:02:55 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 13:12:51 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	reverse_a(t_stack **lst)
{
	int		size;
	t_stack	*tmp;
	t_stack	*bottom;
	t_stack	*before_bottom;

	size = get_size(lst);
	if (size <= 1 || lst == NULL)
		return ;
	bottom = get_bottom(*lst);
	before_bottom = get_before_bottom(*lst);
	tmp = *lst;
	*lst = bottom;
	(*lst)-> next = tmp;
	before_bottom -> next = NULL;
}

void	reverse_b(t_stack **lst)
{
	int		size;
	t_stack	*tmp;
	t_stack	*bottom;
	t_stack	*before_bottom;

	size = get_size(lst);
	if (size <= 1 || lst == NULL)
		return ;
	bottom = get_bottom(*lst);
	before_bottom = get_before_bottom(*lst);
	tmp = *lst;
	*lst = bottom;
	(*lst)-> next = tmp;
	before_bottom -> next = NULL;
}

void	reverse_both(t_stack **a, t_stack **b)
{
	reverse_a(a);
	reverse_b(b);
}
