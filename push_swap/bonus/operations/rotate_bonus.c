/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:03:36 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 10:31:19 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rotate_a(t_stack **lst)
{
	int		size;
	t_stack	*tmp;
	t_stack	*bottom;

	size = get_size(lst);
	if (size <= 1 || lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)-> next;
	bottom = get_bottom(*lst);
	tmp -> next = NULL;
	bottom -> next = tmp;
}

void	rotate_b(t_stack **lst)
{
	int		size;
	t_stack	*tmp;
	t_stack	*bottom;

	size = get_size(lst);
	if (size <= 1 || lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)-> next;
	bottom = get_bottom(*lst);
	tmp -> next = NULL;
	bottom -> next = tmp;
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate_a(a);
	rotate_b(b);
}
