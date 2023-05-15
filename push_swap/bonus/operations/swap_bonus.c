/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:05:16 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 10:20:00 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	swap_a(t_stack **lst)
{
	int	size;
	int	tmp;

	size = get_size(lst);
	if (size <= 1 || lst == NULL)
		return ;
	tmp = (*lst)-> data;
	(*lst)-> data = (*lst)-> next ->data;
	(*lst)-> next -> data = tmp;
	tmp = (*lst)-> index;
	(*lst)-> index = (*lst)-> next -> index;
	(*lst)-> next -> index = tmp;
}

void	swap_b(t_stack **lst)
{
	int	size;
	int	tmp;

	size = get_size(lst);
	if (size <= 1 || lst == NULL)
		return ;
	tmp = (*lst)-> data;
	(*lst)-> data = (*lst)-> next ->data;
	(*lst)-> next -> data = tmp;
	tmp = (*lst)-> index;
	(*lst)-> index = (*lst)-> next -> index;
	(*lst)-> next -> index = tmp;
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
}
